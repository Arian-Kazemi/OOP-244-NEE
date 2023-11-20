/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>

#include "LblShape.h"

namespace sdds {
    class Rectangle : public LblShape {
    private:
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char* labelName, int width, int height);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}  
#endif  