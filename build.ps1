# PowerShell build script for PIA Booking System

Write-Host "====================================" -ForegroundColor Cyan
Write-Host "Building PIA Booking System..." -ForegroundColor Cyan
Write-Host "====================================" -ForegroundColor Cyan
Write-Host ""

# Check if g++ is available
$gppPath = Get-Command g++ -ErrorAction SilentlyContinue
if (-not $gppPath) {
    Write-Host "Error: g++ not found!" -ForegroundColor Red
    Write-Host ""
    Write-Host "Please install one of the following:" -ForegroundColor Yellow
    Write-Host "1. MinGW-w64: https://www.mingw-w64.org/downloads/" -ForegroundColor Yellow
    Write-Host "2. MSYS2: https://www.msys2.org/" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Or use Visual Studio and run: build_vs.bat" -ForegroundColor Yellow
    pause
    exit 1
}

Write-Host "Compiler found: $($gppPath.Source)" -ForegroundColor Green
Write-Host ""

# Compile source files
Write-Host "Compiling source files..." -ForegroundColor Yellow

$sourceFiles = @("main.cpp", "Menu.cpp", "BookingSystem.cpp", "Passenger.cpp", "Flight.cpp", "Utils.cpp")
$objectFiles = @()

foreach ($source in $sourceFiles) {
    $object = $source -replace '\.cpp$', '.o'
    Write-Host "  Compiling $source..." -NoNewline
    
    & g++ -std=c++11 -Wall -Wextra -c $source -o $object
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host " OK" -ForegroundColor Green
        $objectFiles += $object
    } else {
        Write-Host " FAILED" -ForegroundColor Red
        Write-Host ""
        Write-Host "Build failed!" -ForegroundColor Red
        pause
        exit 1
    }
}

# Link
Write-Host ""
Write-Host "Linking..." -ForegroundColor Yellow
& g++ -std=c++11 -o pia_booking_system.exe $objectFiles

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "====================================" -ForegroundColor Green
    Write-Host "Build successful!" -ForegroundColor Green
    Write-Host "Run: .\pia_booking_system.exe" -ForegroundColor Green
    Write-Host "====================================" -ForegroundColor Green
} else {
    Write-Host ""
    Write-Host "Linking failed!" -ForegroundColor Red
    pause
    exit 1
}

Write-Host ""
pause
