cmake_minimum_required(VERSION 3.10)
project(StoreManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(StoreManager PUBLIC "include")

add_executable(StoreManager 
	src/iowriter.cpp 
	src/customerWrapper.cpp
	src/customerParser.cpp
	src/customerManager.cpp
	src/smprogram.cpp
	src/adminServiceDM.cpp
	src/customerServiceDM.cpp
	src/main.cpp)
	
add_executable(StoreManager_test  
	src/iowriter.cpp 
	src/customerWrapper.cpp
	src/customerParser.cpp
	src/customerManager.cpp
	tests/main.cpp)
