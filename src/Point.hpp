#ifndef POINT_HPP
#define POINT_HPP

class Point{
    public:
    double x;
    double y;
    double z;
};

inline void copyPoint(Point src, Point & dest){
    dest.x = src.x;
    dest.y = src.y;
    dest.z = src.z;
}
#endif

