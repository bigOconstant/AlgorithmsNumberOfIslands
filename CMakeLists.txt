cmake_minimum_required(VERSION 3.0)

project(numberofislands)

add_executable(numberofislands main.cpp)

install(TARGETS numberofislands RUNTIME DESTINATION bin)
