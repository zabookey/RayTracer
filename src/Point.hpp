#ifndef POINT_HPP
#define POINT_HPP

struct Point_Struct{
    double x;
    double y;
    double z;
}; 
typedef struct Point_Struct Point;

inline void copyPoint(Point src, Point & dest){
    dest.x = src.x;
    dest.y = src.y;
    dest.z = src.z;
}
#endif

