cmake_minimum_required(VERSION 3.22)
project(test_static_shared)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(log_facade)
add_subdirectory(shrd_lib)

add_executable(test_static_shared main.cpp)
target_link_libraries(test_static_shared PUBLIC log_facade shrd_lib )
