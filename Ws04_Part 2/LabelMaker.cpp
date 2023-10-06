/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#include <iostream>
#include "Label.h"
#include "LabelMaker.h"

using namespace sdds;

LabelMaker::LabelMaker(int noOfLabels) {
	m_noOfLabels = noOfLabels;
	m_labels = new Label [m_noOfLabels];
}

void LabelMaker::readLabels() const {
	std::cout << "Enter " << m_noOfLabels << " labels:" << std::endl;
	for (int i = 0; i < m_noOfLabels; i++) {
		std::cout << "Enter label number " << i+1 << std::endl;
		m_labels[i].readLabel();
	}
}

void LabelMaker::printLabels() const {
	for (int i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel();
			std::cout << std::endl;
	}
}

LabelMaker::~LabelMaker() {
	delete[] m_labels;
}
