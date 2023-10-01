################################################################################
## benchmark

if(NOT benchmark_FOUND)
  if(NOT TARGET benchmark::benchmark)
    FetchContent_Declare(
      benchmark
      GIT_REPOSITORY "https://github.com/google/benchmark.git"
      GIT_TAG "v1.6.0"
      CMAKE_ARGS "-DBENCHMARK_ENABLE_TESTING=OFF"
      UPDATE_DISCONNECTED TRUE)
    FetchContent_GetProperties(benchmark)
    if(NOT benchmark_POPULATED)
      FetchContent_Populate(benchmark)
      add_subdirectory(${benchmark_SOURCE_DIR} ${benchmark_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
  endif()
endif()
