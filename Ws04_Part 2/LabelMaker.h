/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H



namespace sdds {


	class LabelMaker{   //declaration of the `LabelMaker
		Label* m_labels;
		int  m_noOfLabels;


	public:
		LabelMaker(int noOfLabels);
		void readLabels() const;
		void printLabels() const;
		~LabelMaker();
	};
}

#endif
