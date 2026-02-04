#include "Utils.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <ctime>

string toLower(const string &str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c)
              { return tolower(c); });
    return result;
}

string toUpper(const string &str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c)
              { return toupper(c); });
    return result;
}

string formatCnic(const string &cnic)
{
    if (cnic.length() != 13)
        return cnic;
    return cnic.substr(0, 5) + "-" + cnic.substr(5, 7) + "-" + cnic.substr(12, 1);
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year)
{
    time_t now = time(nullptr);
    tm *currentTime = localtime(&now);

    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;

    // Check basic validity
    if (month < 1 || month > 12)
    {
        return false;
    }

    if (day < 1 || day > 31)
    {
        return false;
    }

    // Check year validity (current year to 2 years ahead for flexibility)
    if (year < currentYear || year > currentYear + 2)
    {
        return false;
    }

    // Check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }

    // Check for February
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            return day <= 29;
        }
        else
        {
            return day <= 28;
        }
    }

    // Allow booking from current month onwards (simplified - allows today and future)
    if (year == currentYear && month < currentMonth)
    {
        return false;
    }

    return true;
}

string formatDate(int day, int month, int year)
{
    return (day < 10 ? "0" : "") + to_string(day) + "/" +
           (month < 10 ? "0" : "") + to_string(month) + "/" +
           to_string(year);
}

bool isValidCnic(const string &cnic)
{
    if (cnic.length() != 13)
    {
        return false;
    }

    return isAllDigits(cnic);
}

bool isValidCity(const string &city)
{
    string cityLower = toLower(city);
    return (cityLower == "lahore" || cityLower == "islamabad" ||
            cityLower == "karachi" || cityLower == "quetta" ||
            cityLower == "peshawar");
}

bool isAllDigits(const string &str)
{
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayHeader(const string &title)
{
    cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║  " << title;
    for (size_t i = title.length(); i < 56; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
}

void displayDivider()
{
    cout << "────────────────────────────────────────────────────────────" << endl;
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
