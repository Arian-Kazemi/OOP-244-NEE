/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"


using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::alocpy(char*& destination, const char* source)
   {
      delete[] destination;
      destination = nullptr;
      if (source != nullptr)
      {
         destination = new char[strlen(source) + 1];
         strcpy(destination, source);
      }
   }
   int Utils::getint(const char* prompt, istream& istr) {
      bool valid = false;
      int input = 0;
      if (prompt != nullptr)
      {
         cout << prompt;
      }
      while (!valid)
      {
         istr >> input;
         if (istr)
         {
            valid = true;
         }
         else
         {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Integer, retry: ";
         }
      }
      return input;
   }
   int Utils::getint(int min, int max, const char* prompt, const char* errMes)
   {
      bool valid = false;
      int val = 0;
      val = getint(prompt);
      while (!valid)
      {
         if (val >= min && val <= max)
         {
            valid = true;
         }
         else
         {
            if (errMes != nullptr)
               cout << errMes << ", retry: ";
            else
            {
               cout << "Value out of range " << "[" << min << "<=val<=" << max << "]: ";
               val = getint();
            }
         }
      }
      return val;
   }
   double Utils::getdouble(double min, double max, const char* prompt)
   {
      bool valid = false;
      double val = 0;
      if (prompt != nullptr)
      {
         cout << prompt;
      }
      while (!valid)
      {
         cin >> val;
         if (!cin)
         {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid number, retry: ";
         }
         else if (val < min || val > max)
         {
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
         }
         else
            valid = true;
      }
      return val;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if (day) *day = sdds_testDay;
         if (mon) *mon = sdds_testMon;
         if (year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }
   void Utils::strcpy(char* des, const char* src) {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = 0;
   }
   int Utils::strlen(const char* str) {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   const char* Utils::strstr(const char* str, const char* find)
   {
      {
         const char* faddress = nullptr;
         int i, flen = strlen(find), slen = strlen(str);
         for (i = 0; i <= slen - flen && strncmp(&str[i], find, flen); i++);
         if (i <= slen - flen) faddress = &str[i];
         return faddress;
      }
   }

   int Utils::strncmp(const char* s1, const char* s2, int len)
   {
      int i = 0;
      while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];

   }

}