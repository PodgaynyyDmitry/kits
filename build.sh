#!/bin/bash

BUILD_DIR="build"

if [ ! -d "$BUILD_DIR" ]; then
    echo "Создание каталога сборки: $BUILD_DIR"
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR" || { echo "Не удалось перейти в каталог $BUILD_DIR"; exit 1; }

echo "Запуск CMake..."
if ! cmake ..; then
    echo "Ошибка конфигурации CMake"
    exit 1
fi

echo "Сборка проекта..."
if ! cmake --build .; then
    echo "Ошибка сборки проекта"
    exit 1
fi

EXECUTABLE="transport"
if [ -f "$EXECUTABLE" ]; then
    echo "Запуск исполняемого файла:"
    ./"$EXECUTABLE"
else
    echo "Исполняемый файл не найден!"
fi
