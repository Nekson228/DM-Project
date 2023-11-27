cmake_minimum_required(VERSION 3.25)
set(CMAKE_BUILD_TYPE Debug)
project(DM_Modules)

set(CMAKE_CXX_STANDARD 20)

add_executable(DM main.cpp
        modules/Natural/Natural.cpp
        modules/Natural/Natural.h
        modules/Integer/Integer.cpp
        modules/Integer/Integer.h
        modules/Polynomial/Polynomial.cpp
        modules/Polynomial/Polynomial.h
        modules/Rational/Rational.cpp
        modules/Rational/Rational.h
        modules/utils/utils.cpp
        modules/utils/utils.h
        modules/Interfaces/Model.h)
