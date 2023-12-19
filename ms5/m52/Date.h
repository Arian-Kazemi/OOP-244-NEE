/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"


namespace sdds

{
   class Date
   {
      const int m_maxyear = 2030;
      int m_year;
      int m_month;
      int m_day;
      Status m_state;
      bool m_format = true;
      bool validate();
      int uniqueDateVal();
   public:
      Date(const int year = 0, const int month = 0, const int date = 0);
      Date& operator=(const Date& d);
      bool operator==(Date& d);
      bool operator!=(Date& d);
      bool operator<(Date& d);
      bool operator>(Date& d);
      bool operator<=(Date& d);
      bool operator>=(Date& d);
      const Status& state()const;
      Date& formatted(bool set);
      operator bool()const;
      std::ostream& write(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const Date& d);
   std::istream& operator>>(std::istream& istr, Date& d);

}
#endif