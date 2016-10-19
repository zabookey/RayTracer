#ifndef FACE_HPP
#define FACE_HPP

#include "Object.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "Qppax.hpp"
#include "Vpmq.hpp"
#include "CrossProduct.hpp"
#include "TextureVertex.hpp"

class Face: public Object{
    public:
        Point p0;
        Point p1;
        Point p2;
        bool smooth;
        Vector np0;
        Vector np1;
        Vector np2;
        TextureVertex tp0, tp1, tp2;
        Face();
        Face(Point p0_, Point p_1, Point p_2);
        double collision(Ray r);
        Vector normVector(Point* collision); // Use a pointer to allow passing null.
        Color getColor(Point p);
    private:
        void barycentricCord(Point p, double& a, double& b, double& c);
};

#endif
