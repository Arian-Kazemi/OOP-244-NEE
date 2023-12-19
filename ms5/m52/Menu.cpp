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
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds

{
   Menu::Menu()
   {
      m_numOptions = 0;
   }
   Menu::Menu(unsigned int numOptions, const char* options)
   {
      set(numOptions, options);
   }

   Menu& Menu::set(unsigned int numOptions, const char* options)
   {
      if (numOptions > 15 || options == nullptr)
         m_numOptions = 0;
      else
      {
         ut.alocpy(m_options, options);
         m_numOptions = numOptions;
      }

      return *this;
   }

   Menu::~Menu()
   {
      delete[] m_options;
   }

   unsigned int Menu::run() const
   {
      bool invalid = true;
      int val = 0;
      cout << m_options << "0- Exit" << endl;
      cout << "> ";
      do
      {
         cin >> val;
         if (!cin)
         {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Integer, retry: ";
         }
         else if (val < 0 || (unsigned int)val > m_numOptions)
         {
            cout << "Value out of range [0<=val<=" << m_numOptions << "]: ";
         }
         else
            invalid = false;
      } while (invalid);
      return val;
   }

}