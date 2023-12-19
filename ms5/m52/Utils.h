/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include <iostream>


namespace sdds {

    const int sdds_testYear = 2023;
    const int sdds_testMon = 10;
    const int sdds_testDay = 9;
   class Utils {
      bool m_testMode = false;
   public:
      void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
      int daysOfMon(int mon, int year)const;
      void testMode(bool testmode = true);
      void alocpy(char*& destination, const char* source);
      int getint(const char* prompt = nullptr, std::istream& istr = std::cin);
      int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
      double getdouble(double min, double max, const char* prompt = nullptr);
      void strcpy(char* des, const char* src);
      int strlen(const char* str);
      const char* strstr(const char* str, const char* find);
      int strncmp(const char* s1, const char* s2, int len);
      template <typename Type>
      void dealoSingle(Type*& source)
      {
         delete source;
         source = nullptr;
      }
   };
   extern Utils ut;
}

#endif 
