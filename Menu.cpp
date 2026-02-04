#include "Menu.h"
#include "Utils.h"
#include <iostream>

using namespace std;

void Menu::displayMainMenu() const {
    cout << "\n\n";
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                                                            ║" << endl;
    cout << "║        PAKISTAN INTERNATIONAL AIRLINES (PIA)               ║" << endl;
    cout << "║            Flight Booking Management System                ║" << endl;
    cout << "║                                                            ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << "\n";
    cout << "┌────────────────────────────────────────────────────────────┐" << endl;
    cout << "│  1. Create New Booking                                     │" << endl;
    cout << "│  2. View Booking Details                                   │" << endl;
    cout << "│  3. Calculate Price                                        │" << endl;
    cout << "│  4. Modify Booking                                         │" << endl;
    cout << "│  5. Process Payment                                        │" << endl;
    cout << "│  6. Cancel Booking                                         │" << endl;
    cout << "│  7. View Waiting List                                      │" << endl;
    cout << "│  8. Available Destinations                                 │" << endl;
    cout << "│  9. Booking Statistics                                     │" << endl;
    cout << "│  0. Exit                                                   │" << endl;
    cout << "└────────────────────────────────────────────────────────────┘" << endl;
    cout << "\nEnter your choice: ";
}

void Menu::handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            bookingSystem.createNewBooking();
            break;
            
        case 2:
            bookingSystem.viewBookingDetails();
            break;
            
        case 3:
            bookingSystem.calculateAndDisplayPrice();
            break;
            
        case 4:
            bookingSystem.modifyBooking();
            break;
            
        case 5:
            bookingSystem.processPayment();
            break;
            
        case 6:
            bookingSystem.cancelBooking();
            break;
            
        case 7:
            bookingSystem.displayWaitingList();
            break;
            
        case 8:
            bookingSystem.displayAvailableCities();
            break;
            
        case 9:
            bookingSystem.displayBookingStatistics();
            break;
            
        case 0:
            cout << "\n╔════════════════════════════════════════════════════╗" << endl;
            cout << "║  Thank you for using PIA Booking System!          ║" << endl;
            cout << "║  Have a safe journey!                             ║" << endl;
            cout << "╚════════════════════════════════════════════════════╝" << endl;
            break;
            
        default:
            cout << "\n✗ Invalid choice. Please try again." << endl;
            break;
    }
    
    if (choice != 0) {
        cout << "\n";
        displayDivider();
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
}

void Menu::run() {
    int choice;
    
    do {
        displayMainMenu();
        cin >> choice;
        handleUserChoice(choice);
    } while (choice != 0);
}
