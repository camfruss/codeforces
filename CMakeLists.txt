
cmake_minimum_required(VERSION 3.29.6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")

add_compile_options(-fmodules -fbuiltin-module-map)
enable_testing()

project(codeforces
		LANGUAGES CXX
)

file(GLOB SOURCES "problems/*.cpp")

foreach(FILENAME ${SOURCES})
	get_filename_component(EXEC_NAME ${FILENAME} NAME_WE)
	add_executable(${EXEC_NAME} ${FILENAME})
endforeach()

# add_library(core)
# target_sources(core
#	PUBLIC 
#	FILE_SET CXX_MODULES TYPE CXX_MODULES FILES
#		problems/solutions.cppm
#		problems/1802B.cppm
# )
# add_executable(codeforces problems/main.cpp)
# target_link_libraries(codeforces PRIVATE core)

