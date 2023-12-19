/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "Item.h"
#include "Date.h"
namespace sdds
{
	class Perishable : public Item
	{
	private:
		Date Expiry;
		char* Instructions; 
	public:
		Perishable();

		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& perishable);
		~Perishable();

		const Date& expiry()const;

		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(istream& istr);
	};
}

#endif 

