

/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
************************************************************************/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <ostream>

namespace sdds {
	class Status {
		char* m_description;
		int m_code;
	public:
		Status(const char* description = "\0", int code = 0);
		Status(const Status& other);
		~Status();

		Status& operator=(const Status& other);
		Status& operator=(const char* description);
		Status& operator=(int status);

		Status& clear();

		operator int() const { return m_code; }
		operator const char* () const { return m_description; }
		operator bool() const { return m_description == nullptr; }

		friend std::ostream& operator<<(std::ostream& os, const Status& status);
	};
}

#endif 