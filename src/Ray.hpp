#ifndef RAY_HPP
#define RAY_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Vpmq.hpp"
#include "Normalize.hpp"

class Ray{
    public:
    Point origin;
    Vector direction;
    Ray();
    Ray(Point src, Point dest);
};

inline void initRay(Ray& r, Point src, Point dest){
    copyPoint(src, r.origin);
    vpmq(r.direction, dest, src);
    normalize(r.direction);
}
#endif
