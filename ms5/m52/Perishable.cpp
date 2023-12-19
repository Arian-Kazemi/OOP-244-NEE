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
#include <fstream>
#include "Perishable.h"
#include "Utils.h"

using namespace std;
namespace sdds

{
   Perishable::Perishable() : Item()
   {

   }

   Perishable::Perishable(const Perishable& P)
   {
      operator=(P);
   }

   Perishable& Perishable::operator=(const Perishable& P)
   {
      if (this != &P)
      {
         Item:: operator=(P);
         m_expiry = P.m_expiry;
         ut.alocpy(m_instruction, P.m_instruction);
         if (m_instruction == nullptr)
         {
            m_state = "Empty";
         }
      }
      return *this;
   }

   Perishable::~Perishable()
   {
      delete[] m_instruction;
   }

   const Date& Perishable::expiry()
   {
      return m_expiry;
   }

   int Perishable::readSku(std::istream& istr)
   {
      return ut.getint(10000, 39999, "SKU: ");
   }

   std::ofstream& Perishable::save(std::ofstream& ofstr) const
   {
      Date D;
      if (*this)
      {
         //it will call the save of the Base class.
         Item::save(ofstr);
         //   writes a tab
         ofstr << "\t";
         //   writes the handling instructions, if handling instructions existand the attribute is not empty.
         if (m_instruction && m_instruction[0] != ' ') ofstr << m_instruction;
         //   writes a tab
         ofstr << "\t";
         //   writes an unformatted copy of the expiry date
         D = m_expiry;
         D.formatted(false);
         ofstr << D;
      }
      return ofstr;
   }
   std::ifstream& Perishable::load(std::ifstream& ifstr)
   {
      char temp[1000];
      Item::load(ifstr);
      ifstr.getline(temp, 1000, '\t');
      ut.alocpy(m_instruction, temp);
      m_expiry.Date::read(ifstr);
      ifstr.clear();
      ifstr.ignore(1000, '\n');
      if (ifstr.fail() || !m_state)
      {
         m_state = "Input file stream read (perishable) failed!";
         ifstr.setstate(ios::badbit);
      }
      return ifstr;
   }
   std::ostream& Perishable::display(std::ostream& ostr) const
   {
      if (!*this)
         ostr << m_state;
      else if (linear())
      {
         Item::display(ostr);
         if (m_instruction && m_instruction[0] != '\0')
            ostr << "*";
         else
            ostr << " ";
         ostr << m_expiry;
      }
      else if (!linear())
      {
         ostr << "Perishable ";
         Item::display(ostr);
         ostr << "Expiry date: ";
         ostr << m_expiry;
         if (m_instruction && m_instruction[0] != '\0')
         {
            ostr << endl << "Handling Instructions: ";
            ostr << m_instruction;
         }
         ostr << "\n";
      }
      return ostr;
   }
   std::istream& Perishable::read(std::istream& istr)
   {
      char temp[1000];
      istr.clear();
      Item::read(istr);
      delete[] m_instruction;
      m_instruction = nullptr;
      cout << "Expiry date (YYMMDD): ";
      m_expiry.Date::read(istr);
      istr.ignore(1000, '\n');
      cout << "Handling Instructions, ENTER to skip: ";
      if (istr.peek() != '\n')
      {
         istr.getline(temp, 1000, '\n');
         ut.alocpy(m_instruction, temp);
      }
      if (!istr)
      {
         m_state = "Perishable console date entry failed!";
      }
      return istr;
   }
}