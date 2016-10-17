#ifndef FACE_HPP
#define FACE_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "Qppax.hpp"
#include "Vpmq.hpp"
#include "CrossProduct.hpp"

class Face{
    public:
        Point p0;
        Point p1;
        Point p2;
        Face();
        Face(Point p0_, Point p_1, Point p_2);
        double collision(Ray r);
        Vector normVector(Point* collision); // Use a pointer to allow passing null.
};

#endif
