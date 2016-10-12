#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "Light.hpp"
#include <vector>

struct Input_Data_Struct{
    int imageWidth;
    int imageHeight;
    Point eye;
    Color bkgcolor;
    Vector updir;
    Vector viewdir;
    int fovv;
    std::vector<Sphere> spheres;
    std::vector<Light> lights;
};

typedef struct Input_Data_Struct InputData;

#endif
