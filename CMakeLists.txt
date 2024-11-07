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
        ability.cpp
        ability.h
        double_damage.cpp
        double_damage.h
        scanner.cpp
        scanner.h
        bombard.cpp
        bombard.h
        ability_manager.cpp
        ability_manager.h
        exceptions/invalid_ability_usage.cpp
        exceptions/invalid_ability_usage.h
        exceptions/ship_placement_error.cpp
        exceptions/ship_placement_error.h
        exceptions/attack_out_of_bound.cpp
        exceptions/attack_out_of_bound.h
)