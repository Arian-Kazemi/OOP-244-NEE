/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SDDS_MENU_H
#define SDDS_MENU_H


namespace sdds
{
	const unsigned int MAX_OPT_NUM = 15;
	class Menu
	{
		unsigned int m_optNum;	
		char* m_menuCont;
		

	public:
		Menu();
		Menu(unsigned int inOptNum, std::string inMenuCont);
		Menu(const Menu& src) = delete; 
		void operator=(const Menu& src) = delete; 
		~Menu();

		unsigned int run() const;
	};
}

#endif