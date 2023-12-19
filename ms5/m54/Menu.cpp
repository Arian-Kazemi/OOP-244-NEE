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
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	
	Menu::Menu()
	{
		m_menuCont = nullptr;
		m_optNum = 0;
	}

	
	Menu::Menu(unsigned int inOptNum, std::string inMenuCont)
	{
		if (inOptNum > MAX_OPT_NUM || strlen(inMenuCont.c_str()) == 0) {
			
			delete[] m_menuCont;
			m_menuCont = nullptr;
			m_optNum = 0;
		}
		m_optNum = inOptNum;
		m_menuCont = nullptr;
		m_menuCont = new char[strlen(inMenuCont.c_str()) + 1];
		strcpy(m_menuCont, inMenuCont.c_str());
	}

	
	Menu::~Menu()
	{
		delete[] m_menuCont;
		m_menuCont = nullptr;
	}

	
	unsigned int Menu::run() const
	{
		cout << m_menuCont << "0- Exit" << endl;
		return ut.getInt(0, m_optNum, "> ", nullptr); 
	}

}