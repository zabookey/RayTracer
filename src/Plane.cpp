#include "Plane.hpp"
#include "Vpmq.hpp"
#include "CrossProduct.hpp"
#include "Vector.hpp"

#include <iostream>
Plane::Plane(Face f){
    Vector e1;
    vpmq(e1, f.p1, f.p0);
    Vector e2;
    vpmq(e2, f.p2, f.p0);
    Vector n;
    crossProduct(n, e1, e2);
    std::cout << "n.dx: " << n.dx << " n.dy: " << n.dy << " n.dz: " << n.dz << std::endl;
    a = n.dx;
    b = n.dy;
    c = n.dz;
    d = -a*f.p0.x - b*f.p0.y - c*f.p0.z;
    std::cout << "D: " << d << std::endl;
};
