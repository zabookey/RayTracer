#ifndef COLOR_HPP
#define COLOR_HPP

class Color{
    public:
        double red;
        double green;
        double blue;
};

// Function that copies one color struct to another
inline void copyColor(Color src, Color & dest){
    dest.red = src.red;
    dest.green = src.green;
    dest.blue = src.blue;
}
#endif
