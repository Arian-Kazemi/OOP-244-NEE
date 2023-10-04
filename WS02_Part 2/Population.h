/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char postalCode[4];
        int population;
    };

    bool startsWith(const char* cString, const char* subString);
    bool getPostalCode(char* postal_code_prefix);
    bool load(const char* filename, const char* partial_postal_code_prefix);
    void sort();
    void display();
    void deallocateMemory();
}

#endif // SDDS_POPULATION_H_
