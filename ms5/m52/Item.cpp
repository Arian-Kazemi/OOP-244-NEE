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
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   bool Item::linear() const
   {
      return m_linear;
   }
   Item::Item()
   {
      m_price = m_qty = m_qtyNeeded = m_sku = m_state = 0;
      m_linear = false;
   }
   Item::Item(const Item& I)
   {
      operator=(I);
   }
   Item& Item::operator=(const Item& I)
   {
      if (this != &I)
      {
         m_price = I.m_price;
         m_qty = I.m_qty;
         m_qtyNeeded = I.m_qtyNeeded;
         ut.alocpy(m_desc, I.m_desc);
         m_linear = I.m_linear;
         m_state = I.m_state;
         m_sku = I.m_sku;
      }
      return *this;
   }
   Item::~Item()
   {
      delete[] m_desc;
      m_desc = nullptr;
   }
   int Item::qtyNeeded() const
   {
      return m_qtyNeeded;
   }
   int Item::qty() const
   {
      return m_qty;
   }
   Item::operator double() const
   {
      return m_price;
   }
   Item::operator bool() const
   {
      return m_state;
   }
   int Item::operator-=(int qty)
   {
      m_qty -= qty;
      return m_qty;
   }
   int Item::operator+=(int qty)
   {
      m_qty += qty;
      return m_qty;
   }
   void Item::linear(bool islinear)
   {
      m_linear = islinear;
   }
   Item& Item::clear()
   {
      m_state.clear();
      return *this;
   }
   bool Item::operator==(int sku) const
   {
      return sku == m_sku;
   }
   bool Item::operator==(const char* description) const
   {
      bool result = true;
      if (description == nullptr || m_desc == nullptr)
         result = false;
      else if (!ut.strstr(m_desc, description))
         result = false;
      return result;
   }
   std::ofstream& Item::save(std::ofstream& ofstr) const
   {
      if (m_state)
      {
         ofstr << m_sku << '\t';
         ofstr << m_desc << '\t';
         ofstr << m_qty << '\t';
         ofstr << m_qtyNeeded << '\t';
         ofstr << m_price;
         ofstr.clear();
      }
      return ofstr;
   }
   std::ifstream& Item::load(std::ifstream& ifstr)
   {
      char temp[1000];
      ifstr >> m_sku;
      ifstr.clear();
      ifstr.ignore(1000, '\t');
      ifstr.getline(temp, 1000, '\t');
      ut.alocpy(m_desc, temp);
      ifstr >> m_qty;
      ifstr >> m_qtyNeeded;
      ifstr >> m_price;
      ifstr.get();
      if (ifstr.fail())
      {
         m_state = "Input file stream read failed!";
      }
      return ifstr;
   }
   std::ostream& Item::display(std::ostream& ostr) const
   {
      int i;
      if (m_state)
      {
         if (m_linear)
         {
            ostr << m_sku << " | ";
            ostr.fill(' ');
            if (m_desc != nullptr)
            {
               if (ut.strlen(m_desc) <= 35)
               {
                  ostr.setf(ios::left);
                  ostr.width(35);
                  ostr << m_desc;
               }
               else
                  for (i = 0; m_desc[i] != '\0' && i < 35; i++) ostr << m_desc[i];
            }
            ostr << " | ";
            ostr.setf(ios::right);
            ostr.width(4);
            ostr << m_qty;
            ostr << " | ";
            ostr.width(4);
            ostr << m_qtyNeeded;
            ostr << " | ";
            ostr.width(7);
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << m_price;
            ostr << " |";
            ostr.unsetf(ios::right);
         }
         else
         {
            ostr << "AMA Item:" << endl <<
               m_sku << ": " << m_desc << endl <<
               "Quantity Needed: " << m_qtyNeeded << endl <<
               "Quantity Available: " << m_qty << endl;
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "Unit Price: $" << m_price << endl;
            ostr.precision(2);
            ostr << "Needed Purchase Fund: $" << m_price * (m_qtyNeeded - m_qty) << endl;
         }
      }
      return ostr;
   }
   std::istream& Item::read(std::istream& istr)
   {
      char temp[1000];
      clear();
      cout << "AMA Item:" << endl;
      m_sku = readSku(istr);
      istr.clear();
      istr.ignore(1000, '\n');
      cout << "Description: ";
      istr.getline(temp, 1000, '\n');
      ut.alocpy(m_desc, temp);
      m_qtyNeeded = ut.getint(1, 9999, "Quantity Needed: ");
      m_qty = ut.getint(0, m_qtyNeeded, "Quantity On Hand: ");
      m_price = ut.getdouble(0.0, 9999.0, "Unit Price: $");
      return istr;
   }
   int Item::readSku(std::istream& istr)
   {
      return ut.getint(40000, 99999, "SKU: ");
   }
}