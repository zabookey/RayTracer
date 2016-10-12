#include "DotProduct.hpp"

double dotProduct(Vector x, Vector y){
    return (x.dx*y.dx + x.dy*y.dy + x.dz*y.dz);
}
