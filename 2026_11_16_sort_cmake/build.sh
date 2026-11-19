#!/bin/sh

#
# Вид сборки / суффикс в названии каталога сборки
#
# "Ninja" / "ninja"
# "Visual Studio 17 2022" / "visual_studio"
#
BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

set -e

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="src"

mkdir -p "$BUILD_FOLDER"

cd "$BUILD_FOLDER"

cmake -G "$BUILD_TYPE" "../${SOURCE_FOLDER}"
cmake --build .

cd ..