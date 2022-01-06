cmake_minimum_required(VERSION 3.21)
project(virtualfriends)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR C:/Users/abdul.wasay/boost_1_55_0/boost_1_55_0)
set(Boost_LIBRARY_DIR C:/Users/abdul.wasay/boost_1_55_0/boost_1_55_0/libs)
find_package(Boost 1.55.0)
include_directories(${Boost_INCLUDE_DIR})

add_executable(virtualfriends main.cpp)
