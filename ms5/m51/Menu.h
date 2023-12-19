/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
namespace sdds {
	class Menu {
		char* m_options;
		

	public:
		Menu(const char* options);
		unsigned int run() const;
		~Menu();
	};
}
#endif