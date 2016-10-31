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

Color phong(Point intersection, Object* object, vector<Light> lights,
        vector<Object*> objects, Vector viewdir, double rayrefrac, int npower);

#endif
