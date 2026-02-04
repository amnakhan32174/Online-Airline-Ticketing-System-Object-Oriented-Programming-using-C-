#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using namespace std;

/**
 * @brief Represents a passenger with booking details
 */
class Passenger {
private:
    string name;
    string cnic;
    string gender;
    string bookingDate;
    string departureCity;
    string destinationCity;
    int age;
    int ticketSerialNumber;
    int bookingCode;
    float fare;
    Passenger* next; // For linked list implementation

public:
    // Constructor
    Passenger();
    Passenger(const string& passengerName, int passengerAge, 
              const string& passengerCnic, const string& passengerGender);
    
    // Setters
    void setName(const string& passengerName) { name = passengerName; }
    void setCnic(const string& passengerCnic) { cnic = passengerCnic; }
    void setGender(const string& passengerGender) { gender = passengerGender; }
    void setAge(int passengerAge) { age = passengerAge; }
    void setBookingDate(const string& date) { bookingDate = date; }
    void setDepartureCity(const string& city) { departureCity = city; }
    void setDestinationCity(const string& city) { destinationCity = city; }
    void setTicketSerialNumber(int serial) { ticketSerialNumber = serial; }
    void setBookingCode(int code) { bookingCode = code; }
    void setFare(float ticketFare) { fare = ticketFare; }
    void setNext(Passenger* nextPassenger) { next = nextPassenger; }
    
    // Getters
    string getName() const { return name; }
    string getCnic() const { return cnic; }
    string getGender() const { return gender; }
    int getAge() const { return age; }
    string getBookingDate() const { return bookingDate; }
    string getDepartureCity() const { return departureCity; }
    string getDestinationCity() const { return destinationCity; }
    int getTicketSerialNumber() const { return ticketSerialNumber; }
    int getBookingCode() const { return bookingCode; }
    float getFare() const { return fare; }
    Passenger* getNext() const { return next; }
    
    // Display passenger information
    void displayPassengerInfo() const;
    
    // Calculate fare with age-based discounts
    float calculateFareWithDiscount(float basePrice) const;
};

#endif // PASSENGER_H
