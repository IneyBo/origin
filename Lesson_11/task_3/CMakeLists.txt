cmake_minimum_required(VERSION 2.22.0)

project(Leaver)

add_library(LeaverLibraryDynamic SHARED leaver.h leaver.cpp)
add_executable(LeaverExe task_3.cpp)
target_link_libraries(LeaverExe LeaverLibraryDynamic)