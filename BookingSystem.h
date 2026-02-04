#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include "Passenger.h"
#include "Flight.h"
#include <set>
#include <string>

using namespace std;

/**
 * @brief Manages the entire booking system including reservations and waiting list
 */
class BookingSystem {
private:
    // Linked list for confirmed bookings (max 2 bookings initially)
    Passenger* confirmedBookingsHead;
    
    // Queue for waiting list
    Passenger* waitingListFront;
    Passenger* waitingListRear;
    
    // Booking management
    int totalBookingsCount;
    set<int> usedBookingCodes;
    FlightManager flightManager;
    
    // File persistence
    static const char* BOOKINGS_FILE;
    void saveToFile();
    void loadFromFile();
    
    // Helper methods
    int generateUniqueBookingCode();
    Passenger* findPassengerByBookingCode(int bookingCode);
    void addToConfirmedList(Passenger* passenger);
    void addToWaitingList(Passenger* passenger);
    float calculateTotalFare(int bookingCode);
    
public:
    BookingSystem();
    ~BookingSystem();
    
    // Core booking operations
    void createNewBooking();
    void viewBookingDetails();
    void modifyBooking();
    void cancelBooking();
    void processPayment();
    
    // Price and flight operations
    void calculateAndDisplayPrice();
    void displayAvailableCities() const;
    
    // Waiting list operations
    void displayWaitingList() const;
    void promoteFromWaitingList();
    
    // Statistics
    void displayBookingStatistics() const;
};

#endif // BOOKING_SYSTEM_H
