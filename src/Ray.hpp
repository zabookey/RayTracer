#ifndef RAY_HPP
#define RAY_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Vpmq.hpp"
#include "Normalize.hpp"

struct Ray_Struct{
    Point origin;
    Vector direction;
};

typedef struct Ray_Struct Ray;

inline void initRay(Ray& r, Point src, Point dest){
    copyPoint(src, r.origin);
    vpmq(r.direction, dest, src);
    normalize(r.direction);
}
#endif
