#include "Face.hpp"
#include "Plane.hpp"
#include "Normalize.hpp"
#include "Waxpby.hpp"

#include <iostream>
Face::Face(){smooth = false;};

Face::Face(Point p_0, Point p_1, Point p_2):
    p0(p_0), p1(p_1), p2(p_2){smooth = false;};

double Face::collision(Ray r){
    Plane p(*this);
    Vector d = r.direction;
    Point o = r.origin;
    double denom = p.a*d.dx + p.b*d.dy + p.c*d.dz;
    if(fabs(denom) < 1e-4) // Should be a < tolerance dealio...
        return -1.0;
    double numer = -(p.a*o.x + p.b*o.y + p.c*o.z + p.d);
    // t value where ray intersects the plane.
    // Not necessarily within the face/triangle
    double t = numer/denom;
    double faceArea;
    Point intersect;
    qppax(intersect, r.origin, t, r.direction);
    Vector e1;
    vpmq(e1, p1, p0);
    Vector e2;
    vpmq(e2, p2, p0);
    Vector cp;
    crossProduct(cp, e1, e2);
    faceArea = norm(cp)/2;
    double a; // Area of triangle created from i, p1 and p2
    vpmq(e1, intersect, p1);
    vpmq(e2, intersect, p2);
    crossProduct(cp, e1, e2);
    a = norm(cp)/2;
    double b; // Area of triangle created from i, p0 and p2
    vpmq(e1, intersect, p0);
    vpmq(e2, intersect, p2);
    crossProduct(cp, e1, e2);
    b = norm(cp)/2;
    double c; // Area pf triangle created from i, p1 and p2
    vpmq(e1, intersect, p0);
    vpmq(e2, intersect, p1);
    crossProduct(cp, e1, e2);
    c = norm(cp)/2;
    if(fabs(faceArea - (a+b+c)) < 1e-4) // Should be a < tolerance dealio...
        return t;
    else
        return -1.0;
};

Vector Face::normVector(Point* collision){
    Vector n;
    if(!smooth){
        Vector e1;
        Vector e2;
        vpmq(e1, p1, p0);
        vpmq(e2, p2, p0);
        crossProduct(n, e1, e2);
        normalize(n);
    }
    else{
        double faceArea;
        Point intersect = *collision;
        Vector e1;
        vpmq(e1, p1, p0);
        Vector e2;
        vpmq(e2, p2, p0);
        Vector cp;
        crossProduct(cp, e1, e2);
        faceArea = norm(cp)/2;
        double a; // Area of triangle created from i, p1 and p2
        vpmq(e1, intersect, p1);
        vpmq(e2, intersect, p2);
        crossProduct(cp, e1, e2);
        a = norm(cp)/2;
        a = a/faceArea;
        double b; // Area of triangle created from i, p0 and p2
        vpmq(e1, intersect, p0);
        vpmq(e2, intersect, p2);
        crossProduct(cp, e1, e2);
        b = norm(cp)/2;
        b = b/faceArea;
        double c; // Area pf triangle created from i, p0 and p1
        vpmq(e1, intersect, p0);
        vpmq(e2, intersect, p1);
        crossProduct(cp, e1, e2);
        c = norm(cp)/2;
        c = c/faceArea;
        waxpby(n, a, np0, b, np1);
        waxpby(n, 1, n, c, np2);
        normalize(n);
    }
    return n;
}
