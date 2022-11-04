cmake_minimum_required(VERSION 3.22.0)

project(race_library)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(race_library SHARED
	leaver.h
	leaver.cpp
	transport.h
	transport.cpp
	ground_transport.h
	ground_transport.cpp
	camel.h
	camel.cpp
	air_transport.h
	air_transport.cpp
	magic_carpet.h
	magic_carpet.cpp
	grand_prix.h
	grand_prix.cpp
	centaur.h
	centaur.cpp
	ground_grand_prix.h
	ground_grand_prix.cpp
	air_grand_prix.h
	air_grand_prix.cpp
	mixed_grand_prix.h
	mixed_grand_prix.cpp
	grand_prix_error.h
	grand_prix_error.cpp
	speed_camel.h
	speed_camel.cpp
	terrain_boots.h
	terrain_boots.cpp
	eagle.h
	eagle.cpp
	broom.h
	broom.cpp)