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
#include "Date.h"
#include "Utils.h"


using namespace std;
namespace sdds

{
   bool Date::validate()
   {
      bool result = false;
      int year;
      ut.getSystemDate(&year);
      if (m_month < 1 || m_month > 12)
      {
         m_state = "Invalid month in date";
         m_state = 2;
      }
      else if (m_year < year || m_year > m_maxyear)
      {
         m_state = "Invalid year in date";
         m_state = 1;
      }

      else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year))
      {
         m_state = "Invalid day in date";
         m_state = 3;
      }
      else
      {
         result = true;
      }
      return result;
   }
   int Date::uniqueDateVal()
   {
      return m_year * 372 + m_month * 31 + m_day;
   }
   Date::Date(const int year, const int month, const int date)
   {
      if (year == month && month == date)
      {
         ut.getSystemDate(&m_year, &m_month, &m_day);
      }
      else
      {
         m_year = year;
         m_month = month;
         m_day = date;
      }
      validate();
   }

   Date& Date::operator=(const Date& d)
   {
      if (this != &d)
      {
         m_year = d.m_year;
         m_month = d.m_month;
         m_day = d.m_day;
         m_state = d.m_state;
         m_format = d.m_format;
      }
      return *this;
   }

   bool Date::operator==(Date& d)
   {
      return uniqueDateVal() == d.uniqueDateVal();
   }

   bool Date::operator!=(Date& d)
   {
      return uniqueDateVal() != d.uniqueDateVal();
   }

   bool Date::operator<(Date& d)
   {
      return uniqueDateVal() < d.uniqueDateVal();
   }

   bool Date::operator>(Date& d)
   {
      return uniqueDateVal() > d.uniqueDateVal();
   }

   bool Date::operator<=(Date& d)
   {
      return uniqueDateVal() <= d.uniqueDateVal();
   }

   bool Date::operator>=(Date& d)
   {
      return uniqueDateVal() >= d.uniqueDateVal();
   }

   const Status& Date::state() const
   {
      return m_state;
   }

   Date& Date::formatted(bool set)
   {
      m_format = set;
      return *this;
   }

   Date::operator bool()const
   {
      return state();
   }

   ostream& Date::write(ostream& ostr) const
   {
      if (m_format)
      {
         ostr.width(2);
         ostr << m_year << "/";
         ostr.setf(ios::right);
         ostr.width(2);
         ostr.fill('0');
         ostr << m_month << "/";
         ostr.unsetf(ios::right);
         ostr.width(2);
         ostr << m_day;
      }
      else
      {
         ostr.width(2);
         ostr << m_year % 100;
         ostr.width(2);
         ostr.fill('0');
         ostr << m_month;
         ostr.width(2);
         ostr << m_day;
      }
      return ostr;
   }
   istream& Date::read(istream& istr)
   {
      int input;
      istr.clear();
      istr >> input;
      if (istr)
      {
         if (input > 999 && input < 10000)
         {
            m_day = input % 100;
            m_month = (input - input % 100) / 100;
            ut.getSystemDate(&m_year);
         }
         else
         {
            m_day = input % 100;
            m_month = int(input % 10000 / 100);
            m_year = ((input - input % 10000) / 10000) + 2000;
         }
         if (!validate())
         {
            istr.setstate(ios::badbit);
         }
      }
      else
      {
         m_state = "Invalid date value";
      }

      return istr;
   }

   ostream& operator<<(ostream& ostr, const Date& d)
   {
      return d.write(ostr);
   }

   istream& operator>>(istream& istr, Date& d)
   {
      return d.read(istr);
   }

}