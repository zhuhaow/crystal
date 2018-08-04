cmake_minimum_required(VERSION 3.2.0)

project(crystal CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)


cmake_policy(SET CMP0063 NEW)
add_library(crystal INTERFACE)

set(CMAKE_PREFIX_PATH "/usr/local/opt/openblas/lib/cmake" ${CMAKE_PREFIX_PATH})
find_package(OPENBLAS REQUIRED)
if (NOT OPENBLAS_FOUND)
  message(FATAL_ERROR "BLAS is required")
else()
  message("Using BLAS: ${OpenBLAS_LIBRARIES}")
endif()
target_link_libraries(crystal INTERFACE ${OpenBLAS_LIBRARIES})

find_package(OpenMP REQUIRED)
target_link_libraries(crystal INTERFACE OpenMP::OpenMP_CXX)

include(CheckCXXCompilerFlag)

target_include_directories(crystal INTERFACE "include")
target_include_directories(crystal INTERFACE ${OpenBLAS_INCLUDE_DIRS})
