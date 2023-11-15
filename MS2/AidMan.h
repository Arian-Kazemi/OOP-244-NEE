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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include "Menu.h"

namespace sdds {
	class AidMan {
		char* m_fileName{};
		Menu m_menu{ "List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database" };

		unsigned int menu() const;

	public:
		AidMan(const char* fileName);
		~AidMan();
		void run();
	};
}

#endif // !SDDS_AIDMAN_H
