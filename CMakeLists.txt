cmake_minimum_required(VERSION 3.15)
project(data_structures)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE includes include/*.h)

add_executable(urt_streamer ${includes} ${sources} )
