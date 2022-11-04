cmake_minimum_required(VERSION 3.22.0)

project(main)

include_directories(../race_library)

add_executable(race main.cpp)

target_include_directories(
	race
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../race_library
)

target_link_libraries(race race_library)