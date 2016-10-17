#include "Plane.hpp"
#include "Vpmq.hpp"
#include "CrossProduct.hpp"
#include "Vector.hpp"

Plane::Plane(Face f){
    Vector e1;
    vpmq(e1, f.p1, f.p0);
    Vector e2;
    vpmq(e2, f.p2, f.p0);
    Vector n;
    crossProduct(n, e1, e2);
    a = n.dx;
    b = n.dy;
    c = n.dz;
    d = -a*f.p0.x - b*f.p0.y - c*f.p0.z;
};
