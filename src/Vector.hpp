#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Point.hpp"

class Vector{
    public:
    double dx;
    double dy;
    double dz;
    Vector();
    Vector(double dx_, double dy_, double dz_);
};

inline void copyVector(Vector src, Vector & dest){
    dest.dx = src.dx;
    dest.dy = src.dy;
    dest.dz = src.dz;
}

inline void scaleVector(Vector& x, double scale){
    x.dx *= scale;
    x.dy *= scale;
    x.dz *= scale;
}
#endif
