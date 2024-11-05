cmake_minimum_required(VERSION 3.28)
project(naval_warfare)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(naval_warfare main.cpp
        ship.cpp
        ship.h
        gamefield.cpp
        gamefield.h
        ship_manager.cpp
        ship_manager.h
        shippart.cpp
        shippart.h
        cell.cpp
        cell.h
)