#include "Ray.hpp"

Ray::Ray(){};

Ray::Ray(Point src, Point dest){
    origin = src;
    vpmq(direction, dest, src);
    normalize(direction);
};

Ray::Ray(Point origin_, Vector direction_):
    origin(origin_), direction(direction_){};
