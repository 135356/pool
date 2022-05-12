cmake_minimum_required(VERSION 3.17)
project(bb)
set(CMAKE_CXX_STANDARD 14)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build/lib)

include_directories(include)
add_executable(main main.cpp)

find_library(bb bb ${CMAKE_BINARY_DIR}/build/lib)
target_link_libraries(main ${bb})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(Threads)
    target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
endif()