/*************************************************************************
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

#include "Item.h"
#include "Date.h"

namespace sdds
{
	
	class Perishable : public Item
	{
		Date m_expDate;		
		char* m_handInstr;

		void setEmpty();

	public:
		Perishable();
		~Perishable();

		Perishable(const Perishable& inObj);
		Perishable& operator=(const Perishable& inObj);
		operator bool()const;

		const Date& expiry();

		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);

	};

}

#endif 

