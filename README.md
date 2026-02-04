# Pakistan International Airlines (PIA) Flight Booking System

## Overview
A comprehensive flight booking management system built with C++ that demonstrates object-oriented programming principles, data structures, and software engineering best practices.

## Features

### Core Functionality
- **Flight Booking**: Book tickets for multiple passengers with automatic seat allocation
- **Waiting List Management**: Queue-based system for managing excess bookings
- **Price Calculation**: Automatic fare calculation with age-based discounts:
  - 50% discount for children (0-6 years)
  - 30% discount for children (7-12 years)
  - 20% discount for senior citizens (60+ years)
- **Payment Processing**: Secure payment confirmation system
- **Booking Modification**: Edit passenger details for existing bookings
- **Booking Cancellation**: Cancel bookings with automatic waiting list promotion

### Technical Features
- **File Persistence**: All bookings are saved to disk and restored on startup
- **Input Validation**: Comprehensive validation for dates, CNIC, cities, and flights
- **Data Structures**:
  - Linked list for confirmed bookings
  - Queue for waiting list management
  - Set for unique booking code generation
- **Object-Oriented Design**: Proper encapsulation, separation of concerns, and modularity

## Project Structure

```
pia-booking-system/
├── main.cpp              # Entry point
├── Menu.h/cpp            # User interface and menu system
├── BookingSystem.h/cpp   # Core booking logic and data management
├── Passenger.h/cpp       # Passenger data and operations
├── Flight.h/cpp          # Flight information and selection
├── Utils.h/cpp           # Utility functions (validation, formatting)
├── Makefile              # Build configuration
└── README.md             # This file
```

## Building and Running

### Prerequisites
- C++ compiler with C++11 support (g++, clang++, or MSVC)
- Make (optional, for using Makefile)

### Using Makefile (Linux/macOS/MinGW)
```bash
# Build the project
make

# Build and run
make run

# Clean build files
make clean

# Rebuild from scratch
make rebuild
```

### Manual Compilation
```bash
# Compile all source files
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp Menu.cpp BookingSystem.cpp Passenger.cpp Flight.cpp Utils.cpp -o pia_booking_system

# Run the program
./pia_booking_system
```

### Windows (Visual Studio)
```cmd
cl /EHsc /std:c++11 main.cpp Menu.cpp BookingSystem.cpp Passenger.cpp Flight.cpp Utils.cpp /Fe:pia_booking_system.exe
```

## Usage Guide

### 1. Create New Booking
- Select departure and destination cities
- Choose travel date (up to 30 days in advance)
- Select from available flights
- Enter passenger details (name, age, gender, CNIC)
- Receive unique booking code

### 2. View Booking Details
- Enter booking code
- View complete ticket information for all passengers

### 3. Calculate Price
- Enter booking code
- See itemized fare breakdown
- View total amount due

### 4. Modify Booking
- Enter booking code and passenger serial number
- Update passenger name, age, or gender

### 5. Process Payment
- Enter booking code and CNIC for verification
- Pay the total fare amount
- Receive confirmation

### 6. Cancel Booking
- Enter booking code
- Booking is removed and waiting list is promoted automatically

### 7. View Waiting List
- See all passengers currently on the waiting list
- Displayed in queue order

### 8. View Statistics
- Current confirmed bookings
- Waiting list count
- Available seats

## Available Routes

The system supports flights between the following Pakistani cities:
- Karachi
- Lahore
- Islamabad
- Peshawar
- Quetta

Multiple flights available per route with different times and prices.

## Technical Highlights

### Object-Oriented Design
- **Encapsulation**: Private data members with public accessor methods
- **Separation of Concerns**: Each class has a single, well-defined responsibility
- **Modularity**: Code organized into logical, reusable components

### Data Structures
- **Linked List**: Efficient insertion and deletion for bookings
- **Queue**: FIFO processing for waiting list
- **Set**: O(log n) lookup for unique booking codes

### Best Practices
- Const-correctness for read-only methods
- Memory management with proper destructors
- File I/O error handling
- Input validation at multiple levels
- Clear naming conventions
- Comprehensive code comments

## Future Enhancements

Potential improvements for this project:
1. **Database Integration**: Replace file storage with SQL database
2. **User Authentication**: Add user accounts with login system
3. **Email Notifications**: Send booking confirmations via email
4. **Payment Gateway**: Integrate online payment processing
5. **GUI Interface**: Develop Qt or web-based interface
6. **Multi-threading**: Handle concurrent bookings
7. **Reporting**: Generate sales and booking reports
8. **Dynamic Pricing**: Implement surge pricing based on demand
9. **Seat Selection**: Allow passengers to choose specific seats
10. **International Routes**: Add international flight support

## License
This project is created for educational purposes.

## Author
[Your Name]
Semester 3 OOP Project
[Your University]

## Acknowledgments
- Original concept developed as part of Object-Oriented Programming course
- Enhanced with modern C++ practices and professional software engineering principles
