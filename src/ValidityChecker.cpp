#include "ValidityChecker.hpp"

// Function that takes the filled in input data and makes sure that
// there are no illegal data entries
bool checkValidity(InputData data){
    // Check that image width and height are both greater than 0
    if(data.imageWidth <= 0 || data.imageHeight <= 0){
        cout << "Invalid parameters read from imsize variable tag" << endl;
        return false;
    }
    // Check that field of view is less than 180 degrees
    if(data.fovv >= 180 || data.fovv <= 0){
        cout << "Invalid parameters read from fovv variable tag" << endl;
        return false;
    }
    // Check to see if viewdir is a zero vector
    if(data.viewdir.dx == 0 && data.viewdir.dy == 0 && data.viewdir.dz == 0){
        cout << "Error: View directions is a zero vector" << endl;
        return false;
    }
    // Check to see if updir is a zero vector
    if(data.updir.dx == 0 && data.updir.dy == 0 && data.updir.dz == 0){
        cout << "Error: Up direction is a zero vector" << endl;
        return false;
    }
    // Check to see if updir and viewdir are parallel
    Vector nud;
    copyVector(data.updir, nud);
    normalize(nud);
    Vector nvd;
    copyVector(data.viewdir, nvd);
    normalize(nvd);
    if(nud.dx == nvd.dx && nud.dy == nvd.dy && nud.dz == nvd.dz){
        cout << "Error: Up direction and View direction are parallel" << endl;
        return false;
    }
    if(data.objects.size() == 0)
        cout << "Warning: Data valid but no spheres added to scene..." << endl;
    // Make sure that no directional lights have direction (0 0 0)
    bool invalidLight = false;
    for(int i = 0; i < data.lights.size(); i++){
        Light light = data.lights[i];
        if(light.w == 0){
            if(light.x == 0 && light.y == 0 && light.z == 0){
                cout << "Error: Light " << i << " is directional with 0 direction..." << endl;
                invalidLight = true;
            }
        }
    }
    if(invalidLight)
        return false;

    return true;
}
