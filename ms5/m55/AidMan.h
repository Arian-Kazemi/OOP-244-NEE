/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"

namespace sdds
{
	const int sdds_max_num_items = 100;
	class AidMan
	{
		char* m_fileName;
		Menu m_mainMenu = {7, "1- List Items\n"
								"2- Add Item\n"
								"3- Remove Item\n"
								"4- Update Quantity\n"
								"5- Sort\n"
								"6- Ship Items\n"
								"7- New/Open Aid Database\n"
								"---------------------------------\n" };
		iProduct* m_iProdPtrs[sdds_max_num_items];	
		int m_iProdItems;	
			
		unsigned int menu() const;
		void save();
		void deallocate();
		bool load();
		int list(const char* sub_desc = nullptr);
		int search(int sku) const;
		void addItem();
		void doActionByDescr(const char* action);
		void remove(int index);
		void updateQty(int index);
		void sort();

	public:
		AidMan();
		AidMan(const AidMan& src) = delete;  
		void operator=(const AidMan&) = delete;  
		~AidMan();
		void run();
	};

	bool operator<(const iProduct& lhs, const iProduct& rhs);
}

#endif 
