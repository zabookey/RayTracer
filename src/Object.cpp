#include "Object.hpp"

#include<iostream>

using namespace std;

void Object::PrintObject(){
    if(textured){
        cout << "Object is textured" << endl;
        cout << "Texture File: " << texture->filename << endl;
    } else {
        cout << "Color: (" << color.red << " " << color.green << " " << color.blue << ")" << endl;
    }
    cout << "Spec Color: (" << speccolor.red << " " << speccolor.green << " " << speccolor.blue << ")" << endl;
    cout << "Ambient : " << ka << endl;
    cout << "Diffues : " << kd << endl;
    cout << "Specular: " << ks << endl;
    cout << "Spec Power: " << powerN << endl;
}
