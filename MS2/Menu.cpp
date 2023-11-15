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

#include "Menu.h"

using namespace std;

namespace sdds {
	Menu::Menu(const char* content) {
		int count{ 0 };
		m_content = nullptr;
		if (content) {
			m_content = new char[strlen(content) + 1];
			for (size_t i = 0; i < strlen(content); i++) if (content[i] == '\t') count++;

			if (count <= 15) {
				strcpy(m_content, content);
			}
			else {
				delete[] m_content;
				m_content = nullptr;
			}
		}

	}
	Menu::~Menu() {
		delete[] m_content;
		m_content = nullptr;
	}
	unsigned int Menu::run() const {
		int input{ 0 };
		if (m_content) {
			int index{ 1 };
			cout << index << "- ";
			for (size_t i = 0; i < strlen(m_content); i++) {
				if (m_content[i] == '\t') {
					cout << endl;
					cout << ++index << "- ";
				}
				else cout << m_content[i];
			}
			cout << endl << "---------------------------------" << endl << "0- Exit" << endl << "> ";

			do {

				cin >> input;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid Integer, retry: ";
					cin.clear();
					input = -1;
				}
				else if (input < 0 || input > index) {
					cout << "Value out of range [0<=val<=" << index << "]: ";
					cin.clear();
				}
			} while (input < 0 || input > index);
		}
		else cout << "Invalid Menu!" << endl;
		return input;
	}

	void Menu::printSelection(unsigned int selection) {
		unsigned int counter{ 1 };
		for (size_t i = 0; i < strlen(m_content); i++) {
			if (m_content[i] == '\t') {
				counter++;
				i++;
			}
			if (counter == selection) cout << m_content[i];
		}
	}


}