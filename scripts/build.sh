#!/bin/bash

set -e

WORKDIR="${HOME}/compass"

RELEASE_DIR="${WORKDIR}/release"
BUILD_DIR="${WORKDIR}/build"

BUILD_TYPE=$1

cmake -G -Ninja -DCMAKE_INSTALL_PREFIX=$REALEASE_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_SHARED_LIBS=TRUE -B $BUILD_DIR ..
cmake --build $BUILD_DIR
cmake --build $BUILD_DIR --target install