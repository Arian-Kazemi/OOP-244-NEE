/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_AidMan_H
#define SDDS_AidMan_H

#include "Menu.h"
#include "iProduct.h"

namespace sdds

{
   const int sdds_max_num_items = 100;
   class AidMan
   {
      char* m_fileName;
      Menu m_mainMenu;
      unsigned int menu() const;
      iProduct* m_iproduct[sdds_max_num_items]{};
      int m_numOfIproduct;
   public:
      AidMan();
      AidMan(const AidMan& a) = delete;
      AidMan& operator=(const AidMan& A) = delete;
      virtual ~AidMan();
      void run();
      void save();
      void deallocate();
      void load();
      void add();
      int list(const char* sub_desc = nullptr);
      int search(int sku) const;
   };
}
#endif