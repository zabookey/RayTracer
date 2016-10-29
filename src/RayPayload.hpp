#ifndef RAYPAYLOAD_HPP
#define RAYPAYLOAD_HPP

#include <float.h>
#include "Object.hpp"
#include "Ray.hpp"

#include <vector>
using namespace std;

class RayPayload{
    public:
        Object* nearest;
        double nearestDist = DBL_MAX;
        RayPayload();
        RayPayload(Object* nearest, double nearestDist);
};

RayPayload traceRay(Ray& r, vector<Object*> objects);
#endif
