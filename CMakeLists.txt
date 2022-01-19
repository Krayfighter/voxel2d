cmake_minimum_required(VERSION 3.0.0)
project(
    voxel2d
    VERSION 0.1.0
    LANGUAGES CXX
)

include(CTest)
enable_testing()

add_executable(voxel2d src/main.cpp)

target_link_libraries(
    voxel2d
    sfml-graphics
    sfml-window
    sfml-system
)

target_compile_features(
    voxel2d
    PRIVATE
    cxx_std_20
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
