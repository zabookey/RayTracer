#include "Texture.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

Texture::Texture(){};

Texture::Texture(string filename, bool& success){
    ifstream inputFile(filename);
    if(!inputFile){
        success = false;
        return;
    }
    int maxPixelValue;
    string line;
    string delimiter = " ";
    getline(inputFile, line);
    size_t pos = line.find(delimiter);
    // Find the P3 keyword and throw it out...
    if(pos == string::npos){
        success = false;
        inputFile.close();
        return;
    }
    line.erase(0, pos+delimiter.length());
    // Find the width value
    pos = line.find(delimiter);
    if(pos == string::npos){
        success = false;
        inputFile.close();
        return;
    }
    string widthstring = line.substr(0, pos);
    try{
        width = stoi(widthstring, NULL);
    } catch (invalid_argument& e){
        success = false;
        inputFile.close();
        return;
    }
    line.erase(0, pos+delimiter.length());
    // Find the height value
    pos = line.find(delimiter);
    if(pos == string::npos){
        success = false;
        inputFile.close();
        return;
    }
    string heightstring = line.substr(0, pos);
    try{
        height = stoi(heightstring, NULL);
    } catch (invalid_argument& e){
        success = false;
        inputFile.close();
        return;
    }
    line.erase(0, pos+delimiter.length());
    // Find the max pixel value
    pos = line.find(delimiter);
    if(pos != string::npos){
        success = false;
        inputFile.close();
        return;
    }
    try{
        maxPixelValue = stoi(line, NULL);
    } catch (invalid_argument& e){
        success = false;
        inputFile.close();
        return;
    }
    // First file read fine. Preallocate our pixel array.
    pixelArray = new Color*[width];
    for(int i = 0; i < width; i++)
        pixelArray[i] = new Color[height];
    int pixelnum = 0;
    while(getline(inputFile, line)){
        int red, blue, green;        
        // Find the width value
        pos = line.find(delimiter);
        if(pos == string::npos){
            success = false;
            inputFile.close();
            return;
        }
        string redstring = line.substr(0, pos);
        try{
            red = stoi(redstring, NULL);
        } catch (invalid_argument& e){
            success = false;
            inputFile.close();
            return;
        }
        line.erase(0, pos+delimiter.length());
        // Find the height value
        pos = line.find(delimiter);
        if(pos == string::npos){
            success = false;
            inputFile.close();
            return;
        }
        string greenstring = line.substr(0, pos);
        try{
            green = stoi(greenstring, NULL);
        } catch (invalid_argument& e){
            success = false;
            inputFile.close();
            return;
        }
        line.erase(0, pos+delimiter.length());
        // Find the max pixel value
        pos = line.find(delimiter);
        if(pos != string::npos){
            success = false;
            inputFile.close();
            return;
        }
        try{
            blue = stoi(line, NULL);
        } catch (invalid_argument& e){
        success = false;
        inputFile.close();
        return;
        }
        Color c;
        c.red = ((double) red)/maxPixelValue;
        c.green = ((double) green)/maxPixelValue;
        c.blue = ((double) blue)/maxPixelValue;
        pixelArray[pixelnum % width][pixelnum / width] = c;
        pixelnum++;
    }
    inputFile.close();
    success = true;
}

Texture::~Texture(){
    if(pixelArray != NULL){
        cout << "Pixel Array being deleted! " << endl;
        for(int i = 0; i < width; i++)
            delete(pixelArray[i]);
        delete(pixelArray);
    }
}
