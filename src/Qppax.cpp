#include "Qppax.hpp"

// Calculates a point plus a scalar times a vector
// Q = P + alpha * x
void qppax(Point& q, Point p, double alpha, Vector x){
    q.x = p.x + alpha*x.dx;
    q.y = p.y + alpha*x.dy;
    q.z = p.z + alpha*x.dz;
}
