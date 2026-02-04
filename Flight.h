#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Represents a single flight with basic details
 */
class Flight {
private:
    int serialNumber;
    int pricePerPerson;
    string departureTime;
    string destinationCity;

public:
    // Constructor
    Flight(int serial, int price, const string& time, const string& city);
    
    // Getters
    int getSerialNumber() const { return serialNumber; }
    int getPrice() const { return pricePerPerson; }
    string getDepartureTime() const { return departureTime; }
    string getDestinationCity() const { return destinationCity; }
    
    // Display flight information
    void displayFlightInfo() const;
};

/**
 * @brief Manages flight selection and pricing
 */
class FlightManager {
private:
    vector<Flight> availableFlights;
    int selectedFlightSerial;
    int selectedFlightPrice;
    
    void initializeFlights();
    
public:
    FlightManager();
    
    // Display all flights to a specific city
    void displayFlightsToCity(const string& city) const;
    
    // Select a flight for booking
    bool selectFlight(const string& city, int flightSerial);
    
    // Getters
    int getSelectedFlightPrice() const { return selectedFlightPrice; }
    int getSelectedFlightSerial() const { return selectedFlightSerial; }
    
    // Get all available destination cities
    vector<string> getAvailableCities() const;
};

#endif // FLIGHT_H
