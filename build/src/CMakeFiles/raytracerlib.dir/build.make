# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zbookey/Documents/Graphics/RayTracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zbookey/Documents/Graphics/RayTracing/build

# Include any dependencies generated for this target.
include src/CMakeFiles/raytracerlib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/raytracerlib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/raytracerlib.dir/flags.make

src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o: ../src/InputReader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/InputReader.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/InputReader.cpp

src/CMakeFiles/raytracerlib.dir/InputReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/InputReader.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/InputReader.cpp > CMakeFiles/raytracerlib.dir/InputReader.cpp.i

src/CMakeFiles/raytracerlib.dir/InputReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/InputReader.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/InputReader.cpp -o CMakeFiles/raytracerlib.dir/InputReader.cpp.s

src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o

src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o: ../src/Waxpby.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/Waxpby.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/Waxpby.cpp

src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/Waxpby.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/Waxpby.cpp > CMakeFiles/raytracerlib.dir/Waxpby.cpp.i

src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/Waxpby.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/Waxpby.cpp -o CMakeFiles/raytracerlib.dir/Waxpby.cpp.s

src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o

src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o: ../src/CrossProduct.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/CrossProduct.cpp

src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/CrossProduct.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/CrossProduct.cpp > CMakeFiles/raytracerlib.dir/CrossProduct.cpp.i

src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/CrossProduct.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/CrossProduct.cpp -o CMakeFiles/raytracerlib.dir/CrossProduct.cpp.s

src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o

src/CMakeFiles/raytracerlib.dir/Norm.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/Norm.cpp.o: ../src/Norm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/Norm.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/Norm.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/Norm.cpp

src/CMakeFiles/raytracerlib.dir/Norm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/Norm.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/Norm.cpp > CMakeFiles/raytracerlib.dir/Norm.cpp.i

src/CMakeFiles/raytracerlib.dir/Norm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/Norm.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/Norm.cpp -o CMakeFiles/raytracerlib.dir/Norm.cpp.s

src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/Norm.cpp.o

src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o: ../src/Normalize.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/Normalize.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/Normalize.cpp

src/CMakeFiles/raytracerlib.dir/Normalize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/Normalize.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/Normalize.cpp > CMakeFiles/raytracerlib.dir/Normalize.cpp.i

src/CMakeFiles/raytracerlib.dir/Normalize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/Normalize.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/Normalize.cpp -o CMakeFiles/raytracerlib.dir/Normalize.cpp.s

src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o

src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o: ../src/Qppax.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/Qppax.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/Qppax.cpp

src/CMakeFiles/raytracerlib.dir/Qppax.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/Qppax.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/Qppax.cpp > CMakeFiles/raytracerlib.dir/Qppax.cpp.i

src/CMakeFiles/raytracerlib.dir/Qppax.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/Qppax.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/Qppax.cpp -o CMakeFiles/raytracerlib.dir/Qppax.cpp.s

src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o

src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o: ../src/Vpmq.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/Vpmq.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/Vpmq.cpp

src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/Vpmq.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/Vpmq.cpp > CMakeFiles/raytracerlib.dir/Vpmq.cpp.i

src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/Vpmq.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/Vpmq.cpp -o CMakeFiles/raytracerlib.dir/Vpmq.cpp.s

src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o

src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o: ../src/SphereCollision.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/SphereCollision.cpp

src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/SphereCollision.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/SphereCollision.cpp > CMakeFiles/raytracerlib.dir/SphereCollision.cpp.i

src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/SphereCollision.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/SphereCollision.cpp -o CMakeFiles/raytracerlib.dir/SphereCollision.cpp.s

src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o

src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o: ../src/ValidityChecker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/ValidityChecker.cpp

src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/ValidityChecker.cpp > CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.i

src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/ValidityChecker.cpp -o CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.s

src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o

src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o: ../src/DotProduct.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/DotProduct.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/DotProduct.cpp

src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/DotProduct.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/DotProduct.cpp > CMakeFiles/raytracerlib.dir/DotProduct.cpp.i

src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/DotProduct.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/DotProduct.cpp -o CMakeFiles/raytracerlib.dir/DotProduct.cpp.s

src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o

src/CMakeFiles/raytracerlib.dir/Phong.cpp.o: src/CMakeFiles/raytracerlib.dir/flags.make
src/CMakeFiles/raytracerlib.dir/Phong.cpp.o: ../src/Phong.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbookey/Documents/Graphics/RayTracing/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/raytracerlib.dir/Phong.cpp.o"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracerlib.dir/Phong.cpp.o -c /home/zbookey/Documents/Graphics/RayTracing/src/Phong.cpp

src/CMakeFiles/raytracerlib.dir/Phong.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracerlib.dir/Phong.cpp.i"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbookey/Documents/Graphics/RayTracing/src/Phong.cpp > CMakeFiles/raytracerlib.dir/Phong.cpp.i

src/CMakeFiles/raytracerlib.dir/Phong.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracerlib.dir/Phong.cpp.s"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbookey/Documents/Graphics/RayTracing/src/Phong.cpp -o CMakeFiles/raytracerlib.dir/Phong.cpp.s

src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.requires:
.PHONY : src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.requires

src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.provides: src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/raytracerlib.dir/build.make src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.provides.build
.PHONY : src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.provides

src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.provides.build: src/CMakeFiles/raytracerlib.dir/Phong.cpp.o

# Object files for target raytracerlib
raytracerlib_OBJECTS = \
"CMakeFiles/raytracerlib.dir/InputReader.cpp.o" \
"CMakeFiles/raytracerlib.dir/Waxpby.cpp.o" \
"CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o" \
"CMakeFiles/raytracerlib.dir/Norm.cpp.o" \
"CMakeFiles/raytracerlib.dir/Normalize.cpp.o" \
"CMakeFiles/raytracerlib.dir/Qppax.cpp.o" \
"CMakeFiles/raytracerlib.dir/Vpmq.cpp.o" \
"CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o" \
"CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o" \
"CMakeFiles/raytracerlib.dir/DotProduct.cpp.o" \
"CMakeFiles/raytracerlib.dir/Phong.cpp.o"

# External object files for target raytracerlib
raytracerlib_EXTERNAL_OBJECTS =

src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/Norm.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/Phong.cpp.o
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/build.make
src/libraytracerlib.a: src/CMakeFiles/raytracerlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libraytracerlib.a"
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && $(CMAKE_COMMAND) -P CMakeFiles/raytracerlib.dir/cmake_clean_target.cmake
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracerlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/raytracerlib.dir/build: src/libraytracerlib.a
.PHONY : src/CMakeFiles/raytracerlib.dir/build

src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/InputReader.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/Waxpby.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/CrossProduct.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/Norm.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/Normalize.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/Qppax.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/Vpmq.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/SphereCollision.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/ValidityChecker.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/DotProduct.cpp.o.requires
src/CMakeFiles/raytracerlib.dir/requires: src/CMakeFiles/raytracerlib.dir/Phong.cpp.o.requires
.PHONY : src/CMakeFiles/raytracerlib.dir/requires

src/CMakeFiles/raytracerlib.dir/clean:
	cd /home/zbookey/Documents/Graphics/RayTracing/build/src && $(CMAKE_COMMAND) -P CMakeFiles/raytracerlib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/raytracerlib.dir/clean

src/CMakeFiles/raytracerlib.dir/depend:
	cd /home/zbookey/Documents/Graphics/RayTracing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zbookey/Documents/Graphics/RayTracing /home/zbookey/Documents/Graphics/RayTracing/src /home/zbookey/Documents/Graphics/RayTracing/build /home/zbookey/Documents/Graphics/RayTracing/build/src /home/zbookey/Documents/Graphics/RayTracing/build/src/CMakeFiles/raytracerlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/raytracerlib.dir/depend

