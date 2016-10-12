#include "SphereCollision.hpp"

// Decides whether or not the input ray intersects the
// surface of the input sphere or not.
// If it does return the smallest t value that's greater than 0.
// Otherwise return -1
double sphereCollision(Ray r, Sphere s){
    double xd = r.direction.dx, yd = r.direction.dy, zd = r.direction.dz;
    double x0 = r.origin.x, y0 = r.origin.y, z0 = r.origin.z;
    double xc = s.center.x, yc = s.center.y, zc = s.center.z;
    double rad = s.radius;
// This should equal 1 since our vector is normalized
    double A = xd*xd + yd*yd + zd*zd;
    double B = 2 * (xd*(x0-xc) + yd*(y0-yc) + zd*(z0-zc));
    double C = (x0-xc)*(x0-xc) + (y0-yc)*(y0-yc) + (z0-zc)*(z0-zc) - rad*rad;
    double disc = B*B - 4*A*C;
    if(disc >= 0){
        double plus = (-B + sqrt(disc))/(2*A);
        double min = (-B - sqrt(disc))/(2*A);
        if(plus < min && plus > 0)
            return plus;
        else
            return min;
    } else if(disc == 0){
        return -B/(2*A);
    } else
        return -1.0;
}
