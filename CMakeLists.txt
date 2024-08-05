cmake_minimum_required (VERSION 3.2)
project(Space_AI)

#设定CXX的标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#添加源文件到src_init GLOB是通配符模板名称
file(GLOB src_init ${CMAKE_CURRENT_SOURCE_DIR}/proc/*.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/com/*.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/task/*.cpp) 

set(current_hFile ${CMAKE_CURRENT_SOURCE_DIR}/include)

#添加需要include的h文件路径
include_directories(${current_hFile})
 
add_executable(Space_AI ${src_init})