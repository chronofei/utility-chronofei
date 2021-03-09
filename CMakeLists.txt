project(utility-chronofei)

cmake_minimum_required(VERSION 2.6)

# find_package(EXAMPLE REQUIRED)

include_directories(
	include
)

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
if (COMPILER_SUPPORTS_CXX11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

add_executable(readCSV src/readCSV.cpp)
# target_link_libraries(readCSV ${EXAMPLE_LIBRARIES})

add_executable(convert src/convert.cpp)
