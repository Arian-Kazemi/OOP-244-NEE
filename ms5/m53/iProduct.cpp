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
#include "iProduct.h"

using namespace std;
namespace sdds
{
	
	std::ostream& operator<<(std::ostream& ostr, const iProduct& inObj)
	{
		inObj.display(ostr);
		return ostr;
	}

	
	std::istream& operator>>(std::istream& istr, iProduct& inObj)
	{
		inObj.read(istr);
		return istr;
	}
}