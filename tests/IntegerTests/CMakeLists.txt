cmake_minimum_required(VERSION 3.25)
project(DM_IntegerTests)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(../googletest googletest)
add_executable(IntegerTests tests.cpp
        ../../modules/Natural/Natural.h ../../modules/Natural/Natural.cpp
        ../../modules/Integer/Integer.h ../../modules/Integer/Integer.cpp
        ../../modules/utils/utils.h ../../modules/utils/utils.cpp)

target_link_libraries(IntegerTests gtest_main)
