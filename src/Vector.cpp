#include "Vector.hpp"

Vector::Vector(){
    dx = 0;
    dy = 0;
    dz = 0;
};

Vector::Vector(double dx_, double dy_, double dz_):
    dx(dx_), dy(dy_), dz(dz_){};
