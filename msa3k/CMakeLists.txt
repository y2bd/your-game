# MSA3K

cmake_minimum_required (VERSION 2.8)
project(msa3k)

set(ALLEGRO5_INCLUDE_DIR /usr/include)
set(ALLEGRO5_LIBRARIES /usr/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")
find_package(Allegro)

set(CMAKE_CXX_FLAGS "-Wall -g -ansi")
add_subdirectory(src)
