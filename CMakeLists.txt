cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(FromHeLL VERSION 0.0.0)

file( GLOB_RECURSE SRC_FILE src/*.c*)

add_executable(FromHeLL ${SRC_FILE})
target_include_directories(FromHeLL PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(FromHeLL PUBLIC dl glfw)