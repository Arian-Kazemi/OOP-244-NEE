/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


#include <iostream>
#include <string>

namespace sdds {


    class Portfolio {

        double m_value = 0;
        char m_stock[16];
        char m_type;


    public:


        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        Portfolio& operator +=(double value);
        Portfolio& operator -=(double value);
        double getvalue() const;
        Portfolio& operator <<(Portfolio& right);
        Portfolio& operator >>(Portfolio& right);
        bool istrueportfolio() const;
        void  emptyPortfolio();
        std::ostream& display() const;
    };


    bool operator ~(const Portfolio& port);
    double operator +(const Portfolio& p1, Portfolio& p2);
    double operator +=(double& value, const Portfolio& p1);
}
#endif // SDDS_Portfolio_H_