#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

/**
 * @brief Utility functions for string manipulation and date validation
 */

// String manipulation
string toLower(const string& str);
string toUpper(const string& str);
string formatCnic(const string& cnic);

// Date validation
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
string formatDate(int day, int month, int year);

// Input validation
bool isValidCnic(const string& cnic);
bool isValidCity(const string& city);
bool isAllDigits(const string& str);

// Display utilities
void clearScreen();
void displayHeader(const string& title);
void displayDivider();
void pauseScreen();

#endif // UTILS_H
