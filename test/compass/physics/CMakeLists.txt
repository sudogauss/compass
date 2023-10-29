# Copyright (C) sudogauss - All Rights Reserved
# Unauthorized copying of this file, via any medium is strictly prohibited
# Proprietary
# Written by sudogauss

set(CONVERT_TEST ${PROJECT_NAME}-physics-convert-units-test)

add_executable(${CONVERT_TEST} convert_units_test.cpp)
set_target_properties(${CONVERT_TEST} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/test")
target_link_libraries(
    ${CONVERT_TEST}
    PRIVATE
    ${PROJECT_NAME}::physics
    GTest::GTest
    Boost::math
)

add_test(NAME ${CONVERT_TEST} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/text COMMAND ${CONVERT_TEST})