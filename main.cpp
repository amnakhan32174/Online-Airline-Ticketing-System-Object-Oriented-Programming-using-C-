/**
 * @file main.cpp
 * @brief Pakistan International Airlines (PIA) Flight Booking System
 * @author Your Name
 * @date 2024
 * 
 * This is an airline management system that allows users to:
 * - Book flight tickets with automatic waiting list management
 * - View and modify bookings
 * - Calculate fares with age-based discounts
 * - Process payments
 * - Manage flight schedules
 * 
 * Features:
 * - Object-oriented design with proper encapsulation
 * - File persistence for booking data
 * - Linked list for confirmed bookings
 * - Queue implementation for waiting list
 * - Input validation and error handling
 */

#include "Menu.h"
#include <iostream>

#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS
#endif

int main() {
    try {
        Menu menu;
        menu.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
