#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Object.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "Ray.hpp"

class Sphere{
    public:
        Color color;
        Color speccolor;
        double ka, kd, ks;
        int powerN;
        Point center;
        double radius;
        Sphere();
        double collision(Ray r);
        Vector normVector(Point* collision);
};

#endif
