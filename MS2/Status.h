/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <iostream>

namespace sdds {
	class Status {
		char* m_desc{};
		int m_code{};

	public:
		Status(const char* desc = nullptr);
		Status& operator=(const Status& source);
		Status& operator=(const char* desc);
		Status& operator=(int code);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
	};
	std::ostream& operator <<(std::ostream& ostr, const Status& status);
}

#endif // !SDDS_STATUS_H
