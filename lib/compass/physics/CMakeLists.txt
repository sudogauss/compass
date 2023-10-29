# Copyright (C) sudogauss - All Rights Reserved
# Unauthorized copying of this file, via any medium is strictly prohibited
# Proprietary
# Written by sudogauss

set(LIB_NAME "${PROJECT_NAME}-physics")
file(GLOB_RECURSE HEADERS *.hpp *.h)

add_library(${LIB_NAME} ${HEADERS})
add_library(compass::physics ALIAS ${LIB_NAME})

target_include_directories(
    ${LIB_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/lib>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include/>
)
target_link_libraries(
    ${LIB_NAME}
    INTERFACE
    Boost::math
)

install(TARGETS ${LIB_NAME}
  EXPORT ${CMAKE_PACKAGE_TARGETS}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install_headers("${HEADERS}" "${CMAKE_INSTALL_INCLUDEDIR}")