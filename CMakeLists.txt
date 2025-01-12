cmake_minimum_required(VERSION 3.15)

project(varcov)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

string(APPEND CMAKE_CXX_FLAGS " -Wall")
string(APPEND CMAKE_CXX_FLAGS " -Werror")
#string(APPEND CMAKE_CXX_FLAGS " -std=c++20")
#string(APPEND CMAKE_CXX_FLAGS " -lsqlite3")

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(csv-parser)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
 

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} Eigen3::Eigen)
target_link_libraries (${PROJECT_NAME} csv)
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


