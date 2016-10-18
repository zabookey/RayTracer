#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Color.hpp"

#include <string>

using namespace std;

class Texture{
    public:
        int width;
        int height;
        Color ** pixelArray = NULL;
        Texture(string filename, bool& error);
        ~Texture();
};
#endif