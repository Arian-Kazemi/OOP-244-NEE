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
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	
	void Item::setEmpty()
	{
		m_price = 0.0;
		m_qtyOnHand = 0;
		m_neededQty = 0;
		m_descr = nullptr;
		m_linear = false;
		m_SKU = 0;
	}

	
	bool Item::linear() const
	{
		return m_linear;
	}

	
	Item::Item()
	{
		setEmpty();
	}

	
	Item::~Item()
	{
		delete[] m_descr;
		m_descr = nullptr;
	}

	
	Item::Item(const Item& inObj)
	{
		setEmpty();
		if (m_descr != nullptr) {
			m_descr = nullptr;
		}
		delete[] m_descr;
		

		m_price = inObj.m_price;
		m_qtyOnHand = inObj.m_qtyOnHand;
		m_neededQty = inObj.m_neededQty;
		if (inObj.m_descr != nullptr) {
			ut.alocpy(m_descr, inObj.m_descr);
		}
		m_linear = inObj.m_linear;
		m_SKU = inObj.m_SKU;
		m_itemState = inObj.m_itemState; 
	}

	
	Item& Item::operator=(const Item& inObj)
	{
		
		if (&(*this) != &inObj) {
			
			delete[] m_descr;
			setEmpty();

			m_price = inObj.m_price;
			m_qtyOnHand = inObj.m_qtyOnHand;
			m_neededQty = inObj.m_neededQty;
			if (inObj.m_descr != nullptr) {
				ut.alocpy(m_descr, inObj.m_descr);
			}
			m_linear = inObj.m_linear;
			m_SKU = inObj.m_SKU;
		}
		else {
			delete[] m_descr;
			setEmpty();
		}
		return *this;
	}

	
	int Item::qtyNeeded() const
	{
		return m_neededQty;
	}

	
	int Item::qty() const
	{
		return m_qtyOnHand;
	}


	Item::operator double() const
	{
		return m_price;
	}

	
	Item::operator bool() const
	{
		return m_itemState;
	}


	
	int Item::operator-=(int qty)
	{
		m_qtyOnHand -= qty;
		return m_qtyOnHand;
	}

	
	int Item::operator+=(int qty)
	{
		m_qtyOnHand += qty;
		return m_qtyOnHand;
	}

	
	void Item::linear(bool isLinear)
	{
		m_linear = isLinear;
	}
	
	void Item::clear()
	{
		
		m_itemState.clear();
	}

	
	bool Item::operator==(int sku) const
	{
		return m_SKU == sku;
	}
	
	
	bool Item::operator==(const char* description) const
	{
		bool result = false;
		string temp(m_descr);

		if (temp.find(description) != string::npos) {
			result = true;
		}

		return result;
	}

	
	std::ofstream& Item::save(std::ofstream& ofstr) const
	{
		if(m_itemState) 
		{
			
			ofstr << m_SKU << "\t" << m_descr << "\t" << m_qtyOnHand << "\t" << m_neededQty << "\t" << fixed << setprecision(2) << m_price;
	
		}
		
		return ofstr;
	}

	
	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		m_itemState.clear();
	
		if (m_descr != nullptr) {
			delete[] m_descr;
			m_descr = nullptr;
		}
		
		m_descr = nullptr;

		if (ifstr.peek() != EOF) {
		
			string temp = { 0 };

			getline(ifstr, temp, '\t');
			m_SKU = atoi(temp.c_str());

			getline(ifstr, temp, '\t');
			ut.alocpy(m_descr, temp.c_str());

			getline(ifstr, temp, '\t');
			m_qtyOnHand = atoi(temp.c_str());

			getline(ifstr, temp, '\t');
			m_neededQty = atoi(temp.c_str());

			
			
			int beginPos = ifstr.tellg();
			getline(ifstr, temp, '\t');
			if (temp.find('\n') != string::npos) { 
				ifstr.seekg(beginPos, ios_base::beg); 
				getline(ifstr, temp, '\n'); 
			}
			m_price = stod(temp.c_str());

			
		}
		else {
		
			ifstr.ignore(1);
		}

		if (ifstr.fail()) {
			m_itemState = "Input file stream read failed!";
		}
		return ifstr;
	}

	
	std::ostream& Item::display(std::ostream& ostr) const
	{
		if (m_descr != nullptr) {
			if (m_itemState) {
				if (m_linear) {
				
					ostr << setfill(' '); 
					ostr.width(5);
					ostr << m_SKU << " | ";
					if (strlen(m_descr) <= 35) {
						ostr << m_descr;
						for (unsigned int i = 0; i < 35 - strlen(m_descr); i++) {
							ostr << " ";
						}
					}
					else {
						for (int i = 0; i < 35; i++) {
							ostr << m_descr[i];
						}
					}
					ostr << " | ";
					ostr.width(4);
					ostr << m_qtyOnHand;
					ostr << " | ";
					ostr.width(4);
					ostr << m_neededQty;
					ostr << " | ";
					ostr.width(7);
					ostr.precision(2);
					ostr << fixed << m_price;
					ostr << " |";
				}
				else {
					
					ostr << "AMA Item:" << endl;
					ostr << m_SKU << ": " << m_descr << endl;
					ostr << "Quantity Needed: " << m_neededQty << endl;
					ostr << "Quantity Available: " << m_qtyOnHand << endl;
					ostr << "Unit Price: $" << m_price << endl;
					int qtyNotOnHand = m_neededQty - m_qtyOnHand;
					ostr << fixed << setprecision(2) << "Needed Purchase Fund: $" << (qtyNotOnHand)*m_price << endl;
				}
			}
			else {
				
				m_itemState.print(ostr);
			}
		}
		
		
		return ostr;
	}

	
	int Item::readSku(std::istream& istr)
	{
		m_SKU = ut.getInt(40000, 99999, "SKU: ", "Invalid Integer");
		return m_SKU;
	}

	
	std::istream& Item::read(std::istream& istr)
	{
		string temp = { 0 };

		delete[] m_descr;
		m_itemState.clear();
		istr.ignore(2000, '\n');

		cout << "AMA Item:" << endl;
		cout << "SKU: " << m_SKU << endl;
		cout << "Description: ";
		
		getline(istr, temp);
		ut.alocpy(m_descr, temp.c_str());
		m_neededQty = ut.getInt(1, 9999, "Quantity Needed: ", "Invalid Integer");
		m_qtyOnHand = ut.getInt(0, m_neededQty, "Quantity On Hand: ", "Invalid Integer");
		m_price = ut.getDouble(0.00, 9999.00, "Unit Price: $", "Invalid number");
		if (istr.fail()) {
			m_itemState = "Console entry failed!";
		}
		return istr;
	}
	
}