set(SOURCES
    InputReader.cpp Waxpby.cpp CrossProduct.cpp Norm.cpp Normalize.cpp
    Qppax.cpp Vpmq.cpp SphereCollision.cpp ValidityChecker.cpp DotProduct.cpp
    Phong.cpp Vector.cpp Point.cpp Face.cpp Plane.cpp Sphere.cpp Texture.cpp
    )

set(HEADERS
    Point.hpp Vector.hpp Color.hpp Sphere.hpp InputData.hpp InputReader.hpp
    Ray.hpp Waxpby.hpp CrossProduct.hpp Norm.hpp Normalize.hpp Qppax.hpp
    Vpmq.hpp SphereCollision.hpp ValidityChecker.hpp Light.hpp DotProduct.hpp
    Phong.hpp Face.hpp Plane.hpp Object.hpp Texture.hpp
    )

add_library(raytracerlib ${SOURCES} ${HEADERS})

add_executable(RayTracer.exe main.cpp)

target_link_libraries(RayTracer.exe raytracerlib)
