cmake_minimum_required(VERSION 3.10)

project(Forest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS Window Graphics REQUIRED)

file(GLOB SOURCES "*.cpp")

add_executable(Forest ${SOURCES})

target_link_libraries(Forest PRIVATE SFML::Window SFML::Graphics)
