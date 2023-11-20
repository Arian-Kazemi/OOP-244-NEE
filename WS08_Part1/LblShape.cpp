/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace sdds {
    // Protected:
    const char* LblShape::label() const {
        return m_label;
    }

    // Public:
    LblShape::LblShape() {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* labelName) {
        delete[] m_label;
        m_label = new char[strlen(labelName) + 1];
        strcpy(m_label, labelName);
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    
    void LblShape::getSpecs(std::istream& is) {
        string temp;
        getline(is, temp, ',');
        const char* labelName = temp.c_str();
        delete[] m_label;
        m_label = new char[strlen(labelName) + 1];
        strcpy(m_label, labelName);
    }
}  
