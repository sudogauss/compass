################################################################################
## read version

file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/VERSION current_version)

################################################################################
## general information

cmake_minimum_required(VERSION 3.8)
project(compass VERSION ${current_version} LANGUAGES CXX)

################################################################################
## install destinations

include(GNUInstallDirs)

################################################################################
## CMake third-party files

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/third-party")

################################################################################
## CMake compiler and declarations

include(cmake/declarations.cmake)
include(cmake/extra_flags.cmake)
include(cmake/toolchain.cmake)
include(cmake/ccache.cmake)

################################################################################
## CMake utils functions

include(cmake/functions.cmake)

################################################################################
## CMake options and dependencies

include(cmake/dependencies.cmake)
include(cmake/options.cmake)

################################################################################
## CMake other configuration

if(NOT STATIC_LIBSTDCXX AND NOT CMAKE_CROSSCOMPILING)
  include(cmake/rpath.cmake)
endif()

if(ENABLE_TESTING)
  include(cmake/test.cmake)
endif()

if(ENABLE_CLANG_TIDY)
  include(cmake/clang-tidy.cmake)
endif()

if(ENABLE_CPPCHECK)
  include(cmake/cppcheck.cmake)
endif()

################################################################################
## process subdirectories

add_subdirectory(external)
add_subdirectory(lib)

if(BUILD_BENCHMARKS)
  add_subdirectory(benchmark)
endif()
if(BUILD_EXAMPLES)
  add_subdirectory(example)
endif()
if(ENABLE_TESTING)
  add_subdirectory(test)
endif()

################################################################################
## print summary

include(cmake/summary.cmake)
