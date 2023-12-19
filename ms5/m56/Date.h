/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include "Status.h"

namespace sdds
{
	const int MAX_YEAR_VAL = 2030;

	class Date
	{
		int m_year; 
		int m_month; 
		int m_day; 
		Status m_state; 
		bool m_format; 

		bool validate();
		int uniqueDateValue() const;

	public:
		Date();
		Date(int year, int month, int day);
		Date(const Date& inObj);
		Date& operator=(const Date& inObj);

		int getUniqueDate() const;
		const Status& state();
		Date& formatted(bool addFormat);
		operator bool() const;

		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	bool operator==(const Date& left, const Date& right);
	bool operator!=(const Date& left, const Date& right);
	bool operator<(const Date& left, const Date& right);
	bool operator>(const Date& left, const Date& right);
	bool operator<=(const Date& left, const Date& right);
	bool operator>=(const Date& left, const Date& right);

	std::ostream& operator<<(std::ostream& ostr, const Date& inObj);
	std::istream& operator>>(std::istream& istr, Date& inObj);
}

#endif 
