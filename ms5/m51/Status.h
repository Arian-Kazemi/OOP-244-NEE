/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/



#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
namespace sdds {
	class Status {
		char* description{};
		int statusCode{};
	public:
		Status() {}
		Status(char* desc, int status);
		~Status();
		Status(const Status& other);
		void setStatus(int status);
		void setStatus(const char* status);
		int getStatus() const;
		const char* getDescription()const;
		operator int() const;
		operator const char* () const;
		operator bool() const;
		
		Status& operator=(const char* newDesc);
		Status& operator=(const int newStatus);
		Status& clear();

		
	};
	std::ostream& operator <<(std::ostream& ostr, const Status& status);
}
#endif 
