cmake_minimum_required(VERSION 3.10)
project(StoreManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(StoreManager PUBLIC "include")

set(CMAKE_BUILD_TYPE Debug)

add_executable(StoreManager 
	src/iowriter.cpp 
	src/customerWrapper.cpp
	
	src/managers/customerManager.cpp
	src/managers/productManager.cpp
	src/managers/orderItemManager.cpp

	src/parsers/customerParser.cpp
	src/parsers/orderItemParser.cpp
	src/parsers/productParser.cpp

	src/DM/displayManager.cpp
	src/DM/adminServiceDM.cpp
	src/DM/customerServiceDM.cpp
	
	src/services/customerService.cpp
	src/services/frontendService.cpp
	src/services/adminService.cpp
	src/services/backendService.cpp
	src/cart.cpp

	src/smProgram.cpp
	src/main.cpp)
	
add_executable(StoreManager_test  
	src/iowriter.cpp 
	src/customerWrapper.cpp
	
	src/managers/customerManager.cpp
	src/managers/productManager.cpp
	src/managers/orderItemManager.cpp

	src/parsers/customerParser.cpp
	src/parsers/orderItemParser.cpp
	src/parsers/productParser.cpp

	src/DM/displayManager.cpp
	src/DM/adminServiceDM.cpp
	src/DM/customerServiceDM.cpp
	
	src/services/customerService.cpp
	src/services/frontendService.cpp
	src/services/adminService.cpp
	src/services/backendService.cpp
	src/cart.cpp
	tests/main.cpp)




