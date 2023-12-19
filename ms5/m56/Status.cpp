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
#include <string.h>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	
	Status::Status()
	{
		m_desc = nullptr;
		m_code = 0;
	}

	
	Status::Status(char* desc)
	{
		ut.alocpy(m_desc, desc);
		m_code = 0;
	}


	Status::Status(const Status& inObj)
	{
		ut.alocpy(m_desc, inObj.m_desc);
		m_code = inObj.m_code;
	}

	
	void Status::destruct()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}

	Status::~Status()
	{
		destruct();
	}

	
	Status& Status::operator=(std::string desc)
	{
		ut.alocpy(m_desc, desc.c_str());
		return *this;
	}

	
	Status& Status::operator=(int code)
	{
		m_code = code;
		return *this;
	}

	
	Status::operator int() const
	{
		return m_code;
	}

	
	Status::operator const char* () const
	{
		return m_desc;
	}


	Status::operator bool() const
	{
		
		return (m_desc == nullptr);
	}

	
	Status& Status::clear()
	{
		if (m_desc != nullptr) {
			delete[] m_desc;
			m_desc = nullptr;
		}
		m_code = 0;
		return *this;
	}

	
	std::ostream& Status::print(std::ostream& ostr) const
	{
		if (this)
		{
			if (m_code != 0) {
				ostr << "ERR#" << m_code << ": " << m_desc;
			}
			else {
				ostr << m_desc;
			}
		}
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Status& inObj)
	{
		inObj.print(ostr);
		return ostr;
	}
}