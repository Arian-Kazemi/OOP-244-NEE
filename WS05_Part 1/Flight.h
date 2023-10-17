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
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#include <string>


namespace sdds {

    const int Boen747_Capacity = 388;
    const int Fuel_Tank_Capacity = 238840;

    class Flight {

        char m_title[16];
        double m_fuel;
        int m_passengers;
        void emptyPlane();

    public:

        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~() const;
        Flight& operator=(Flight& rhs);
        Flight& operator=(int rhs);
        Flight& operator=(double rhs);
        Flight& operator+=(double rhs);
        Flight& operator+=(int rhs);
        Flight& operator-=(double rhs);
        Flight& operator-=(int rhs);
        Flight& operator<<(Flight& rhs);
        Flight& operator>>(Flight& rhs);
    };

    int operator+(const Flight& f1, const Flight& f2);
    int operator+=(int& lhs, const Flight& rhs);

}
#endif // SDDS_FLIGHT_H
