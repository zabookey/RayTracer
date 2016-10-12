#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Color.hpp"
#include "Point.hpp"

struct Sphere_Struct{
    Color color;
    Color speccolor;
    double ka, kd, ks;
    int powerN;
    Point center;
    double radius;
};
typedef struct Sphere_Struct Sphere;

#endif
