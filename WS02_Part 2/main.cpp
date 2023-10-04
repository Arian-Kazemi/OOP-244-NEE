/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#include "Population.h"
using namespace sdds;

int main() {
    char postal_code_prefix[4];
    while (getPostalCode(postal_code_prefix)) {
        if (load("PCpopulationsComplete.csv", postal_code_prefix)) {
            sort(); // Call the sort function to sort the data by postal codes
            display();
        }
        deallocateMemory();
    }
    return 0;
}