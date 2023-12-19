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

namespace sdds
{
	class Status
	{
		char* m_desc;
		int m_code;

	public:
		Status();
		explicit Status(char* desc);
		Status(const Status& inObj);
		~Status();
		void destruct();

		
		Status& operator=(std::string desc);
		Status& operator=(int code);

		operator int() const;
		operator const char*() const;
 		operator bool() const;

		Status& clear();

		std::ostream& print(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream&, const Status& inObj);
}
#endif 
