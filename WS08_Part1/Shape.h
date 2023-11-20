/* ------------------------------------------------------
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>


namespace sdds {

    class Shape {


    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape() {};

    };


    std::ostream& operator<<(std::ostream& os, const Shape& shape);
    std::istream& operator>>(std::istream& is, Shape& shape);
}  
#endif  