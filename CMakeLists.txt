cmake_minimum_required (VERSION 3.8)
 
project(IntN) 
 
#aux_source_directory(. SRC_LIST) 
 
set(IntN_SRC Main.cpp IntN.cpp IntN_Hori.cpp IntN_Vert.cpp Autotest.cpp) 
set(IntN_HDR IntN.h IntN_Hori.h IntN_Vert.h Factory.h Factory_Hori.h Factory_Vert.h Autotest.h) 
 
#add_executable(${PROJECT_NAME} ${SRC_LIST}) 
#add_library(vector STATIC ${IntN_SRC} ${IntN_HDR}) 
add_executable(${PROJECT_NAME} ${IntN_SRC} ${IntN_HDR}) 
 
#target_link_libraries(${PROJECT_NAME} intn) 
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 




