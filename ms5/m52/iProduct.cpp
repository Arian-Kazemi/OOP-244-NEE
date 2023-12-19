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

namespace sdds
{
   std::ostream& operator<<(std::ostream& ostr, iProduct& ip)
   {
      ip.display(ostr);
      return ostr;
   }
   std::istream& operator>>(std::istream& istr, iProduct& ip)
   {
      ip.read(istr);
      return istr;
   }
   iProduct::~iProduct() 
   {

   }
}