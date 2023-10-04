/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"

using namespace std;

namespace sdds {
    Train::Train() {
        m_name = nullptr;
        m_passengers = -1;
        m_departure = -1;
    }

    Train::Train(const char* name, int passengers, int departure) {
        initialize();
        set(name, passengers, departure);
    }

    Train::~Train() {
        finalize();
    }

    void Train::initialize() {
        m_name = nullptr;
        m_passengers = -1;
        m_departure = -1;
    }

    bool Train::validTime(int value) const {
    int minutes = value % 100;
    return (value >= MIN_TIME && value <= MAX_TIME && minutes <= 59);
}

    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* name) {
    if (name != nullptr && name[0] != '\0') {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        std::strncpy(m_name, name, strlen(name) + 1);
        m_name[strlen(name)] = '\0'; // Ensure null-termination
    }
    else {
        delete[] m_name;
        m_name = nullptr;
    }
}


    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            m_passengers = noOfPassengers;
            m_departure = departure;
        }
        else {
            m_passengers = -1;
            m_departure = -1;
        }
    }

    void Train::set(const char* name, int noOfPassengers, int departure) {
        set(name);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        delete[] m_name;
        m_name = nullptr;
        m_passengers = -1;
        m_departure = -1;
    }

    bool Train::isInvalid() const {
        return (m_name == nullptr || m_passengers == -1 || m_departure == -1);
    }

    int Train::noOfPassengers() const {
        return m_passengers;
    }

    const char* Train::getName() const {
        return m_name;
    }

    int Train::getDepartureTime() const {
        return m_departure;
    }

    void Train::display() const {
        if (isInvalid()) {
            cout << "Train in an invalid State!" << endl;
        }
        else {
            cout << "NAME OF THE TRAIN:    " << m_name << endl;
            cout << "NUMBER OF PASSENGERS: " << m_passengers << endl;
            cout << "DEPARTURE TIME:       " << setw(4) << setfill('0') << m_departure << endl;
        }
    }
}
