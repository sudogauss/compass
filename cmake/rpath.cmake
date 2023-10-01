################################################################################
## rpath

set(RPATH ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
  set(CMAKE_INSTALL_NAME_DIR ${RPATH})
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  set(CMAKE_INSTALL_RPATH ${RPATH}:${CMAKE_INSTALL_RPATH})
endif()
