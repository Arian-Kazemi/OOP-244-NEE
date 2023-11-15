/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
	class Menu {
		char* m_content{};

	public:
		Menu(const char* content);
		~Menu();
		unsigned int run() const;
		void printSelection(unsigned int selection);
	};
}

#endif // !SDDS_MENU_H
