#include "Face.hpp"
#include "Plane.hpp"
#include "Normalize.hpp"
#include "Waxpby.hpp"

#include <iostream>
using namespace std;
// Empty constructor
Face::Face(){smooth = false;};

// Constructor that takes three points and sets them as the
// vertices of the face
Face::Face(Point p_0, Point p_1, Point p_2):
    p0(p_0), p1(p_1), p2(p_2){smooth = false;};

// Determines the t value where a ray may collide with this face
// returns -1 if no collision
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
    double a, b, c;
    barycentricCord(intersect, a, b, c);
    if(fabs(1 - (a+b+c)) < 1e-4) // Should be a < tolerance dealio...
        return t;
    else
        return -1.0;
};

// Calculates the surface norm at a given point
// Assumes that the point is withing the triangle already.
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
        double a, b, c;
        barycentricCord(intersect, a, b,c);
        waxpby(n, a, np0, b, np1);
        waxpby(n, 1, n, c, np2);
        normalize(n);
    }
    return n;
}

// Finds the base color of this face at the given point
// Assumes that the point is within the triangle.
// Returns color if not textured.
// Finds the appropriate color from the texture if textured
Color Face::getColor(Point p){
    if(!textured)
        return color;
    else{
        Texture* t = texture;
        double a, b, c;
        barycentricCord(p, a, b, c);
        double u = a*tp0.u + b*tp1.u + c*tp2.u;
        double v = a*tp0.v + b*tp1.v + c*tp2.v;
        int i = (int) round(u * (t->width-1));
        int j = (int) round(v * (t->height-1));
        return t->pixelArray[j][i];
    }
};

// Given a point p, sets a b and c to its respective barycentric
// coordinates alpha, beta and gamma
void Face::barycentricCord(Point p, double& a, double& b, double& c){
    double faceArea;
    // Calculate the area of the whole triangle
    Vector e1;
    vpmq(e1, p1, p0);
    Vector e2;
    vpmq(e2, p2, p0);
    Vector cp;
    crossProduct(cp, e1, e2);
    faceArea = norm(cp)/2;
    // Calculate the area of the triangle made from p1 p2 and p
    vpmq(e1, p, p1);
    vpmq(e2, p, p2);
    crossProduct(cp, e1, e2);
    a = norm(cp)/2;
    // Divide it by the total area
    a = a/faceArea;
    // Same thing for b
    vpmq(e1, p, p0);
    vpmq(e2, p, p2);
    crossProduct(cp, e1, e2);
    b = norm(cp)/2;
    b = b/faceArea;
    // Same thing for c
    vpmq(e1, p, p0);
    vpmq(e2, p, p1);
    crossProduct(cp, e1, e2);
    c = norm(cp)/2;
    c = c/faceArea;
};

void Face::PrintObject(){
    cout << "Object is a face/triangle" << endl;
    cout << "P0: (" << p0.x << " " << p0.y << " " << p0.z << ")" << endl;
    cout << "P1: (" << p1.x << " " << p1.y << " " << p1.z << ")" << endl;
    cout << "P2: (" << p2.x << " " << p2.y << " " << p2.z << ")" << endl;
    if(smooth){
        cout << "Face is smooth" << endl;
        cout << "    NP0: (" << np0.dx << " " << np0.dy << " " << np0.dz << ")" << endl;
        cout << "    NP1: (" << np1.dx << " " << np1.dy << " " << np1.dz << ")" << endl;
        cout << "    NP2: (" << np2.dx << " " << np2.dy << " " << np2.dz << ")" << endl;
    } else {
        cout << "Face is flat" << endl;
    }
    if(textured){
        cout << "Texture Vertices: " << endl;
        cout << "    TP0: (" << tp0.u << " " << tp0.v << ")" << endl;
        cout << "    TP1: (" << tp1.u << " " << tp1.v << ")" << endl;
        cout << "    TP2: (" << tp2.u << " " << tp2.v << ")" << endl;
    }
    Object::PrintObject();
}
