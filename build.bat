@echo off
if not exist build (
    mkdir build
)
cd build
cmake ..
cmake --build .
cd ..
if exist transport.exe (
    transport.exe
)
pause
