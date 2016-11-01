#include "Phong.hpp"
#include "RayPayload.hpp"
#include "Qppax.hpp"

#include <iostream>

/* Uses the phong illumination model to determine what color the pixel
 * should be where a ray intersects a object.
 * Input:
 *     intersection -> The point in 3D space where the ray intersected the object
 *     object -> The object that the ray intersected
 *     lights -> A vector of all the lights in the scene
 *     objects -> A vector of all the objects in the scene
 *     viewdir -> The direction of the ray that intersected the object
 *     npower -> DEPRECATED AND MOVED INSIDE SPHERE STRUCT
 * Output:
 *     Returns the color calculated by the phong model.
 */
Color phong(Point intersection, Object* object, vector<Light> lights,
        vector<Object*> objects, Vector viewdir, double rayrefrac, int n){
    double red, blue, green;
    double ka = object->ka;
    double kd = object->kd;
    double ks = object->ks;
    // Get the objects color. Not trivial if using textures
    Color objectcolor = object->getColor(intersection);
    Color specular = object->speccolor;
    //specular.red = 1; specular.blue = 1; specular.green = 1;
    red = ka*objectcolor.red;
    blue = ka*objectcolor.blue;
    green = ka*objectcolor.green;
    Vector V; // Initiate the vector pointing towards the veiwer
    copyVector(viewdir, V); // Copy V with the view direction. Assume V is already normalized...
    scaleVector(V, -1); // Reverse the direction of V
    // Get the normal vector from the intersection between this point
    // and the object
    Vector N = object->normVector(&intersection);
    for(int i = 0; i < lights.size(); i++){
//        Vector N; // The surface normal vector at the intersection point
//        vpmq(N, intersection, sphere.center); // N = intersection - sphere.center
//        scaleVector(N, 1/sphere.radius); // Normalize N by dividing sphere redius
        Vector L; // The vector pointed towards the light
        Light light = lights[i]; // The current light to be checked
        double distanceToLight = DBL_MAX; // Initiate the distance to the light as DBL_MAX
        if(light.w == 1){ //Positional light
            Point lightpoint; // Initiate the point where this light resides
            lightpoint.x = light.x;
            lightpoint.y = light.y;
            lightpoint.z = light.z;
            vpmq(L, lightpoint, intersection); // L = lightpoint - intersection
            distanceToLight = norm(L); // distanceToLight = ||L||
            scaleVector(L, 1/distanceToLight); // Normalize the L vector
//            normalize(L);
        } else { // Assume if not a positional light then a directional light
            L.dx = light.x;
            L.dy = light.y;
            L.dz = light.z;
            scaleVector(L, -1); // Reverse the direction to point to light
            normalize(L); // Normalize L vector
        }
        // Check to see if another object in the scene is blocking this light
        double shadowlessFlag = 1.0; // Assume that we aren't in a shadow
        for(int j = 0; j < objects.size(); j++){
            Ray r; // Initiate a Ray from the intersection in the direction of the light source
            r.origin = intersection;
            r.direction = L;
            double t = objects[j]->collision(r); // Check if and where this ray intersects this object
//            cout << "Intersection Point: (" << intersection.x << " " << intersection.y << " " << intersection.z << ")";
//            cout << "    Shadow T: " << t << endl;
            // If there is a collision set the shadowlessFlag to false
            if(t >= 1e-4 && t < distanceToLight){
                shadowlessFlag -= objects[j]->opac;
            }
        }
        Vector H; // Initialize the Halfway vector
        waxpby(H, 1.0, L, 1.0, V); // H = L + V
        normalize(H); // H = H / ||H||
        double NdotL = dotProduct(N, L); // Calculate <N, L>
        double NdotH = dotProduct(N, H); // Calculate <N, H>
        NdotH = pow(NdotH, object->powerN); // Caluclate <N, H>^powerN
        if(NdotL < 0) NdotL = 0; // make sure NdotL is >= 0.
        if(NdotH < 0) NdotH = 0; // make sure NdotH is >= 0.
        // If this point is not in the shadow of another object. Add this lights contribution to the phong model
        if(shadowlessFlag > 0){
            red += shadowlessFlag*(light.color.red*(kd*objectcolor.red*NdotL + ks*specular.red*NdotH));
            blue += shadowlessFlag*(light.color.blue*(kd*objectcolor.blue*NdotL + ks*specular.blue*NdotH));
            green += shadowlessFlag*(light.color.green*(kd*objectcolor.green*NdotL + ks*specular.green*NdotH));
        }
    }
    // Use a depth check to prevent infinite loops with reflection and refraction
    if(n > 0){
    // Reflection calculations:
    // Calculate the reflection ray reflect.
        // f0 should be the part of the object...
        double opac = object->opac;
        double refrac = object->refrac;
        double f0 = pow((refrac-rayrefrac)/(refrac+rayrefrac),2);
        Vector r;
        copyVector(N, r);
        double  a = dotProduct(N, V);
        double fr = f0 + (1-f0)*pow((1-a), 5);
//        if(a > 1 || a < 0){
//            std::cout << "ERROR" << endl;
//            std::cout << "a: " << a << endl;
//            std::cout << "N: (" << N.dx << " " << N.dy << " " << N.dz << ")" << endl;
//            std::cout << "V: (" << V.dx << " " << V.dy << " " << V.dz << ")" << endl;
//        } else {
        waxpby(r, 2*a, N, -1, V);
        normalize(r); // Just to be safe...
        Ray reflection(intersection, r);
        RayPayload rp = traceRay(reflection, objects);
        if(rp.nearestDist < DBL_MAX && rp.nearestDist > 1e-3){
            Point refcol;
            qppax(refcol, reflection.origin, rp.nearestDist, reflection.direction);
            Color reflectColor = phong(refcol, rp.nearest, lights, objects, r, rayrefrac, n-1);
            red += fr*reflectColor.red;
            green += fr*reflectColor.green;
            blue += fr*reflectColor.blue;
        }
//        }

        // Transparency Calculations:
        if(opac != 1){ // No point in even doing this if this is 1.
            Vector t;
            double alpha = -sqrt(1-pow((rayrefrac/refrac),2)*(1-pow(a,2)));
            double beta = (rayrefrac/refrac);
            Vector y;
            waxpby(y, a, N, -1, V);
            waxpby(t, alpha, N, beta, y);
            normalize(t); // Just to be safe...
            Ray transparent(intersection, t);
            RayPayload rp = traceRay(transparent, objects);
            if(rp.nearestDist < DBL_MAX && rp.nearestDist > 1e-3){
                Point transcol;
                qppax(transcol, transparent.origin, rp.nearestDist, transparent.direction);
                Color transColor = phong(transcol, rp.nearest, lights, objects, t, 1, n);
                double transScale = (1-fr)*(1-opac);
                red += transScale*transColor.red;
                green += transScale*transColor.green;
                blue += transScale*transColor.blue;
            }
        }
    }
    if(red > 1)
        red = 1;
    if(blue > 1)
        blue = 1;
    if(green > 1)
        green = 1;
//    if(red < 0)
//        red = 0;
//    if(blue < 0)
//        blue = 0;
//    if(green < 0)
//        green = 0;
    // Initiate finalColor and return it
    Color finalColor;
    finalColor.red = red;
    finalColor.blue = blue;
    finalColor.green = green;
    return finalColor;
}
