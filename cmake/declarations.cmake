################################################################################
## global declarations

set(PROJECT_VENDOR "sudogauss")
set(PROJECT_DESCRIPTION "Path finding library")
set(CMAKE_PACKAGE_NAME "${PROJECT_NAME}")
set(CMAKE_PACKAGE_TARGETS "${CMAKE_PACKAGE_NAME}Targets")
set(LIBVERSION ${PROJECT_VERSION_MAJOR})
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(EXPORT_COMPILE_COMMANDS ON)

################################################################################
## CXX declarations

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
