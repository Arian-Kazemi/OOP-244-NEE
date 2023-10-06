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
#include "Label.h"
#include <iomanip>

using namespace sdds;

Label::Label() {   //default constructor of the Label class.
	strcpy(m_frameArg, "+-+|+-+|");
	m_content = nullptr;
}

Label::Label(const char* frameArg) {   // constructor initializes m_frameArg with provided frameArg and sets m_content to nullptr.
    strcpy(m_frameArg, frameArg);
    m_content = nullptr;
}

Label::Label(const char* frameArg, const char* content) {
	strcpy(m_frameArg, frameArg);
	m_content = new char [strlen(content) + 1];
	text(content);
}

Label::~Label() {   //destructor of the Label class.
	delete[] m_content;
}

std::istream& Label::readLabel() {
	char content[71];

	std::cout << "> ";
	std::cin.clear();
	std::cin.getline(content, 71, '\n');
	
	text(content);

	return std::cin;
}

std::ostream& Label::printLabel() const {
	if (m_content) {
		const int labelSize = strlen(m_content) + 3;
		
		std::cout << m_frameArg[0] << std::setfill(m_frameArg[1]) << std::setw(labelSize)     << m_frameArg[2] << std::endl
		          << m_frameArg[7] << std::setfill(' ')       << std::setw(labelSize)     << m_frameArg[3] << std::endl
	              << m_frameArg[7] << " " << m_content << " "     << m_frameArg[3]            << std::endl
		          << m_frameArg[7] << std::setfill(' ')       << std::setw(labelSize)     << m_frameArg[3] << std::endl
		          << m_frameArg[6] << std::setfill(m_frameArg[5]) << std::setw(labelSize)     << m_frameArg[4];
	}

	return std::cout;
}


Label& Label::text(const char* content) {
	delete[] m_content;

	m_content = new char [strlen(content) + 1];
	strcpy(m_content, content);
	return *this;
}
