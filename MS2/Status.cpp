/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
#include <cstring>

#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds {

	Status::Status(const char* desc) {
		m_code = 0;

		m_desc = nullptr;

		if (desc) ut.alocpy(m_desc, desc);

	}
	Status& Status::operator=(const Status& stat)
	{
		if (this != &stat)
		{
			m_code = stat.m_code;
			ut.alocpy(m_desc, stat.m_desc);
		}

		return *this;
	}
	Status& Status::operator=(const char* desc) {

		ut.alocpy(m_desc, desc);
		return *this;
	}
	Status& Status::operator=(int code) {
		m_code = code;
		return *this;
	}
	Status::operator int() const {
		return m_code;
	}
	Status::operator const char* () const {
		return m_desc;
	}
	Status::operator bool() const {
		return !m_desc;
	}
	Status& Status::clear() {
		delete[] m_desc;
		m_desc = nullptr;
		m_code = 0;
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const Status& status)
	{
		if (!status) {
			if ((int)status) {
				ostr << "ERR#" << (int)status << ": ";
			}
			ostr << (const char*)status;
		}
		return ostr;
	}
}


