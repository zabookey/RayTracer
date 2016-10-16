#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Color.hpp"

class Light{
    public:
    double x, y, z; 
    int w; // 1 indicates Point. 0 indicates directional
    Color color;
};
#endif
