/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/





#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {

	class Label{    //declaring of label1 class
		char m_frameArg[9] {};   // This array stores the frame characters for the label. 
		char* m_content;  //This pointer will hold the content 
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();

		std::istream&readLabel();   //member function reads a label from the standard input
		std::ostream&printLabel()const;

		Label& text(const char* content);
	};
}

#endif
