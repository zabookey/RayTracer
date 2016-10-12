#ifndef COLOR_HPP
#define COLOR_HPP

struct Color_Struct{
    double red;
    double green;
    double blue;
};
typedef struct Color_Struct Color;

// Function that copies one color struct to another
inline void copyColor(Color src, Color & dest){
    dest.red = src.red;
    dest.green = src.green;
    dest.blue = src.blue;
}
#endif
