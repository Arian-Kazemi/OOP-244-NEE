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

namespace sdds {
    const int sdds_Test_Year = 2022;
    const int sdds_Test_Month = 03;
    const int sdds_Test_Day = 31;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& des, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
        double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;
}

#endif 
