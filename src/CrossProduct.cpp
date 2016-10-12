#include "CrossProduct.hpp"

// Performs the cross product of two vectors
// Input:
//      w -> The vector to store the cross product in
//      x -> The the left vector to cross product
//      y -> The right vector to cross product
void crossProduct(Vector & w, Vector x, Vector y){
    w.dx = x.dy*y.dz - x.dz*y.dy;
    w.dy = x.dz*y.dx - x.dx*y.dz;
    w.dz = x.dx*y.dy - x.dy*y.dx;
}
