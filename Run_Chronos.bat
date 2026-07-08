@echo off
title He Thong Quan Ly Nhiem Vu Chronos
echo Dang bien dich du an Chronos... Vui long doi...

:: Them src/Dashboard.cpp vao lenh bien dich
g++ -I include src/main.cpp src/Dashboard.cpp src/Date.cpp src/Task.cpp src/Project.cpp -o Chronos.exe

if %errorlevel% neq 0 (
    echo.
    echo [LOI] Bien dich that bai! Vui long kiem tra lai code.
    pause
    exit /b
)

cls
Chronos.exe
pauses