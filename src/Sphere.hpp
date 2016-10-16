#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Color.hpp"
#include "Point.hpp"

class Sphere{
    public:
        Color color;
        Color speccolor;
        double ka, kd, ks;
        int powerN;
        Point center;
        double radius;
};

#endif
