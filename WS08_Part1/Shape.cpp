/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Shape.h"

#include <iostream>
#include <string>

using namespace std;


namespace sdds {


    ostream& operator<<(ostream& os, const Shape& shape) {
        shape.draw(os);

        return os;
    }

    istream& operator>>(istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}  