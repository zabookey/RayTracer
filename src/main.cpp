#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "InputData.hpp"
#include "InputReader.hpp"
#include "Normalize.hpp"
#include "CrossProduct.hpp"
#include "Qppax.hpp"
#include "Vpmq.hpp"
#include "Ray.hpp"
#include "SphereCollision.hpp"
#include "ValidityChecker.hpp"
#include "Phong.hpp"

#include <iostream>
#include <cmath>
#include <float.h>

#define PI 3.14159265

using namespace std;

int main(int argc, char** argv){
#ifndef TEST_ENV
    char * inputfilename;
    if(argc < 2){
        cout << "Usage Error... " <<endl;
        cout << "Correct Usage: <./Executable> <input file>" <<endl;
        return 1;
    } else {
        inputfilename = argv[1];
    }
    InputData inputdata;
    int ierr = readInputFile(inputfilename, inputdata);
    if(ierr != 0){
        if(ierr == -1)
            cout << "Error: Input file doesn't contain all necessary fields" << endl;
        else if(ierr == -2)
            cout << "Error: Input file (" << inputfilename << ")  was not able to be opened" << endl;
        else 
            cout << "Error reading input file at line " << ierr << endl;
        return 1;
    }
    bool valid = checkValidity(inputdata);
    if(!valid)
        return 1;
    // Extract the data from inputdata
    int imageWidth = inputdata.imageWidth;
    int imageHeight = inputdata.imageHeight;
    Vector updir = inputdata.updir;
    Vector viewdir = inputdata.viewdir;
    Point eye = inputdata.eye;
    int fovv = inputdata.fovv;
    vector<Object*> objects = inputdata.objects;
    Color bkgcolor = inputdata.bkgcolor;
    // Create the array to store the colors
    Color ** pixelMap = new Color*[imageWidth];
    for(int i = 0; i < imageWidth; i++)
        pixelMap[i] = new Color[imageHeight];
    // Calculate u given updir and viewdir;
    Vector u;
    crossProduct(u, viewdir, updir);
    normalize(u);
    // Calculate v given viewdir and u
    Vector v;
    crossProduct(v, u, viewdir);
    normalize(v);
    // Arbitrary distance value d
    double d = 5.0;
    // Calculate the height, width, aspect ratio, and normalized view direction
    double h = 2*d*tan(fovv*PI/2/180);
    double aspect = ((double) imageWidth)/imageHeight;
    double w = h*aspect;
    Vector normalView;
    copyVector(viewdir, normalView);
    normalize(normalView);
    // Calculate Upper left point    
    Point ul;
    qppax(ul, eye, d, normalView); // ul = eye + d*||view||
    qppax(ul, ul, h/2, v); // ul = ul + h/2 * v
    qppax(ul, ul, -w/2, u); // ul = ul - w/2 * u
    // Calculate Upper right point
    Point ur;
    qppax(ur, eye, d, normalView); // ur = eye + d*||view||
    qppax(ur, ur, h/2, v); // ur = ur + h/2 * v
    qppax(ur, ur, w/2, u); // ur = ur + w/2 * u
    // Calculate Lower left point
    Point ll;
    qppax(ll, eye, d, normalView); // ll = eye + d*||view||
    qppax(ll, ll, -h/2, v); // ll = ll - h/2 * v
    qppax(ll, ll, -w/2, u); // ll = ll - w/2 * u
    // Calculate lower right point
    Point lr;
    qppax(lr, eye, d, normalView); // lr = eye + d*||view||
    qppax(lr, lr, -h/2, v); // lr = lr - h/2 * v
    qppax(lr, lr, w/2, u); // lr = lr + w/2 * u
    // Calculate offest vectors deltaH and deltaV
    Vector deltaH;
    vpmq(deltaH, ur, ul);
    scaleVector(deltaH, 1.0/(imageWidth-1));
    Vector deltaV;
    vpmq(deltaV, ll, ul);
    scaleVector(deltaV, 1.0/(imageHeight-1));
    // For each pixel in the map determine which color it should be
    for(int pixelX = 0; pixelX < imageWidth; pixelX++){
        for(int pixelY = 0; pixelY < imageHeight; pixelY++){
            // Calculate the target point for this pixel
            Point target;
            qppax(target, ul, pixelX, deltaH);
            qppax(target, target, pixelY, deltaV);
            // Create the ray from eye to target
            Ray r;
            initRay(r, eye, target);
            // Witchcraft to determine if the ray hits a object
            // Use pointer to determine which object is the current closest
            Object * nearest = 0;
            double nearestDist = DBL_MAX;
            // Cycle through the objects and determine the collision
            // Determine how far the ray travels for the collision
            for(int i = 0; i < objects.size(); i++){
                double t = objects[i]->collision(r);
                //double t = sphereCollision(r, objects[i]);
                if(t >= 0){
                    // If this t is closer than the previous t
                    // change the nearestDist and and point to this object
                    if(t < nearestDist){
                        nearestDist = t;
                        nearest = objects[i];
                    }
                }
            }
            // Check if a object was hit. If so color it with object color
            // If not color pixel with bkgcolor
            if(nearestDist != DBL_MAX){
                Point intersection;
                qppax(intersection, r.origin, nearestDist, r.direction);
                Color c = phong(intersection, nearest, inputdata.lights, objects, r.direction, 50);
                if(c.red < 0 || c.blue < 0 || c.green < 0){
                    cout << "NEGATIVE COLOR VALUE AT [" << pixelX << "][" << pixelY << "]" << endl;
                }
                copyColor(c, pixelMap[pixelX][pixelY]);
                //copyColor(nearest->color, pixelMap[pixelX][pixelY]);
            }
            else
                copyColor(bkgcolor, pixelMap[pixelX][pixelY]);
        }
    }
// If VERBOSE is defined in the CMake file then print out a bunch of computed information.
#ifdef VERBOSE
    cout << "Image Width:  " << inputdata.imageWidth << endl;
    cout << "Image Height: " << inputdata.imageHeight << endl;
    cout << "Fovv: " << inputdata.fovv << endl;
    cout << "Eye: (" << inputdata.eye.x << " " << inputdata.eye.y << " " << inputdata.eye.z << ")" << endl;
    cout << "BKG Color: (" << inputdata.bkgcolor.red << " " << inputdata.bkgcolor.green << " " << inputdata.bkgcolor.blue << ")" << endl;
    cout << "Up direction: (" << inputdata.updir.dx << " " << inputdata.updir.dy << " " << inputdata.updir.dz << ")" << endl;
    cout << "View direction: (" << inputdata.viewdir.dx << " " << inputdata.viewdir.dy << " " << inputdata.viewdir.dz << ")" << endl;
    cout << "Number of Spheres: " << inputdata.spheres.size() << endl;
    for(int i = 0; i < inputdata.spheres.size(); i++){
        cout << "Sphere " << i << ":" << endl;
        cout << "    " << "Color: (" << inputdata.spheres[i].color.red << " " << inputdata.spheres[i].color.green << " " << inputdata.spheres[i].color.blue << ")" << endl;
        cout << "    " << "Specular Color: (" << inputdata.spheres[i].speccolor.red << " " << inputdata.spheres[i].speccolor.green << " " << inputdata.spheres[i].speccolor.blue << ")" << endl;
        cout << "    " << "K Ambient:  " << inputdata.spheres[i].ka << endl;
        cout << "    " << "K Diffuse:  " << inputdata.spheres[i].kd << endl;
        cout << "    " << "K Specular: " << inputdata.spheres[i].ks << endl;
        cout << "    " << "N Power:    " << inputdata.spheres[i].powerN << endl;
        cout << "    " << "Loc: (" << inputdata.spheres[i].center.x << " " << inputdata.spheres[i].center.y << " " << inputdata.spheres[i].center.z << ")" << endl;
        cout << "    " << "Radius: " << inputdata.spheres[i].radius << endl;
    }
    cout << "Number of Lights: " << inputdata.lights.size() << endl;
    for(int i = 0; i < inputdata.lights.size(); i++){
        cout << "Light " << i << ":" << endl;
        Light light = inputdata.lights[i];
        if(light.w == 1){
            cout << "    " << "Point Source" << endl;
            cout << "    " << "Location:  ";
        }
        else{
            cout << "    " << "Directional Source" << endl;
            cout << "    " << "Direction: ";
        }
        cout << "(" << light.x << " " << light.y << " " << light.z << ")" << endl;
        cout << "    " << "Color: (" << light.color.red << " " << light.color.green << " " << light.color.blue << ")" << endl;
    }
    cout << "U Vector: (" << u.dx << " " << u.dy << " " << u.dz << ")" << endl;
    cout << "V Vector: (" << v.dx << " " << v.dy << " " << v.dz << ")" << endl;
    cout << "Height of viewing window: " << h << endl;
    cout << "Width  of viewing window: " << w << endl;
    cout << "Aspect: " << aspect << endl;
    cout << "Upper Left:  (" << ul.x << " " << ul.y << " " << ul.z << ")" << endl;
    cout << "Upper Right: (" << ur.x << " " << ur.y << " " << ur.z << ")" << endl;
    cout << "Lower Left:  (" << ll.x << " " << ll.y << " " << ll.z << ")" << endl;
    cout << "Lower Right: (" << lr.x << " " << lr.y << " " << lr.z << ")" << endl;
    
    cout << "Delta H: (" << deltaH.dx << " " << deltaH.dy << " " << deltaH.dz << ")" << endl;
    cout << "Delta V: (" << deltaV.dx << " " << deltaV.dy << " " << deltaV.dz << ")" << endl;
#endif
    // Write to an output file!
    string outputfilename(inputfilename);
    size_t pos = outputfilename.find(".");
    if(pos != string::npos){
        outputfilename.erase(pos, outputfilename.length());
    }
    outputfilename.append(".ppm");
    ofstream outputFile;
    outputFile.open(outputfilename);
    outputFile << "P3\n";
    outputFile << imageWidth << " " << imageHeight << "\n";
    outputFile << 255 << "\n";
    for(int i = 0; i < imageHeight; i++){
        for(int j = 0; j < imageWidth; j++){
            Color color = pixelMap[j][i];
            outputFile << static_cast <int> (floor(color.red * 255)) << " ";
            outputFile << static_cast <int> (floor(color.green * 255)) << " ";
            outputFile << static_cast <int> (floor(color.blue * 255)) << "\n";
        }
    }
    outputFile.close();

    // Clean up the allocated arrays
    for(int i = 0; i < imageWidth; i++)
        delete(pixelMap[i]);
    delete(pixelMap);
    for(int i = 0; i < objects.size(); i++)
        delete(objects[i]);

#else
    cout << "TEST ENV VARIABLE" << endl;
    Face f(Point(1, 1, 0), Point(0, 1, 1), Point(1, 0, 1));
    Vector normalV = f.normVector(NULL);
    cout << "NormalVector: (" << normalV.dx << " " << normalV.dy << " " << normalV.dz << ")" << endl;
    Ray r;
    initRay(r, Point(0, 0, 0), Point(-1.0/3, -2.0/3, -2.0/3));
    cout << "Ray Collision with Face at t = " << f.collision(r) << endl;
#endif
}
