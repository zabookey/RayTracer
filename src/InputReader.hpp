#ifndef INPUTREADER_HPP
#define INPUTREADER_HPP

#include "InputData.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "Light.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int readInputFile(std::string filename, InputData& data);

bool process_imsize(std::string line, std::string delimiter, InputData& data);

bool process_fovv(std::string line, std::string delimiter, InputData& data);

bool process_eye(std::string line, std::string delimiter, InputData& data);

bool process_bkgcolor(std::string line, std::string delimiter, InputData& data);

bool process_updir(std::string line, std::string delimiter, InputData& data);

bool process_viewdir(std::string line, std::string delimiter, InputData& data);

bool process_mtlcolor(std::string line, std::string delimiter, Color& mtlcolor,
        Color& speccolor, double& kAmbient, double& kDiffuse, double& kSpecular,
        int& powerN);

bool process_sphere(std::string line, std::string delimiter, InputData& data, Color& mtlcolor,
        Color& speccolor, double& kAmbient, double& kDiffuse, double& kSpecular,
        int& powerN);

bool process_light(std::string line, std::string delimiter, InputData& data);

bool process_vertex(std::string line, std::string delimiter, InputData& data);

bool process_face(std::string line, std::string delimiter, InputData& data, Color& mtlcolor,
        Color& speccolor, double& kAmbient, double& kDiffuse, double& kSpecular,
        int& powerN);
#endif
