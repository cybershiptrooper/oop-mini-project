cmake_minimum_required(VERSION 3.10)
project(StoreManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(StoreManager PUBLIC "include")

add_executable(StoreManager 
	src/iowriter.cpp 
	src/customerWrapper.cpp
	src/customerParser.cpp
	src/customerManager.cpp
	
	src/displayManager.cpp
	src/adminServiceDM.cpp
	src/customerService.cpp
	src/customerServiceDM.cpp
	src/productManager.cpp
	src/productParser.cpp

	src/smProgram.cpp
	src/main.cpp)
	
add_executable(StoreManager_test  
	src/iowriter.cpp 
	src/customerWrapper.cpp
	src/customerParser.cpp
	src/customerManager.cpp
	src/productManager.cpp
	src/productParser.cpp
	tests/main.cpp)




