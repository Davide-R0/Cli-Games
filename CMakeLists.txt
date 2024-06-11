cmake_minimum_required(VERSION 3.10)

# set the project name and version 
set(app_name "CliGame")
project(${app_name} VERSION 1.0 LANGUAGES C CXX)

# specify the C++ standard (ricontrollare la versione minima)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)  #?????
