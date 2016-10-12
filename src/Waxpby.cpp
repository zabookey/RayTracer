#include "Waxpby.hpp"

// W = alpha * x + beta * y
void waxpby(Vector & w, double alpha, Vector x, double beta, Vector y){
    w.dx = alpha*x.dx + beta*y.dx;
    w.dy = alpha*x.dy + beta*y.dy;
    w.dz = alpha*x.dz + beta*y.dz;
}
