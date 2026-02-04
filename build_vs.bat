@echo off
REM Build script for PIA Booking System using Visual Studio compiler

echo ====================================
echo Building PIA Booking System (MSVC)
echo ====================================
echo.

REM Check if cl is available
where cl >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo Error: Visual Studio compiler not found.
    echo Please run this from "Developer Command Prompt for VS"
    echo Or install Visual Studio Build Tools
    pause
    exit /b 1
)

echo Compiling with Visual Studio compiler...
cl /EHsc /std:c++14 /W4 /Fe:pia_booking_system.exe main.cpp Menu.cpp BookingSystem.cpp Passenger.cpp Flight.cpp Utils.cpp

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ====================================
    echo Build failed!
    echo ====================================
    pause
    exit /b 1
)

echo.
echo ====================================
echo Build successful!
echo Run: pia_booking_system.exe
echo ====================================
pause
