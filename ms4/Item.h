/***********************************************************************
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
#include "Status.h"
using namespace std;
namespace sdds
{
	class Item : public iProduct
	{
	private:
		double Price;
		int Quantity;
		int Quantity_Needed;
		char* Description;
	protected:
		bool Linear;
		Status state;
		int SKU;
		bool linear();
	public:
		Item();
		Item(const Item& item);
		Item& operator=(const Item& item);
		~Item();
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(istream& istr);
	};
}

#endif // !SDDS_ITEM_H