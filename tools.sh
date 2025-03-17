#!/bin/bash

BUILD_DIR="build"
EXECUTABLE="tempo"

usage() {
  echo "Usage: $0 generate | build | run"
  exit 1
}

generate() {
  cmake -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
}

build() {
  cmake --build $BUILD_DIR --parallel $(nproc)
}

run() {
  ./build/bin/$EXECUTABLE
}

case "$1" in
  generate)
    generate
    ;;
  build)
    build
    ;;
  run)
    run
    ;;
  *)
    usage
    ;;
esac
