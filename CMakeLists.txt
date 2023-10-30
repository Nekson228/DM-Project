cmake_minimum_required(VERSION 3.25)
project(DM)

set(CMAKE_CXX_STANDARD 20)

add_executable(DM main.cpp modules/Integer/Integer.h modules/Natural/Natural.h modules/Natural/Natural.cpp modules/Integer/Integer.cpp modules/Polynomial/Polynomial.cpp modules/Polynomial/Polynomial.h modules/Rational/Rational.cpp modules/Rational/Rational.h modules/Natural/src/Gurkov_Arseniy/Gurkov_Arseniy.cpp modules/Natural/src/Gurkov_Arseniy/Gurkov_Arseniy_test.cpp)
