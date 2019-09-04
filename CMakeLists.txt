cmake_minimum_required(VERSION 3.0)

project(depeye CXX)

add_compile_options(-std=c++17)



aux_source_directory(src SRCS)

add_library(depeye ${SRCS})


add_executable(example example/main.cc)

target_link_libraries(example depeye)
target_link_libraries(example pthread)