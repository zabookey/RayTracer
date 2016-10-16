#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "Light.hpp"
#include "Face.hpp"
#include <vector>

class InputData{
    public:
    int imageWidth;
    int imageHeight;
    Point eye;
    Color bkgcolor;
    Vector updir;
    Vector viewdir;
    int fovv;
    std::vector<Sphere> spheres;
    std::vector<Point> vertices;
    std::vector<Face> faces;
    std::vector<Light> lights;
};

#endif
