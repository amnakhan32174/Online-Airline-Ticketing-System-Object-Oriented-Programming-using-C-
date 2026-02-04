#ifndef MENU_H
#define MENU_H

#include "BookingSystem.h"

/**
 * @brief Manages the main menu interface
 */
class Menu {
private:
    BookingSystem bookingSystem;
    
    void displayMainMenu() const;
    void handleUserChoice(int choice);
    
public:
    void run();
};

#endif // MENU_H
