#include "RayPayload.hpp"

RayPayload::RayPayload(Object * nearest_, double nearestDist_):
    nearest(nearest_), nearestDist(nearestDist_){};

RayPayload traceRay(Ray& r, vector<Object*> objects){
    Object* nearest = 0;
    double nearestDist = DBL_MAX;
    int numberObjects = objects.size();
    for(int i = 0; i < numberObjects; i++){
        double t = objects[i]->collision(r);
        if(t >= 1e-3 && t < nearestDist){
            nearestDist = t;
            nearest = objects[i];
        }
    }
    return RayPayload(nearest, nearestDist);
}
