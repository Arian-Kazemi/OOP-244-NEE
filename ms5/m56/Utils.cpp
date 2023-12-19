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
#include <iomanip>
#include <ctime>
#include <string>
#include <string.h>
#include <ctype.h>
#include "Utils.h"

using namespace std;
namespace sdds {
   
   Utils ut;

   
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
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
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }

  
   void Utils::alocpy(char*& destination, const char* source)
   {
       if (source != nullptr) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
       else {
           destination = nullptr;
       }    
   }
   
 
   int Utils::getInt(const char* prompt = nullptr, const char* errMes = nullptr)
   {
       bool isChar = false;
       bool exit = false;
       string inputStr = { 0 };
       int result = 0;
       if (prompt != nullptr) {
           cout << prompt;
           do {      
               isChar = false;
               cin >> inputStr;
               for (unsigned int i = 0; i < strlen(inputStr.c_str()); i++) { 
                   if (!isdigit(inputStr[i])) {
                       isChar = true;
                       i = strlen(inputStr.c_str());
                   }
               }
               if (!isChar) { 
                   if (stoi(inputStr) >= 0) {
                       result = stoi(inputStr);
                       exit = true;
                   }
               }
               else { 
                   
                   cout << errMes << ", retry: ";
                   cin.clear();
                   cin.ignore(1000, '\n');
               }
           } while (!exit);
       }
       return result;
   }

   int Utils::getInt(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr)
   {
       bool exit = false;
       int input = 0;
       if (prompt != nullptr) {
           do {
               input = getInt(prompt, errMes);
               if (input < min || input > max) {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]:";
                    prompt = " ";  
               }
               else {
                   exit = true;
               }
           } while (!exit);
       }
       return input;
   }


  
   double Utils::getDouble(const char* prompt = nullptr, const char* errMes = nullptr)
   {
       bool isChar = false;
       bool exit = false;
       string inputStr = { 0 };
       double result = 0;
       if (prompt != nullptr) {
           cout << prompt;
           do {
               isChar = false; 
               cin >> inputStr;
               for (unsigned int i = 0; i < strlen(inputStr.c_str()); i++) { 
                   if (!isdigit(inputStr[i])) {
                       if (int(inputStr[i]) == 46){
                           
                       }
                       else {
                           isChar = true;
                           i = strlen(inputStr.c_str());
                       }
                   }
               }
               if (!isChar) { 
                   if (stod(inputStr) > 0) {
                       result = stod(inputStr);
                       exit = true;
                   }
               }
               else {
                   cout << errMes << ", retry: ";
                   cin.clear();
                   cin.ignore(1000, '\n');
               }
           } while (!exit);
       }
       return result;
   }

   double Utils::getDouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr)
   {
       bool exit = false;
       double input = 0;
       if (prompt != nullptr) {
           do {
               input = getDouble(prompt, errMes);
               if (input < min || input > max) {
                   cout << fixed << setprecision(2) << "Value out of range [" << min << "<=val<=" << max << "]:";
                   prompt = " ";
               }
               else {
                   exit = true;
               }
           } while (!exit);
       }
       return input;
   } 
}