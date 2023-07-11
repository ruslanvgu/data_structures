cmake_minimum_required(VERSION 3.15)
project(data_structures)

include_directories(include) #для того чтобы src файлы видели header
file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE includes include/*.h)

add_executable(data_structures ${includes} ${sources})
