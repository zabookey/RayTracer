#include "Vpmq.hpp"

// Calculates the vector from the difference of two points
// V = p - q
void vpmq(Vector& v, Point p, Point q){
    v.dx = p.x - q.x;
    v.dy = p.y - q.y;
    v.dz = p.z - q.z;
}
