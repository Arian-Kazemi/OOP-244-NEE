/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"

namespace sdds {

    class LblShape : public Shape {
    private:
        char* m_label{};
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

    protected:
        const char* label() const;

    public:
        LblShape();
        LblShape(const char* labelName);
        virtual ~LblShape();
        void getSpecs(std::istream& is);
    };
} 
#endif  