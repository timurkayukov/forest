cmake_minimum_required(VERSION 3.10)

project(Forest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS window graphics REQUIRED)

set(SOURCES
    Animal.cpp
    Carnivore.cpp
    Cat.cpp
    Cow.cpp
    Creature.cpp
    Fish.cpp
    Flower.cpp
    Forest.cpp
    Herbivore.cpp
    Lion.cpp
    Mushroom.cpp
    Penguin.cpp
    Plant.cpp
    Sparrow.cpp
    Sundew.cpp
    main.cpp
)

add_executable(Forest ${SOURCES})

target_link_libraries(Forest PRIVATE sfml-window sfml-graphics)
