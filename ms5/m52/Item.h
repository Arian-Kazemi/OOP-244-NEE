/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <iostream>
#include "iProduct.h"
#include "Status.h"

namespace sdds
{
   class Item : public iProduct
   {
      double m_price;
      int m_qty;
      int m_qtyNeeded;
      char* m_desc{};
      bool m_linear;
   protected:
      Status m_state;
      int m_sku;
      bool linear()const;
   public:
      Item();
      Item(const Item& I);
      Item& operator=(const Item& I);
      ~Item();
      int qtyNeeded()const;
      int qty()const;
      operator double()const;
      operator bool()const;
      int operator-=(int qty);
      int operator+=(int qty);
      void linear(bool islinear);
      Item& clear();
      bool operator==(int sku)const;
      bool operator==(const char* description)const;
      virtual std::ofstream& save(std::ofstream& ofstr)const;
      virtual std::ifstream& load(std::ifstream& ifstr);
      virtual std::ostream& display(std::ostream& ostr)const;
      virtual std::istream& read(std::istream& istr);
      virtual int readSku(std::istream& istr);
   };

}
#endif