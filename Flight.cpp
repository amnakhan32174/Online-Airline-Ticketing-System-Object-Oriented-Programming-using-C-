#include "Flight.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>

// Flight class implementation
Flight::Flight(int serial, int price, const string& time, const string& city)
    : serialNumber(serial), pricePerPerson(price), 
      departureTime(time), destinationCity(city) {}

void Flight::displayFlightInfo() const {
    cout << "  PA-" << serialNumber 
         << " | Time: " << departureTime 
         << " | Price: Rs." << pricePerPerson << " per person" << endl;
}

// FlightManager class implementation
FlightManager::FlightManager() : selectedFlightSerial(0), selectedFlightPrice(0) {
    initializeFlights();
}

void FlightManager::initializeFlights() {
    availableFlights = {
        Flight(101, 12000, "05:00 PM", "Lahore"),
        Flight(102, 10000, "12:00 AM", "Lahore"),
        Flight(103, 15000, "08:00 PM", "Lahore"),
        
        Flight(122, 11000, "03:00 PM", "Karachi"),
        Flight(123, 14000, "07:00 PM", "Karachi"),
        Flight(124, 10000, "02:00 AM", "Karachi"),
        
        Flight(131, 12000, "04:00 PM", "Islamabad"),
        Flight(132, 13500, "09:00 PM", "Islamabad"),
        Flight(133, 9000, "02:00 AM", "Islamabad"),
        
        Flight(241, 12500, "05:00 PM", "Peshawar"),
        Flight(242, 14000, "06:00 PM", "Peshawar"),
        Flight(243, 12000, "01:00 AM", "Peshawar"),
        
        Flight(501, 16000, "04:00 AM", "Quetta"),
        Flight(502, 16500, "03:00 PM", "Quetta"),
        Flight(503, 13500, "06:00 AM", "Quetta")
    };
}

void FlightManager::displayFlightsToCity(const string& city) const {
    string cityLower = toLower(city);
    bool found = false;
    
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "  Available Flights to " << city << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    
    for (const auto& flight : availableFlights) {
        if (toLower(flight.getDestinationCity()) == cityLower) {
            flight.displayFlightInfo();
            found = true;
        }
    }
    
    if (!found) {
        cout << "  No flights available to " << city << endl;
    }
}

bool FlightManager::selectFlight(const string& city, int flightSerial) {
    string cityLower = toLower(city);
    
    for (const auto& flight : availableFlights) {
        if (toLower(flight.getDestinationCity()) == cityLower && 
            flight.getSerialNumber() == flightSerial) {
            selectedFlightSerial = flight.getSerialNumber();
            selectedFlightPrice = flight.getPrice();
            return true;
        }
    }
    
    return false;
}

vector<string> FlightManager::getAvailableCities() const {
    vector<string> cities;
    for (const auto& flight : availableFlights) {
        string city = flight.getDestinationCity();
        if (find(cities.begin(), cities.end(), city) == cities.end()) {
            cities.push_back(city);
        }
    }
    return cities;
}
