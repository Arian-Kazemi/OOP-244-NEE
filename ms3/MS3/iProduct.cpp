/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#include <iostream>  
#include "iProduct.h"
namespace sdds {
    int iProduct::readSku(std::istream& istr)
    {
        int flag;
        istr >> flag;
        return flag;
    }

    int iProduct::operator-=(int qty)
    {
        return qty;
    }

    iProduct::operator double() const
    {
        return 0.0;
    }

    iProduct::operator bool() const
    {
        return false;
    }

    int iProduct::qtyNeeded() const
    {
        return 0;
    }

    int iProduct::qty() const
    {
        return 0;
    }

    void iProduct::linear(bool isLinear)
    {
        std::cout << isLinear;
    }

    std::ofstream& iProduct::save(std::ofstream& ofstr) const
    {
        return ofstr;
    }

    std::ifstream& iProduct::load(std::ifstream& ifstr)
    {
        return ifstr;
    }

    std::ostream& iProduct::display(std::ostream& ostr) const
    {
        return ostr;
    }

    std::istream& iProduct::read(std::istream& istr)
    {
        return istr;
    }

    bool iProduct::operator==(int sku) const
    {
        return false;
    }

    bool iProduct::operator==(const char* description) const
    {
        return false;
    }

    int iProduct::operator+=(int qty)
    {
        return qty;
    }

    std::ostream& operator<<(std::ostream& ostr, const iProduct& I)
    {
        return I.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, iProduct& I)
    {
        return I.read(istr);
    }


}