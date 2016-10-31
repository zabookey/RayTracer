#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Ray.hpp"
#include "Point.hpp"
#include "Color.hpp"
#include "Texture.hpp"

// A base class for scene objects to extend.
class Object{
    public:
        Color color;
        Color speccolor;
        double ka, kd, ks;
        int powerN;
        double f0;
        bool textured = false;
        Texture* texture = NULL;
        virtual double collision(Ray r)=0;
        virtual Vector normVector(Point* collision)=0; // Point* so null can be passed
        virtual Color getColor(Point p)=0; 
        virtual void PrintObject();
};
#endif
