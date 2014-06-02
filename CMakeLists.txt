cmake_minimum_required(VERSION 2.8)

project (apricot)

set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -0s")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")

set(APRICOT_HEADERS
	include/Apricot/Log.hpp
        include/Apricot/Argument.hpp
        include/Apricot/Apricot.hpp
    )

set(APRICOT_SOURCES
	src/Log.cpp
    )

add_library(apricot ${APRICOT_SOURCES} ${APRICOT_HEADERS})
include_directories(include)
