#ifndef PHONG_HPP
#define PHONG_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "Color.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include "Vpmq.hpp"
#include "Normalize.hpp"
#include "DotProduct.hpp"
#include "Waxpby.hpp"
#include "SphereCollision.hpp"

#include <vector>
#include <cfloat>

using namespace std;

Color phong(Point intersection, Sphere sphere, vector<Light> lights,
        vector<Sphere> spheres, Vector viewdir, int npower);

#endif
