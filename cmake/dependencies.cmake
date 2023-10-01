################################################################################
## dependencies

if(BUILD_BENCHMARKS)
  find_package(benchmark QUIET)
endif()

find_package(Boost REQUIRED COMPONENTS date_time filesystem graph system thread program_options)

if(ENABLE_TESTING)
  find_package(GTest QUIET)
endif()

find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)
find_package(Threads REQUIRED)

# By default gcc links executable with lib rt (but not for previous versions). Only UNIX systems (except APPLE) have lib rt.
if(UNIX AND NOT APPLE)
  find_library(LIB_RT rt)
endif()

################################################################################
## additional configuration

add_definitions(-DBOOST_ASIO_NO_DEPRECATED)

if(MSVC)
  add_definitions(-DBOOST_ALL_NO_LIB)
endif()
