
cmake_minimum_required(VERSION 3.29.6)
project(codeforces)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -O0")

file(GLOB SOURCES "problems/*.cpp")

foreach(FILENAME ${SOURCES})
	get_filename_component(EXEC_NAME FILENAME NAME_WE)
	add_executable(${EXEC_NAME} ${FILENAME})
endforeach()

