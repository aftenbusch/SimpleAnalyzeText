cmake_minimum_required(VERSION 3.15)
#
# Text Analyze Project
#
project(TextAnalyzer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# locate header files
include_directories(include)

# sources
set(SOURCES src/main.cpp)
file(GLOB SOURCES src/*.cpp)

#
add_executable(analyzeText ${SOURCES})