#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Color.hpp"

struct Light_Struct{
    double x, y, z; 
    int w; // 1 indicates Point. 0 indicates directional
    Color color;
};

typedef struct Light_Struct Light;
#endif
