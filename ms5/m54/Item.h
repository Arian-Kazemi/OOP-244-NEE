/*************************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/



#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "iProduct.h"

namespace sdds
{
	
	class Item: public iProduct
	{
		double m_price;
		int m_qtyOnHand;
		int m_neededQty;	
		char* m_descr;		
		bool m_linear;		

		void setEmpty();			

	protected:
		Status m_itemState; 
		int m_SKU;		

		bool linear() const;

	public:
		Item(); 
		~Item();
		Item(const Item& inObj);
		Item& operator=(const Item& inObj);

		int qtyNeeded() const;
		int qty() const;
		operator double() const;
		operator bool() const;

		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);

		void clear();

		bool operator==(int sku) const;
		bool operator==(const char* description) const;

		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);				
		std::ostream& display(std::ostream& ostr) const;
		int readSku(std::istream& istr);
		std::istream& read(std::istream& istr);

	};
}

#endif 
