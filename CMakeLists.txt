cmake_minimum_required(VERSION 3.15)

project(varcov)

string(APPEND CMAKE_CXX_FLAGS " -Wall")
string(APPEND CMAKE_CXX_FLAGS " -Werror")
#string(APPEND CMAKE_CXX_FLAGS " -std=c++20")
#string(APPEND CMAKE_CXX_FLAGS " -lsqlite3")

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


