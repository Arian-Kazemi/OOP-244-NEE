/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds {



    class Line : public LblShape {


    private:

        int m_length;

    public:

        Line();
        Line(const char* labelName, int length);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}  
#endif  