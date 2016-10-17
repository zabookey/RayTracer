#ifndef PLANE_HPP
#define PLANE_HPP
#include "Face.hpp"

// Coefficients for the plane equation. Ax+By+Cz+D=0
class Plane{
    public:
        double a;
        double b;
        double c;
        double d;
        Plane(Face f);
};

#endif
