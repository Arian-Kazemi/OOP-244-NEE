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
namespace sdds
{
	const int sdds_Test_Year = 2022;
	const int sdds_Test_Month = 03;
	const int sdds_Test_Day = 31;
	class Utils
	{
		bool m_testMode = false;
	public:
		void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
		int daysOfMon(int mon, int year)const;
		void testMode(bool testmode = true);
		int checking_num(std::istream& istr, int x, int y);
		double checking_float(std::istream& istr, double x, double y);
	};
	extern Utils ut;
}

#endif 