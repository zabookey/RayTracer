#include "InputReader.hpp"

using namespace std;


// Reads the input file provided by the user
// Returns 0 if it succeeds otherwise
//   - -2 if the file can't be opened
//   - -1 if the input file doesn't contain all necessary fields
//   - The line number where an error occured.
int readInputFile(string filename, InputData& data){
    ifstream inputFile(filename);
    if(!inputFile){
        return -2;
    }
//    inputFile.open(filename);
    data.imageWidth = 0;
    data.imageHeight = 0;

    Color mtlcolor;
    mtlcolor.red = 0; mtlcolor.green = 0; mtlcolor.blue = 0;
    Color speccolor;
    speccolor.red = 0; speccolor.green = 0; speccolor.blue=0;

    double kAmbient = 0;
    double kDiffuse = 0;
    double kSpecular = 0;
    int powerN = 0;

    string line;
    string delimiter = " ";
    int linenum = 0;

    bool imsizeUsed = false;
    bool fovvUsed = false;
    bool eyeUsed = false;
    bool viewdirUsed = false;
    bool updirUsed = false;
    bool bkgcolorUsed = false;

    while(getline(inputFile, line)){
        linenum++;
        bool error = false;
        size_t pos = line.find(delimiter);
        if(pos == string::npos)continue;
        string keyword = line.substr(0,pos);
        line.erase(0, pos+delimiter.length());
        if(keyword.compare("imsize") == 0){
            error = !process_imsize(line, delimiter, data);
            imsizeUsed = true;
        } else if(keyword.compare("fovv") == 0){
            error = !process_fovv(line,delimiter, data);
            fovvUsed = true;
        } else if(keyword.compare("eye") == 0){
            error = !process_eye(line, delimiter, data);
            eyeUsed = true;
        } else if(keyword.compare("bkgcolor") == 0){
            error = !process_bkgcolor(line, delimiter, data);
            bkgcolorUsed = true;
        } else if(keyword.compare("updir") == 0){
            error = !process_updir(line, delimiter, data);
            updirUsed = true;
        } else if(keyword.compare("viewdir") == 0){
            error = !process_viewdir(line, delimiter, data);
            viewdirUsed = true;
        } else if(keyword.compare("mtlcolor") == 0){
            error = !process_mtlcolor(line, delimiter, mtlcolor, speccolor,
                    kAmbient, kDiffuse, kSpecular, powerN);
        } else if(keyword.compare("sphere") == 0){
            error = !process_sphere(line, delimiter, data, mtlcolor, speccolor,
                    kAmbient, kDiffuse, kSpecular, powerN);
        } else if(keyword.compare("light") == 0){
            error = !process_light(line, delimiter, data);
        } else if(keyword.compare("v") == 0){
            error = !process_vertex(line, delimiter, data);
        } else if(keyword.compare("f") == 0){
            error = !process_face(line, delimiter, data);
        }
        if(error){
            inputFile.close();
            return linenum;
        }
    }
    inputFile.close();

    bool allTagsUsed = true;
    if(!imsizeUsed || !fovvUsed || !eyeUsed || !viewdirUsed || !updirUsed || !bkgcolorUsed)
        allTagsUsed = false;
    if(!allTagsUsed)
        return -1;
//    Light l;
//    l.x = 0; l.y = 1; l.z = 1; l.w = 0;
//    l.color.red = 1; l.color.green = 1; l.color.blue = 1;
//    data.lights.push_back(l);
    return 0;
}

// Process the line that contains the token imsize
// Reads in the image width and height
bool process_imsize(string line, string delimiter, InputData& data){
    size_t pos = line.find(delimiter);
    // imsize has 0 or 1 strings so return linenum to indicate fail
    if(pos == string::npos){
        return false;
    }
    string widthString = line.substr(0,pos);
    try{
        data.imageWidth = stoi(widthString, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos){
            data.imageHeight = stoi(line, NULL);
        } else {
            string heightString = line.substr(0,pos);
            data.imageHeight = stoi(heightString, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    return true;
}

// Process the line that contains the token fovv
// Reads in the vertical field of view
bool process_fovv(string line, string delimiter, InputData& data){
    size_t pos = line.find(delimiter);
    try{
        if(pos == string::npos){
            data.fovv = stoi(line, NULL);
        } else {
            string token = line.substr(0,pos);
            data.fovv = stoi(token, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    return true;
}

// Process the line that contains the token eye
// Reads in the point for the eye
bool process_eye(string line, string delimiter, InputData& data){
    Point eyePoint;
    size_t pos = line.find(delimiter);
    // eye has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        eyePoint.x = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // eye has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        eyePoint.y = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            eyePoint.z = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            eyePoint.z = stod(token, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    data.eye = eyePoint;
    return true;
}

// Process the line that contains the token bkgcolor
// Reads in the rgb values for bkgcolor
bool process_bkgcolor(string line, string delimiter, InputData& data){
    Color bkgcolor;
    double red;
    double green;
    double blue;
    size_t pos = line.find(delimiter);
    // bkgcolor has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        red = stod(token, NULL);
        if(red < 0 || red > 1){
            cout << "Red value out of Range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // eye has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        green = stod(token, NULL);
        if(green < 0 || green > 1){
            cout << "Green value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            blue = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            blue = stod(token, NULL);
        }
        if(blue < 0 || blue > 1){
            cout << "Blue value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    bkgcolor.red = red;
    bkgcolor.blue = blue;
    bkgcolor.green = green;
    data.bkgcolor = bkgcolor;
    return true;
}

// Processes the line that contains the token updir
// reads in the information to fill in the up direction vector
bool process_updir(string line, string delimiter, InputData& data){
    Vector updir;
    size_t pos = line.find(delimiter);
    // updir has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        updir.dx = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // updir has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        updir.dy = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            updir.dz = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            updir.dz = stod(token, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    data.updir = updir;
    return true;
}

// Process the line that contains the token viewdir
// Reads the information and fills in the view direction vector
bool process_viewdir(string line, string delimiter, InputData& data){
    Vector viewdir;
    size_t pos = line.find(delimiter);
    // updir has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        viewdir.dx = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // updir has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        viewdir.dy = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            viewdir.dz = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            viewdir.dz = stod(token, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    data.viewdir = viewdir;
    return true;
}

// Process the line that contains the token mtlcolor
// Sets the mtlcolor to the desired to the rgb values.
// This will be stored so any objects created will be this color
bool process_mtlcolor(string line, string delimiter, Color& mtlcolor, 
        Color& speccolor, double& kAmbient, double& kDiffuse, double& kSpecular,
        int& powerN){
    double red;
    double green;
    double blue;
    size_t pos = line.find(delimiter);
    // bkgcolor has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        red = stod(token, NULL);
        if(red < 0 || red > 1){
            cout << "Red value out of Range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // eye has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        green = stod(token, NULL);
        if(green < 0 || green > 1){
            cout << "Green value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    token = line.substr(0,pos);
    try{
        blue = stod(token, NULL);
        if(blue < 0 || blue > 1){
            cout << "Blue value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());

    mtlcolor.red = red;
    mtlcolor.blue = blue;
    mtlcolor.green = green;

    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        red = stod(token, NULL);
        if(red < 0 || red > 1){
            cout << "Red value out of Range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // eye has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        green = stod(token, NULL);
        if(green < 0 || green > 1){
            cout << "Green value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        blue = stod(token, NULL);
        if(blue < 0 || blue > 1){
            cout << "Blue value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    speccolor.red = red;
    speccolor.blue = blue;
    speccolor.green = green;

    double ka, kd, ks;
    int n;

    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        ka = stod(token, NULL);
        if(ka < 0 || ka > 1){
            cout << "KA value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());

    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        kd = stod(token, NULL);
        if(kd < 0 || kd > 1){
            cout << "KD valud out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());

    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        ks = stod(token, NULL);
        if(ks < 0 || ks > 1){
            cout << "KS value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());

    pos = line.find(delimiter);
    try{
        if(pos == string::npos){
            n = stoi(line, NULL);
        } else {
            token = line.substr(0, pos);
            n = stoi(token, NULL);
        }
        if(n < 0){
            cout << "n value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    kAmbient = ka;
    kDiffuse = kd;
    kSpecular = ks;
    powerN = n;

    return true;
}

// Processes the line that contains the token sphere
// Adds a sphere created by the information in this line to the vector
bool process_sphere(string line, string delimiter, InputData& data, Color& mtlcolor,
        Color& speccolor, double& kAmbient, double& kDiffuse, double& kSpecular,
        int& powerN){
    double x;
    double y;
    double z;
    double radius;
    size_t pos = line.find(delimiter);
    // bkgcolor has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        x = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        y = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        z = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            radius = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            radius = stod(token, NULL);
        }
        if(radius < 0){
            cout << "Radius value out of range" << endl;
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    Sphere* sphere = new Sphere;
    sphere->color = mtlcolor;
    sphere->center.x = x;
    sphere->center.y = y;
    sphere->center.z = z;
    sphere->radius = radius;
    sphere->speccolor = speccolor;
    sphere->ka = kAmbient;
    sphere->kd = kDiffuse;
    sphere->ks = kSpecular;
    sphere->powerN = powerN;
    data.objects.push_back(sphere);
    return true;
}

// Process the light keyword.
bool process_light(string line, string delimiter, InputData& data){
    double x;
    double y;
    double z;
    int w;
    Color color;
    size_t pos = line.find(delimiter);
    // bkgcolor has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        x = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        y = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        z = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        w = stoi(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        color.red = stod(token, NULL);
        if(color.red < 0)
            return false;
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        color.green = stod(token, NULL);
        if(color.green < 0)
            return false;
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            color.blue = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            color.blue = stod(token, NULL);
        }
        if(color.blue < 0){
            return false;
        }
    } catch (invalid_argument& e){
        return false;
    }
    Light light;
    light.x = x;
    light.y = y;
    light.z = z;
    light.w = w;
    light.color = color;
    data.lights.push_back(light);
    return true;
}

// Process the line that contains the token v
// Reads in the point for the vertex and adds it to the vertex array
bool process_vertex(string line, string delimiter, InputData& data){
    double x, y, z;
    size_t pos = line.find(delimiter);
    // eye has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        x = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // eye has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        y = stod(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            z = stod(line, NULL);
        else{
            token = line.substr(0,pos);
            z = stod(token, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    data.vertices.push_back(Point(x,y,z));
    return true;
}

// Process the line that contains the token f
// Reads in the vertices from the vertex array and creates the appropriate face.
// Adds the face to the face array
bool process_face(string line, string delimiter, InputData& data){
    int v1, v2, v3;
    size_t pos = line.find(delimiter);
    // eye has 0 or 1 tokens so fail
    if(pos == string::npos){
        return false;
    }
    string token = line.substr(0,pos);
    try{
        v1 = stoi(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0, pos+delimiter.length());
    pos = line.find(delimiter);
    // eye has 1 or 2 tokens so fail
    if(pos == string::npos){
        return false;
    }
    token = line.substr(0,pos);
    try{
        v2 = stoi(token, NULL);
    } catch (invalid_argument& e){
        return false;
    }
    line.erase(0,pos+delimiter.length());
    pos = line.find(delimiter);
    try{
        if(pos == string::npos)
            v3 = stoi(line, NULL);
        else{
            token = line.substr(0,pos);
            v3 = stoi(token, NULL);
        }
    } catch (invalid_argument& e){
        return false;
    }
    int nv = data.vertices.size();
    if(v1 < 1 || v1 > nv || v2 < 1 || v2 > nv || v3 < 1 || v3 > nv){
        cout << "Face wants vertex that doesn't exist yet." << endl;
        return false;
    }
    data.faces.push_back(Face(data.vertices[v1-1], data.vertices[v2-1],
                data.vertices[v3-1]));
    return true;
}
