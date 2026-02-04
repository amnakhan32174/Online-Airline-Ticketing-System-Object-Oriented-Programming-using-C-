#include "Passenger.h"
#include <iostream>
#include <iomanip>

Passenger::Passenger() 
    : age(0), ticketSerialNumber(0), bookingCode(0), 
      fare(0.0f), next(nullptr) {}

Passenger::Passenger(const string& passengerName, int passengerAge, 
                     const string& passengerCnic, const string& passengerGender)
    : name(passengerName), cnic(passengerCnic), gender(passengerGender),
      age(passengerAge), ticketSerialNumber(0), bookingCode(0), 
      fare(0.0f), next(nullptr) {}

void Passenger::displayPassengerInfo() const {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║ PASSENGER TICKET DETAILS                                      ║" << endl;
    cout << "╠═══════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ Serial No:        S-" << left << setw(42) << ticketSerialNumber << "║" << endl;
    cout << "║ Passenger Name:   " << left << setw(43) << name << "║" << endl;
    cout << "║ Age:              " << left << setw(43) << age << "║" << endl;
    cout << "║ Gender:           " << left << setw(43) << gender << "║" << endl;
    cout << "║ CNIC:             " << left << setw(43) << cnic << "║" << endl;
    cout << "║ Booking Date:     " << left << setw(43) << bookingDate << "║" << endl;
    cout << "║ From:             " << left << setw(43) << departureCity << "║" << endl;
    cout << "║ To:               " << left << setw(43) << destinationCity << "║" << endl;
    cout << "║ Fare:             Rs." << left << setw(40) << fixed << setprecision(2) << fare << "║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════════╝" << endl;
}

float Passenger::calculateFareWithDiscount(float basePrice) const {
    float discount = 0.0f;
    
    if (age >= 1 && age <= 6) {
        discount = 0.5f; // 50% discount for children 0-6
    } else if (age > 6 && age <= 12) {
        discount = 0.3f; // 30% discount for children 7-12
    } else if (age >= 60) {
        discount = 0.2f; // 20% discount for senior citizens
    }
    
    return basePrice * (1.0f - discount);
}
