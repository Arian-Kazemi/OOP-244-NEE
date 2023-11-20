/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Line.h"

using namespace std;
namespace sdds {
    Line::Line() : LblShape() {
        m_length = 0;
    }

    Line::Line(const char* labelName, int length) : LblShape(labelName) {
        m_length = length;
    }

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(m_length, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << endl;
            for (int i = 0; i < m_length; i++) {
                cout << "=";
            }
        }
    }

} 