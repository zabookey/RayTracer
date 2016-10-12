#include "Normalize.hpp"

// Normalizes the vector by calculating the norm of the matrix
// and dividing the entries by it
void normalize(Vector & x){
    double xnorm = norm(x);
    x.dx = x.dx/xnorm;
    x.dy = x.dy/xnorm;
    x.dz = x.dz/xnorm;
}
