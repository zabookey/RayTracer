#include "Phong.hpp"
#include <iostream>

/* Uses the phong illumination model to determine what color the pixel
 * should be where a ray intersects a sphere.
 * Input:
 *     intersection -> The point in 3D space where the ray intersected the sphere
 *     sphere -> The sphere that the ray intersected
 *     lights -> A vector of all the lights in the scene
 *     spheres -> A vector of all the spheres in the scene
 *     viewdir -> The direction of the ray that intersected the sphere
 *     npower -> DEPRECATED AND MOVED INSIDE SPHERE STRUCT
 * Output:
 *     Returns the color calculated by the phong model.
 */
Color phong(Point intersection, Sphere sphere, vector<Light> lights,
        vector<Sphere> spheres, Vector viewdir, int npower){
    double red, blue, green;
    double ka = sphere.ka;
    double kd = sphere.kd;
    double ks = sphere.ks;
    Color spherecolor = sphere.color;
    Color specular = sphere.speccolor;
    //specular.red = 1; specular.blue = 1; specular.green = 1;
    red = ka*spherecolor.red;
    blue = ka*spherecolor.blue;
    green = ka*spherecolor.green;
    for(int i = 0; i < lights.size(); i++){
        Vector N; // The surface normal vector at the intersection point
        vpmq(N, intersection, sphere.center); // N = intersection - sphere.center
        scaleVector(N, 1/sphere.radius); // Normalize N by dividing sphere redius
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
        bool shadowlessFlag = true; // Assume that we aren't in a shadow
        for(int j = 0; j < spheres.size(); j++){
            Ray r; // Initiate a Ray from the intersection in the direction of the light source
            r.origin = intersection;
            r.direction = L;
            double t = sphereCollision(r, spheres[j]); // Check if and where this ray intersects this sphere
            // If there is a collision set the shadowlessFlag to false
            if(t >= 0 && t < distanceToLight){
                shadowlessFlag = false;
            }
        }
        Vector V; // Initiate the vector pointing towards the veiwer
        copyVector(viewdir, V); // Copy V with the view direction
        scaleVector(V, -1); // Reverse the direction of V
        Vector H; // Initialize the Halfway vector
        waxpby(H, 1.0, L, 1.0, V); // H = L + V
        normalize(H); // H = H / ||H||
        double NdotL = dotProduct(N, L); // Calculate <N, L>
        double NdotH = dotProduct(N, H); // Calculate <N, H>
        NdotH = pow(NdotH, sphere.powerN); // Caluclate <N, H>^powerN
        if(NdotL < 0) NdotL = 0; // make sure NdotL is >= 0.
        if(NdotH < 0) NdotH = 0; // make sure NdotH is >= 0.
        // If this point is not in the shadow of another sphere. Add this lights contribution to the phong model
        if(shadowlessFlag){
            red += light.color.red*(kd*spherecolor.red*NdotL + ks*specular.red*NdotH);
            blue += light.color.blue*(kd*spherecolor.blue*NdotL + ks*specular.blue*NdotH);
            green += light.color.green*(kd*spherecolor.green*NdotL + ks*specular.green*NdotH);
        }
    }
    // Initiate finalColor and return it
    Color finalColor;
    finalColor.red = red;
    finalColor.blue = blue;
    finalColor.green = green;
    return finalColor;
}
