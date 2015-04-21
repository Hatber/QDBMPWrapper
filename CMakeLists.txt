cmake_minimum_required(VERSION 2.8)
project(BMP)

add_subdirectory(bmp)
file(COPY ${CMAKE_SOURCE_DIR}/Examples/Tux.bmp DESTINATION ${PROJECT_BINARY_DIR}/Examples)

set(SOURCE_FILES main.cpp)
add_executable(BMP ${SOURCE_FILES})

target_link_libraries(BMP qdbmpWrapper)