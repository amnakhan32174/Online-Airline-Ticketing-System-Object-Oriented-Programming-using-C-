#include "BookingSystem.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

const char* BookingSystem::BOOKINGS_FILE = "bookings.txt";

BookingSystem::BookingSystem() 
    : confirmedBookingsHead(nullptr), waitingListFront(nullptr), 
      waitingListRear(nullptr), totalBookingsCount(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
    loadFromFile();
}

BookingSystem::~BookingSystem() {
    saveToFile();
    
    // Clean up confirmed bookings
    while (confirmedBookingsHead != nullptr) {
        Passenger* temp = confirmedBookingsHead;
        confirmedBookingsHead = confirmedBookingsHead->getNext();
        delete temp;
    }
    
    // Clean up waiting list
    while (waitingListFront != nullptr) {
        Passenger* temp = waitingListFront;
        waitingListFront = waitingListFront->getNext();
        delete temp;
    }
}

int BookingSystem::generateUniqueBookingCode() {
    int code;
    do {
        code = 10000 + (rand() % 90000); // 5-digit code
    } while (usedBookingCodes.count(code));
    
    usedBookingCodes.insert(code);
    return code;
}

void BookingSystem::addToConfirmedList(Passenger* passenger) {
    if (confirmedBookingsHead == nullptr) {
        confirmedBookingsHead = passenger;
    } else {
        Passenger* current = confirmedBookingsHead;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(passenger);
    }
}

void BookingSystem::addToWaitingList(Passenger* passenger) {
    if (waitingListFront == nullptr) {
        waitingListFront = waitingListRear = passenger;
    } else {
        waitingListRear->setNext(passenger);
        waitingListRear = passenger;
    }
}

Passenger* BookingSystem::findPassengerByBookingCode(int bookingCode) {
    // Search in confirmed bookings
    Passenger* current = confirmedBookingsHead;
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            return current;
        }
        current = current->getNext();
    }
    
    // Search in waiting list
    current = waitingListFront;
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            return current;
        }
        current = current->getNext();
    }
    
    return nullptr;
}

void BookingSystem::saveToFile() {
    ofstream outFile(BOOKINGS_FILE);
    if (!outFile) {
        cerr << "Error: Could not save bookings to file." << endl;
        return;
    }
    
    // Save booking codes
    outFile << "BOOKING_CODES";
    for (int code : usedBookingCodes) {
        outFile << " " << code;
    }
    outFile << "\n";
    
    // Save confirmed bookings
    outFile << "CONFIRMED\n";
    int count = 0;
    for (Passenger* p = confirmedBookingsHead; p != nullptr; p = p->getNext()) {
        count++;
    }
    outFile << count << "\n";
    
    for (Passenger* p = confirmedBookingsHead; p != nullptr; p = p->getNext()) {
        outFile << p->getName() << "|" << p->getBookingDate() << "|" 
                << p->getDepartureCity() << "|" << p->getDestinationCity() << "|"
                << p->getGender() << "|" << p->getCnic() << "|" << p->getAge() << "|"
                << p->getBookingCode() << "|" << p->getTicketSerialNumber() << "|"
                << p->getFare() << "\n";
    }
    
    // Save waiting list
    outFile << "WAITING\n";
    count = 0;
    for (Passenger* p = waitingListFront; p != nullptr; p = p->getNext()) {
        count++;
    }
    outFile << count << "\n";
    
    for (Passenger* p = waitingListFront; p != nullptr; p = p->getNext()) {
        outFile << p->getName() << "|" << p->getBookingDate() << "|" 
                << p->getDepartureCity() << "|" << p->getDestinationCity() << "|"
                << p->getGender() << "|" << p->getCnic() << "|" << p->getAge() << "|"
                << p->getBookingCode() << "|" << p->getTicketSerialNumber() << "|"
                << p->getFare() << "\n";
    }
    
    outFile.close();
}

void BookingSystem::loadFromFile() {
    ifstream inFile(BOOKINGS_FILE);
    if (!inFile) {
        return; // File doesn't exist yet, which is fine
    }
    
    string line;
    
    // Load booking codes
    if (getline(inFile, line) && line.find("BOOKING_CODES") == 0) {
        istringstream iss(line.substr(13));
        int code;
        while (iss >> code) {
            usedBookingCodes.insert(code);
        }
    }
    
    // Load confirmed bookings
    getline(inFile, line); // "CONFIRMED"
    getline(inFile, line);
    int count = atoi(line.c_str());
    
    Passenger* tail = nullptr;
    for (int i = 0; i < count && getline(inFile, line); i++) {
        Passenger* p = new Passenger();
        istringstream iss(line);
        string parts[10];
        
        for (int j = 0; j < 10 && getline(iss, parts[j], '|'); j++);
        
        p->setName(parts[0]);
        p->setBookingDate(parts[1]);
        p->setDepartureCity(parts[2]);
        p->setDestinationCity(parts[3]);
        p->setGender(parts[4]);
        p->setCnic(parts[5]);
        p->setAge(atoi(parts[6].c_str()));
        p->setBookingCode(atoi(parts[7].c_str()));
        p->setTicketSerialNumber(atoi(parts[8].c_str()));
        p->setFare(static_cast<float>(atof(parts[9].c_str())));
        
        if (confirmedBookingsHead == nullptr) {
            confirmedBookingsHead = tail = p;
        } else {
            tail->setNext(p);
            tail = p;
        }
        totalBookingsCount++;
    }
    
    // Load waiting list
    getline(inFile, line); // "WAITING"
    getline(inFile, line);
    count = atoi(line.c_str());
    
    tail = nullptr;
    for (int i = 0; i < count && getline(inFile, line); i++) {
        Passenger* p = new Passenger();
        istringstream iss(line);
        string parts[10];
        
        for (int j = 0; j < 10 && getline(iss, parts[j], '|'); j++);
        
        p->setName(parts[0]);
        p->setBookingDate(parts[1]);
        p->setDepartureCity(parts[2]);
        p->setDestinationCity(parts[3]);
        p->setGender(parts[4]);
        p->setCnic(parts[5]);
        p->setAge(atoi(parts[6].c_str()));
        p->setBookingCode(atoi(parts[7].c_str()));
        p->setTicketSerialNumber(atoi(parts[8].c_str()));
        p->setFare(static_cast<float>(atof(parts[9].c_str())));
        
        if (waitingListFront == nullptr) {
            waitingListFront = waitingListRear = p;
        } else {
            tail->setNext(p);
            waitingListRear = tail = p;
        }
    }
    
    inFile.close();
}

void BookingSystem::createNewBooking() {
    displayHeader("NEW BOOKING");
    
    string departureCity, destinationCity;
    int day, month, year;
    
    // Get departure city
    do {
        cout << "\nAvailable cities: Karachi, Lahore, Peshawar, Islamabad, Quetta" << endl;
        cout << "Enter departure city: ";
        cin >> departureCity;
        
        if (!isValidCity(departureCity)) {
            cout << "Invalid city. Please choose from the available cities." << endl;
        }
    } while (!isValidCity(departureCity));
    
    // Get destination city
    do {
        cout << "\nEnter destination city: ";
        cin >> destinationCity;
        
        if (!isValidCity(destinationCity)) {
            cout << "Invalid city. Please choose from the available cities." << endl;
        } else if (toLower(departureCity) == toLower(destinationCity)) {
            cout << "Departure and destination cities cannot be the same." << endl;
            destinationCity = "";
        }
    } while (!isValidCity(destinationCity) || toLower(departureCity) == toLower(destinationCity));
    
    // Get travel date
    do {
        cout << "\nEnter travel date:" << endl;
        cout << "Day: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;
        
        if (!isValidDate(day, month, year)) {
            cout << "Invalid date. You can book up to 30 days in advance." << endl;
        }
    } while (!isValidDate(day, month, year));
    
    string bookingDate = formatDate(day, month, year);
    
    // Display and select flight
    flightManager.displayFlightsToCity(destinationCity);
    
    int flightSerial;
    bool validFlight = false;
    do {
        cout << "\nEnter flight number (PA-XXX): PA-";
        cin >> flightSerial;
        
        validFlight = flightManager.selectFlight(destinationCity, flightSerial);
        if (!validFlight) {
            cout << "Invalid flight number. Please try again." << endl;
        }
    } while (!validFlight);
    
    // Get number of passengers
    int numPassengers;
    cout << "\nHow many passengers? ";
    cin >> numPassengers;
    
    if (numPassengers <= 0) {
        cout << "Invalid number of passengers." << endl;
        return;
    }
    
    int bookingCode = generateUniqueBookingCode();
    int basePrice = flightManager.getSelectedFlightPrice();
    
    // Input passenger details
    for (int i = 1; i <= numPassengers; i++) {
        cout << "\n--- Passenger " << i << " Details ---" << endl;
        
        Passenger* newPassenger = new Passenger();
        
        string name, gender, cnic;
        int age;
        
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Age: ";
        cin >> age;
        
        cout << "Gender (M/F): ";
        cin >> gender;
        
        // CNIC validation
        do {
            cout << "CNIC (13 digits without dashes): ";
            cin >> cnic;
            
            if (!isValidCnic(cnic)) {
                cout << "Invalid CNIC. Must be exactly 13 digits." << endl;
            }
        } while (!isValidCnic(cnic));
        
        // Set passenger details
        newPassenger->setName(name);
        newPassenger->setAge(age);
        newPassenger->setGender(gender);
        newPassenger->setCnic(formatCnic(cnic));
        newPassenger->setDepartureCity(departureCity);
        newPassenger->setDestinationCity(destinationCity);
        newPassenger->setBookingDate(bookingDate);
        newPassenger->setTicketSerialNumber(i);
        newPassenger->setBookingCode(bookingCode);
        
        // Calculate fare with discount
        float fare = newPassenger->calculateFareWithDiscount(static_cast<float>(basePrice));
        newPassenger->setFare(fare);
        
        // Add to appropriate list (max 2 in confirmed, rest in waiting)
        if (totalBookingsCount < 2) {
            addToConfirmedList(newPassenger);
            totalBookingsCount++;
            cout << "\n✓ Booking confirmed!" << endl;
        } else {
            addToWaitingList(newPassenger);
            cout << "\n⚠ Added to waiting list (no seats available)" << endl;
        }
    }
    
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║  Booking Code: " << bookingCode << "                              ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    cout << "\nPlease save this booking code for future reference." << endl;
    
    saveToFile();
}

float BookingSystem::calculateTotalFare(int bookingCode) {
    float total = 0.0f;
    
    Passenger* current = confirmedBookingsHead;
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            total += current->getFare();
        }
        current = current->getNext();
    }
    
    return total;
}

void BookingSystem::calculateAndDisplayPrice() {
    displayHeader("PRICE CALCULATION");
    
    int bookingCode;
    cout << "Enter booking code: ";
    cin >> bookingCode;
    
    float totalFare = calculateTotalFare(bookingCode);
    
    if (totalFare == 0.0f) {
        cout << "\nNo booking found with this code or booking is in waiting list." << endl;
        return;
    }
    
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║  FARE BREAKDOWN                                    ║" << endl;
    cout << "╠════════════════════════════════════════════════════╣" << endl;
    
    Passenger* current = confirmedBookingsHead;
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            cout << "║  " << current->getName() << " (Age " << current->getAge() << ")" << endl;
            cout << "║  Fare: Rs." << current->getFare() << endl;
            cout << "║  " << endl;
        }
        current = current->getNext();
    }
    
    cout << "╠════════════════════════════════════════════════════╣" << endl;
    cout << "║  TOTAL FARE: Rs." << totalFare << "                    ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
}

void BookingSystem::viewBookingDetails() {
    displayHeader("VIEW BOOKING DETAILS");
    
    int bookingCode;
    cout << "Enter booking code: ";
    cin >> bookingCode;
    
    bool found = false;
    
    Passenger* current = confirmedBookingsHead;
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            current->displayPassengerInfo();
            found = true;
        }
        current = current->getNext();
    }
    
    if (!found) {
        cout << "\nNo booking found with code: " << bookingCode << endl;
    }
}

void BookingSystem::modifyBooking() {
    displayHeader("MODIFY BOOKING");
    
    int bookingCode, serialNo;
    cout << "Enter booking code: ";
    cin >> bookingCode;
    cout << "Enter passenger serial number (S-X): S-";
    cin >> serialNo;
    
    Passenger* current = confirmedBookingsHead;
    bool found = false;
    
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode && 
            current->getTicketSerialNumber() == serialNo) {
            
            cout << "\nCurrent Details:" << endl;
            current->displayPassengerInfo();
            
            cout << "\n--- Enter New Details ---" << endl;
            
            string name, gender;
            int age;
            
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            
            cout << "Age: ";
            cin >> age;
            
            cout << "Gender (M/F): ";
            cin >> gender;
            
            current->setName(name);
            current->setAge(age);
            current->setGender(gender);
            
            cout << "\n✓ Booking modified successfully!" << endl;
            saveToFile();
            found = true;
            break;
        }
        current = current->getNext();
    }
    
    if (!found) {
        cout << "\nBooking not found." << endl;
    }
}

void BookingSystem::cancelBooking() {
    displayHeader("CANCEL BOOKING");
    
    int bookingCode;
    cout << "Enter booking code to cancel: ";
    cin >> bookingCode;
    
    if (confirmedBookingsHead == nullptr) {
        cout << "\nNo bookings to cancel." << endl;
        return;
    }
    
    // Handle deletion from confirmed bookings
    Passenger* current = confirmedBookingsHead;
    Passenger* previous = nullptr;
    bool found = false;
    
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            if (previous == nullptr) {
                // Deleting head
                confirmedBookingsHead = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            
            Passenger* toDelete = current;
            current = current->getNext();
            delete toDelete;
            found = true;
            totalBookingsCount--;
        } else {
            previous = current;
            current = current->getNext();
        }
    }
    
    if (found) {
        cout << "\n✓ Booking cancelled successfully!" << endl;
        saveToFile();
        
        // Try to promote from waiting list
        promoteFromWaitingList();
    } else {
        cout << "\nBooking not found." << endl;
    }
}

void BookingSystem::processPayment() {
    displayHeader("PAYMENT CONFIRMATION");
    
    int bookingCode;
    string cnic;
    
    cout << "Enter booking code: ";
    cin >> bookingCode;
    cout << "Enter CNIC of first passenger (with dashes): ";
    cin >> cnic;
    
    // Verify booking exists and CNIC matches
    Passenger* firstPassenger = nullptr;
    Passenger* current = confirmedBookingsHead;
    
    while (current != nullptr) {
        if (current->getBookingCode() == bookingCode) {
            if (firstPassenger == nullptr || 
                current->getTicketSerialNumber() < firstPassenger->getTicketSerialNumber()) {
                firstPassenger = current;
            }
        }
        current = current->getNext();
    }
    
    if (firstPassenger == nullptr || firstPassenger->getCnic() != cnic) {
        cout << "\nBooking not found or CNIC does not match." << endl;
        return;
    }
    
    float totalFare = calculateTotalFare(bookingCode);
    
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║  Total Amount Due: Rs." << totalFare << "                  ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    
    float payment;
    cout << "\nEnter payment amount: Rs.";
    cin >> payment;
    
    if (payment == totalFare) {
        cout << "\n✓ Payment confirmed! Your booking is complete." << endl;
        cout << "Have a safe journey!" << endl;
    } else if (payment < totalFare) {
        cout << "\n✗ Insufficient payment. Please pay the full amount." << endl;
        cout << "Remaining: Rs." << (totalFare - payment) << endl;
    } else {
        cout << "\n✓ Payment received!" << endl;
        cout << "Change: Rs." << (payment - totalFare) << endl;
        cout << "Your booking is complete. Have a safe journey!" << endl;
    }
}

void BookingSystem::displayWaitingList() const {
    displayHeader("WAITING LIST");
    
    if (waitingListFront == nullptr) {
        cout << "\nWaiting list is empty." << endl;
        return;
    }
    
    Passenger* current = waitingListFront;
    int position = 1;
    
    while (current != nullptr) {
        cout << "\n[Position " << position << "]" << endl;
        current->displayPassengerInfo();
        current = current->getNext();
        position++;
    }
}

void BookingSystem::promoteFromWaitingList() {
    if (waitingListFront == nullptr || totalBookingsCount >= 2) {
        return;
    }
    
    cout << "\n--- Promoting passengers from waiting list ---" << endl;
    
    while (waitingListFront != nullptr && totalBookingsCount < 2) {
        Passenger* toPromote = waitingListFront;
        waitingListFront = waitingListFront->getNext();
        
        if (waitingListFront == nullptr) {
            waitingListRear = nullptr;
        }
        
        toPromote->setNext(nullptr);
        addToConfirmedList(toPromote);
        totalBookingsCount++;
        
        cout << "✓ " << toPromote->getName() << " (Booking: " 
             << toPromote->getBookingCode() << ") promoted to confirmed list." << endl;
    }
    
    saveToFile();
}

void BookingSystem::displayAvailableCities() const {
    displayHeader("AVAILABLE DESTINATIONS");
    
    vector<string> cities = flightManager.getAvailableCities();
    
    cout << "\nWe fly to the following cities:" << endl;
    for (const auto& city : cities) {
        cout << "  • " << city << endl;
    }
}

void BookingSystem::displayBookingStatistics() const {
    displayHeader("BOOKING STATISTICS");
    
    int confirmedCount = 0;
    int waitingCount = 0;
    
    for (Passenger* p = confirmedBookingsHead; p != nullptr; p = p->getNext()) {
        confirmedCount++;
    }
    
    for (Passenger* p = waitingListFront; p != nullptr; p = p->getNext()) {
        waitingCount++;
    }
    
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║  Confirmed Bookings: " << confirmedCount << "                           ║" << endl;
    cout << "║  Waiting List:       " << waitingCount << "                           ║" << endl;
    cout << "║  Total Bookings:     " << (confirmedCount + waitingCount) << "                           ║" << endl;
    cout << "║  Available Seats:    " << (2 - confirmedCount) << "                           ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
}
