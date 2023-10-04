/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Train.h"

using namespace sdds;

void Train::initialize() {
    if (m_name != nullptr) {
        delete[] m_name;
        m_name = nullptr;
    }

    m_passengers = 0;
    m_departure_time = 0;
}

bool Train::validTime(int value) const {
    if (value >= MIN_TIME && value <= MAX_TIME) {
        int minutes = value % 100;
        return (minutes <= 59);
    }
    return false;
}

bool Train::validNoOfPassengers(int value) const {
    bool ok = false;
    if (value >= 0 && value <= MAX_NO_OF_PASSENGERS) {
        ok = true;
    }
    return ok;
}

bool Train::isInvalid() const {
    return (m_name == nullptr || m_name[0] == '\0' || m_passengers <= 0 || m_departure_time <= 0);
}

void Train::set(const char* name) {
    delete[] m_name;
    m_name = nullptr;

    if (name != nullptr && name[0] != '\0') {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
}

void Train::set(int passengers, int departure_time) {
    if (validNoOfPassengers(passengers)) {
        m_passengers = passengers;
    }
    else m_passengers = -1;

    if (validTime(departure_time)) {
        m_departure_time = departure_time;
    }
    else m_departure_time = -1;
}

void Train::set(const char* name, int passengers, int departure_time) {
    set(name);
    set(passengers, departure_time);
}

void Train::finalize() {
    delete[] m_name;
    m_name = nullptr;
}

int Train::noOfPassengers() const {
    return m_passengers;
}

int Train::getDepartureTime() const {
    return m_departure_time;
}

const char* Train::getName() const {
    return m_name;
}

void Train::display() const {
    if (!isInvalid()) {
        std::cout << "NAME OF THE TRAIN:    " << getName() << std::endl
            << "NUMBER OF PASSENGERS: " << noOfPassengers() << std::endl
            << "DEPARTURE TIME:       " << getDepartureTime() << std::endl;
    }
    else std::cout << "Train in an invalid State!" << std::endl;
}

bool Train::load(int& notBoarded) {
    int numPassengers;
    std::cout << "Enter number of passengers boarding:" << std::endl;
    std::cout << "> ";
    std::cin >> numPassengers;

    if (numPassengers <= 0) {
        std::cout << "Invalid number of passengers." << std::endl;
        m_passengers = -1;
        notBoarded = 0;
        return false;
    }

    if (m_passengers + numPassengers <= MAX_NO_OF_PASSENGERS) {
        m_passengers += numPassengers;
        notBoarded = 0;
        return true;
    }
    else {
        notBoarded = (m_passengers + numPassengers) - MAX_NO_OF_PASSENGERS;
        m_passengers = MAX_NO_OF_PASSENGERS;
        return false;
    }
}

bool Train::updateDepartureTime() {
    std::cout << "Enter new departure time:\n> ";
    if (std::cin >> m_departure_time) {
        if (validTime(m_departure_time)) {
            return true;
        }
        m_departure_time = -1;
    }
    return false;
}

bool Train::transfer(const Train& other) {
    if (!isInvalid() && !other.isInvalid()) {
        char* combinedName = new char[strlen(m_name) + strlen(other.m_name) + 3];
        strcpy(combinedName, m_name);
        strcat(combinedName, ", ");
        strcat(combinedName, other.m_name);

        delete[] m_name;
        m_name = combinedName;

        int notBoarded = 0;
        if (m_passengers + other.m_passengers <= MAX_NO_OF_PASSENGERS) {
            m_passengers += other.m_passengers;
        }
        else {
            notBoarded = (m_passengers + other.m_passengers) - MAX_NO_OF_PASSENGERS;
            m_passengers = MAX_NO_OF_PASSENGERS;
        }

        if (notBoarded > 0) {
            std::cout << "Train is full; " << notBoarded << " passengers of " << other.getName() << " could not be boarded!" << std::endl;
        }

        return true;
    }
    else {
        return false;
    }
}
