Ray tracing assignment
Author: Zach Bookey

Overview:
This program when built will read an input file and use ray tracing to draw
the scene described in an output file named after the input file.

To build:
This program uses a cmake script to create a makefile that will build the program 
as RayTracer.exe. The supplied configure script will create a build directory and 
launch the cmake script from there and call make. Once the configure script 
completes the executable can be found in ./build/src/

Input:
The input file describes the scene to be drawn by the Ray Tracer. Each line of the
input file must have a keyword and then the required variables following each
keyword separated by a single space. For Example:
keyword var1 var2 var3
Using things other than spaces will cause the reader to fail.
The input file must also contain the following keywords with the required number
of variables:
imsize <width> <height>
eye <x> <y> <z>
fovv <angle>
viewdir <dx> <dy> <dz>
updir <dx> <dy> <dz>
bkgcolor <red> <green> <blue>
mtlcolor <red> <green> <blue> <specred> <specgreen> <specblue> <ka> <kd> <ks> <n> <opac> <refrac>
texture <texture_file_name>
sphere <x> <y> <z> <radius>
light <x> <y> <z> <w> <red> <green> <blue>
v <x> <y> <z>
vn <dx> <dy> <dz>
vt <x> <y>
f <v1>/<vt1>/<vn1> <v2>/<vt2>/<vn2> <v3>/<vt3>/<vn3>
f <v1>/<vt1> <v2>/<vt2> <v3>/<vt3>
f <v1>//<vn1> <v2>//<vn2> <v3>//<vn3>
f <v1> <v2> <v3>

Running:
Run the file like so:
./RayTracer.exe <pathToInputFile>
If the file runs to completion it will produce an image of the scene in ppm format
in the run directory called <InputFile>.ppm
