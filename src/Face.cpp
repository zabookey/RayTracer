#include "Face.hpp"
#include "Plane.hpp"

#include <iostream>
using namespace std;

Face::Face(Point p_0, Point p_1, Point p_2):
    p0(p_0), p1(p_1), p2(p_2){};

double Face::collision(Ray r){
    Plane p(*this);
    Vector d = r.direction;
    Point o = r.origin;
    cout << "Plane: (" << p.a << " " << p.b << " " << p.c << " " << p.d << ")" << endl;
    double denom = p.a*d.dx + p.b*d.dy + p.c*d.dz;
    cout << "Denom: " << denom << endl;
    if(denom == 0) // Should be a < tolerance dealio...
        return -1.0;
    double numer = -(p.a*o.x + p.b*o.y + p.c*o.z + p.d);
    cout << "Numer: " << numer << endl;
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
    cout << "e1: (" << e1.dx << " " << e1.dy << " " << e1.dz << ")" << endl;
    cout << "e2: (" << e2.dx << " " << e2.dy << " " << e2.dz << ")" << endl;
    cout << "cp: (" << cp.dx << " " << cp.dy << " " << cp.dz << ")" << endl;
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
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "FA: " << faceArea << endl;
    if(fabs(faceArea - (a+b+c)) < 1e-4) // Should be a < tolerance dealio...
        return t;
    else
        return -1.0;
};
