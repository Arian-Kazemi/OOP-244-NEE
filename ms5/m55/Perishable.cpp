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
#include <fstream>
#include <string>
#include <string.h>
#include "Perishable.h"
#include "Utils.h"

using namespace std;

namespace sdds
{

	void Perishable::setEmpty()
	{
		m_handInstr = nullptr;
	}

	
	Perishable::Perishable()
	{
		setEmpty();
	}

	
	Perishable::~Perishable()
	{
		delete[] m_handInstr;
		m_handInstr = nullptr;
	}

	
	Perishable::Perishable(const Perishable& inObj): Item(inObj) 
	{
		setEmpty();
		if (m_handInstr != nullptr) {
			m_handInstr = nullptr;
		}
		delete[] m_handInstr;

		
		ut.alocpy(m_handInstr, inObj.m_handInstr);	
		m_expDate = inObj.m_expDate;
	}

	
	Perishable& Perishable::operator=(const Perishable& inObj)
	{
		
		if (&(*this) != &inObj) {
			
			delete[] m_handInstr;
			setEmpty();

			Item::operator=(inObj);
			ut.alocpy(m_handInstr, inObj.m_handInstr);
			m_expDate = inObj.m_expDate;
		}
		else {
			delete[] m_handInstr;
			setEmpty();
		}
		return *this;
	}

	Perishable::operator bool()const
	{
		return (m_SKU >= 10000 && m_SKU <= 39999) && m_itemState;
	}

	
	const Date& Perishable::expiry()
	{
		return m_expDate;
	}

	
	int Perishable::readSku(std::istream& istr)
	{
		m_SKU = ut.getInt(10000, 39999, "SKU: ", "Invalid Integer");
		return m_SKU;
	}

	
	std::ofstream& Perishable::save(std::ofstream& ofstr) const
	{
		Date temp = m_expDate; 
		temp.formatted(false); 
		
		if (m_itemState) {
			Item::save(ofstr);
			ofstr << "\t";
			if (m_handInstr != nullptr && strlen(m_handInstr) > 0) { 
				ofstr << m_handInstr;
			}
			ofstr << "\t";
			temp.write(ofstr); 
		}
		return ofstr;
	}

	
	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		string temp = { 0 };

		if (m_handInstr != nullptr) {
			delete[] m_handInstr;
			m_handInstr = nullptr;
		}
		m_handInstr = nullptr;
		
		if (ifstr.peek() != EOF) {
			Item::load(ifstr); 
			getline(ifstr, temp, '\t');
			ut.alocpy(m_handInstr, temp.c_str());
			m_expDate.read(ifstr);
			ifstr.ignore();
		}
		else {
			
			ifstr.ignore(1);
		}

		if (ifstr.fail()) {
			m_itemState = "Input file stream read (perishable) failed!";
		}
		return ifstr;		
	}

	
	std::ostream& Perishable::display(std::ostream& ostr) const
	{
		Date temp = m_expDate; 
		temp.formatted(true);

		if (m_SKU > 0) {
			if (m_itemState) {
				if (Item::linear()) {
				
					Item::display(ostr);
					if (m_handInstr != nullptr && strlen(m_handInstr) > 0) { 
						ostr << "*";
					}
					else {
						ostr << ' ';
					}
					m_expDate.write(ostr);
				}
				else {
					
					ostr << "Perishable ";
					Item::display(ostr);
					ostr << "Expiry date: ";
					temp.write(ostr);	
					ostr << endl;
					if (m_handInstr != nullptr && strlen(m_handInstr) > 0) { 
						ostr << "Handling Instructions: " << m_handInstr;
						ostr << endl;
					}
					
				}
			}
			else {
				
				m_itemState.print(ostr);
			}
			
		}

		return ostr;
	}

	
	std::istream& Perishable::read(std::istream& istr)
	{
		string temp = { 0 };

		Item::read(istr);
		delete[] m_handInstr;
		setEmpty();

		cout << "Expiry date (YYMMDD): ";
		m_expDate.read(istr);
		istr.ignore(2000, '\n');

		cout << "Handling Instructions, ENTER to skip: ";
		getline(istr, temp);

		if (temp.length() != 0) {	
			ut.alocpy(m_handInstr, temp.c_str());
		} 

		if (istr.fail()) {
			m_itemState = "Perishable console date entry failed!";
		}
		return istr;
	}
}