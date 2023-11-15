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
#include <iomanip>
#include <cstring>

#include "AidMan.h"
#include "Utils.h"


using namespace std;

namespace sdds {
	unsigned int AidMan::menu() const {
		int year, month, day;
		ut.getSystemDate(&year, &month, &day);
		cout << "Aid Management System" << endl << "Date: ";
		cout << setfill('0') << setw(4) << year << "/"
			<< setw(2) << month << "/"
			<< setw(2) << day << endl;
		cout << "Data file: " << ((m_fileName) ? m_fileName : "No file") << endl << endl;

		return m_menu.run();
	}
	AidMan::AidMan(const char* fileName) {
		if (fileName) {
			m_fileName = new char[strlen(fileName) + 1];
			strcpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
	}
	AidMan::~AidMan() {
		delete[] m_fileName;
		m_fileName = nullptr;
	}
	void AidMan::run() {
		unsigned int input{};
		do {
			input = menu();
			if (input == 0) cout << "Exiting Program!" << endl;
			else {
				cout << endl << "****";
				m_menu.printSelection(input);
				cout << "****" << endl << endl;
			}
		} while (input != 0);
	}
}