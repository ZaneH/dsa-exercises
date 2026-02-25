default:
  @just --list

setup:
  @cmake -S . -B build/Debug -DCMAKE_BUILD_TYPE=Debug -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
  @cmake -S . -B build/Release -DCMAKE_BUILD_TYPE=Release -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

build:
  @cmake --build build/Debug

build-release:
  @cmake --build build/Release

test: build
  @ctest --test-dir build/Debug
