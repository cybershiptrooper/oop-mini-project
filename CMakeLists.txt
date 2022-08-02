cmake_minimum_required(VERSION 3.10)
project(StoreManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(StoreManager PUBLIC "include")

add_executable(StoreManager src/main.cpp)
add_executable(StoreManager_test  tests/main.cpp)
