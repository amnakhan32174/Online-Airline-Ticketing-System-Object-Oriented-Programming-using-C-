@echo off
REM Build script for PIA Booking System (Windows)

echo ====================================
echo Building PIA Booking System...
echo ====================================
echo.

REM Check if g++ is available
where g++ >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo Error: g++ not found. Please install MinGW or use Visual Studio.
    echo.
    echo Option 1: Install MinGW from https://www.mingw-w64.org/
    echo Option 2: Use build_vs.bat for Visual Studio
    pause
    exit /b 1
)

REM Compile all source files
echo Compiling source files...
g++ -std=c++11 -Wall -Wextra -c main.cpp -o main.o
if %ERRORLEVEL% NEQ 0 goto :error

g++ -std=c++11 -Wall -Wextra -c Menu.cpp -o Menu.o
if %ERRORLEVEL% NEQ 0 goto :error

g++ -std=c++11 -Wall -Wextra -c BookingSystem.cpp -o BookingSystem.o
if %ERRORLEVEL% NEQ 0 goto :error

g++ -std=c++11 -Wall -Wextra -c Passenger.cpp -o Passenger.o
if %ERRORLEVEL% NEQ 0 goto :error

g++ -std=c++11 -Wall -Wextra -c Flight.cpp -o Flight.o
if %ERRORLEVEL% NEQ 0 goto :error

g++ -std=c++11 -Wall -Wextra -c Utils.cpp -o Utils.o
if %ERRORLEVEL% NEQ 0 goto :error

REM Link object files
echo.
echo Linking...
g++ -std=c++11 -o pia_booking_system.exe main.o Menu.o BookingSystem.o Passenger.o Flight.o Utils.o
if %ERRORLEVEL% NEQ 0 goto :error

echo.
echo ====================================
echo Build successful!
echo Run: pia_booking_system.exe
echo ====================================
goto :end

:error
echo.
echo ====================================
echo Build failed!
echo ====================================
pause
exit /b 1

:end
pause
