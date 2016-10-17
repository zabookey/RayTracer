#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Object.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "Ray.hpp"

class Sphere: public Object{
    public:
        Point center;
        double radius;
        Sphere();
        double collision(Ray r);
        Vector normVector(Point* collision);
};

#endif
