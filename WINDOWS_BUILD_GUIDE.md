# Building on Windows - Quick Guide

## You have 3 options to compile this project on Windows:

### ✅ **OPTION 1: Using MinGW/MSYS2 (Recommended)**

#### Step 1: Install MinGW-w64 or MSYS2
- **MSYS2** (Easiest): Download from https://www.msys2.org/
  - After installation, open "MSYS2 MINGW64" terminal
  - Run: `pacman -S mingw-w64-x86_64-gcc`
  
- **MinGW-w64**: Download from https://www.mingw-w64.org/downloads/
  - Choose installer and add to PATH

#### Step 2: Compile
Open PowerShell or Command Prompt in your project folder:

**Using the batch file:**
```cmd
build.bat
```

**Using PowerShell script:**
```powershell
.\build.ps1
```

**Manual compilation:**
```cmd
g++ -std=c++11 -Wall -Wextra main.cpp Menu.cpp BookingSystem.cpp Passenger.cpp Flight.cpp Utils.cpp -o pia_booking_system.exe
```

#### Step 3: Run
```cmd
pia_booking_system.exe
```

---

### ✅ **OPTION 2: Using Visual Studio**

#### Step 1: Install Visual Studio
- Download **Visual Studio Community** (free): https://visualstudio.microsoft.com/
- During installation, select "Desktop development with C++"

#### Step 2: Compile
Open "Developer Command Prompt for VS" (search in Start menu):

**Using the batch file:**
```cmd
build_vs.bat
```

**Manual compilation:**
```cmd
cl /EHsc /std:c++14 main.cpp Menu.cpp BookingSystem.cpp Passenger.cpp Flight.cpp Utils.cpp /Fe:pia_booking_system.exe
```

#### Step 3: Run
```cmd
pia_booking_system.exe
```

---

### ✅ **OPTION 3: Using Visual Studio IDE (GUI)**

1. **Create a new project:**
   - Open Visual Studio
   - Create New Project → Console App (C++)
   - Name it "PIA_Booking_System"

2. **Add files:**
   - Right-click project in Solution Explorer
   - Add → Existing Item
   - Select ALL .cpp and .h files

3. **Build and Run:**
   - Press F5 or click "Local Windows Debugger"

---

## 🔧 **Troubleshooting**

### "g++ is not recognized..."
- You need to install MinGW or MSYS2 (see Option 1)
- Make sure to add it to your PATH

### "cl is not recognized..."
- You need Visual Studio installed
- Use "Developer Command Prompt for VS" instead of regular Command Prompt

### "Cannot run scripts..." (PowerShell)
Run this in PowerShell as Administrator:
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

### Compilation errors
- Make sure all .cpp and .h files are in the same folder
- Check you're using C++11 or later

---

## 📝 **Quick Start for Beginners**

**If you've never compiled C++ on Windows:**

1. Install MSYS2: https://www.msys2.org/
2. Open "MSYS2 MINGW64" from Start menu
3. Install gcc: `pacman -S mingw-w64-x86_64-gcc`
4. Navigate to project folder: `cd /c/path/to/your/project`
5. Compile: `g++ -std=c++11 main.cpp Menu.cpp BookingSystem.cpp Passenger.cpp Flight.cpp Utils.cpp -o pia.exe`
6. Run: `./pia.exe`

---

## ✨ **After Building**

Run the program:
```cmd
pia_booking_system.exe
```

The program will create a `bookings.txt` file to store data between sessions.

---

## 📧 **Still Having Issues?**

Common fixes:
- Make sure all files are in the same directory
- Use the exact commands shown above
- Check that your compiler supports C++11
- Try the Visual Studio option if MinGW doesn't work
