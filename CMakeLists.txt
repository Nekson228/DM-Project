cmake_minimum_required(VERSION 3.25)
project(DM)

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
        modules/Rational/src/Valeyeva_Alina_2384/Valeyeva_Alina.cpp
        modules/Integer/src/Valeyeva_Alina_2384/Valeyeva_Alina.cpp)
