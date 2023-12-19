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
#include <cstring>
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Status::Status(const char* c)
   {
      ut.alocpy(m_errDesc, c);
      m_errCode = 0;
   }

   Status::Status(const Status& s)
   {
      m_errCode = s.m_errCode;
      if (s.m_errDesc != nullptr)
      {
         ut.alocpy(m_errDesc, s.m_errDesc);
      }
      else
      {
         m_errDesc = nullptr;
      }
   }

   Status& Status::operator=(const Status& s)
   {
      if (this != &s)
      {
         m_errCode = s.m_errCode;
         if (s.m_errDesc != nullptr)
         {
            ut.alocpy(m_errDesc, s.m_errDesc);
         }
      }
      return *this;
   }

   Status::~Status()
   {
      clear();
   }

   Status& Status::operator=(int num)
   {
      m_errCode = num;
      return *this;
   }

   Status& Status::operator=(const char* str)
   {
      ut.alocpy(m_errDesc, str);
      return *this;
   }

   Status::operator int()const
   {
      return m_errCode;
   }

   Status::operator const char* () const
   {
      return m_errDesc;
   }

   Status::operator bool() const
   {
      return m_errDesc == nullptr;
   }

   Status& Status::clear()
   {
      delete[] m_errDesc;
      m_errDesc = nullptr;
      m_errCode = 0;
      return *this;
   }

   ostream& operator<<(ostream& ostr, const Status& s)
   {
      if (!s)
      {
         if (int(s) != 0)
         {
            ostr << "ERR#" << int(s) << ": " << (const char*)s;
         }
         else
         {
            ostr << (const char*)s;
         }
      }
      return ostr;
   }

}
