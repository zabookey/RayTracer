#include "Norm.hpp"

// Calculates and returns the norm of the input vector
double norm(Vector x){
    return sqrt(x.dx*x.dx + x.dy*x.dy + x.dz*x.dz);
}
