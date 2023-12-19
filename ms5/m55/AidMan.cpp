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
#include <iomanip>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"
#include "Perishable.h"


using namespace std;
namespace sdds
{
	unsigned int AidMan::menu() const
	{
		string appName = "Aid Management System";
		Date appDate;

		cout << appName << endl;
		cout << "Date: " << appDate << endl;
		if (m_fileName == nullptr) {
			cout << "Data file: " << "No file" << endl;
		}
		else {
			cout << "Data file: " << m_fileName << endl;
		}
		cout << "---------------------------------" << endl;

		return m_mainMenu.run();
	}

	
	AidMan::AidMan()
	{
		m_fileName = nullptr;
		m_iProdItems = 0;
		for (int i = 0; i < sdds_max_num_items; i++) {
			m_iProdPtrs[i] = nullptr;
		}
	}

	
	AidMan::~AidMan()
	{
		delete[] m_fileName;
		m_fileName = nullptr;
		deallocate();
	}

	void AidMan::run()
	{
		bool exit = false;
		string temp = { 0 };

		
		char userSelect[2] = { 0 };
		int rowId = 0;

		do {
			unsigned int selection = menu();
			if (m_fileName == nullptr && selection != 7) {
				selection = 7;
			}
			switch (selection) {
			case 1:
				
				cout << endl << "****List Items****" << endl;
				list();
				
				cout << "Enter row number to display details or <ENTER> to continue:\n> ";
				cin.ignore();
				cin.read(userSelect, 1);
				userSelect[1] = '\0';
				if (strcmp(userSelect, "\n") == 0) {
					
					cout << endl;
				}
				else { 
					rowId = stoi(userSelect);
					m_iProdPtrs[rowId - 1]->linear(false);
					cout << *m_iProdPtrs[rowId - 1] << endl;
				}

				break;
			case 2:
				
				cout << endl << "****Add Item****" << endl;
				addItem();
				break;
			case 3:
				
				cout << endl << "****Remove Item****" << endl;
				doActionByDescr("remove");
				break;
			case 4:
				
				cout << endl << "****Update Quantity****" << endl;
				doActionByDescr("update");
				break;
			case 5:
				
				cout << endl << "****Sort****" << endl;
				sort();
				break;
			case 6:
				
				cout << endl << "****Ship Items****" << endl << endl;
				break;
			case 7:
				
				cout << endl << "****New/Open Aid Database****" << endl;
				cout << "Enter file name: ";
				cin >> temp;
				ut.alocpy(m_fileName, temp.c_str());
				load();
				cout << m_iProdItems << " records loaded!" << endl << endl;
				break;
			case 0:
				
				exit = true;
				cout << "Exiting Program!" << endl;
				break;
			}

		} while (exit == false);

		save();
	}

	
	void AidMan::save()
	{
		if (m_fileName != nullptr) {
			ofstream file(m_fileName); 
			for (int i = 0; i < m_iProdItems; i++) {
				m_iProdPtrs[i]->save(file);
				file << endl;
			}
		}
		
	}

	
	void AidMan::deallocate()
	{
		if (m_iProdItems > 0) {
			for (int i = 0; i < m_iProdItems; i++) {
				delete m_iProdPtrs[i];
				m_iProdPtrs[i] = nullptr;
			}
			delete[] m_fileName;
			m_iProdItems = 0;
		}
	}

	bool AidMan::load()
	{
		bool recAdded = false;
		int selection = 0, idx = 0;

		ifstream file(m_fileName);
		if (!file.is_open()) { 
			cout << "Failed to open " << m_fileName << " for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!\n0- Exit" << endl;
			selection = ut.getInt(0, 1, "> ", nullptr);
			if (selection == 1) {
				
				ofstream newFile(m_fileName);
			}
		}
		else { 		
			do {

				if (file.peek() == '1' || file.peek() == '2' || file.peek() == '3') { 
					m_iProdPtrs[idx] = new Perishable;
					if (m_iProdPtrs[idx] != nullptr) { 
						m_iProdPtrs[idx]->load(file);
						if (m_iProdPtrs[idx]) { 
							m_iProdItems++;
							idx++;
							recAdded = true;
						}
						else { 
							delete m_iProdPtrs[idx];
						}
					}
				}
				else if (file.peek() == '4' || file.peek() == '5' || file.peek() == '6' || file.peek() == '7' || file.peek() == '8' || file.peek() == '9') { //If the upcoming record is non-perishable
									
					m_iProdPtrs[idx] = new Item;
					if (m_iProdPtrs[idx] != nullptr) { 
						m_iProdPtrs[idx]->load(file);
						if (m_iProdPtrs[idx]) { 
							m_iProdItems++;
							idx++;
							recAdded = true;
						}
						else { 
							delete m_iProdPtrs[idx];
						}
					}
				}
				else {
					
					file.setstate(ios::failbit);
				}
			} while (!file.eof());
		}

		return recAdded;
	}

	
	int AidMan::list(const char* sub_desc)
	{
		ofstream outFile(m_fileName);
		int recsDisplayed = 0;

		bool isEmpty = (m_iProdItems == 0) ? true : false; 
		if (!isEmpty) {

			cout.width(4);
			cout << "ROW" << " | ";
			cout.width(5);
			cout << "SKU " << " | ";
			cout.width(35);
			cout << left << "Description" << " | ";
			cout.width(4);
			cout << "Have" << " | ";
			cout.width(4);
			cout << "Need" << " | ";
			cout.width(7);
			cout << " Price " << " | ";
			cout.width(6);
			cout << left << "Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

			if (sub_desc == nullptr) { 
				for (int i = 0; i < m_iProdItems; i++) {
					m_iProdPtrs[i]->linear(true);
					cout.width(4);
					cout << right << i + 1;
					cout << " | " << *m_iProdPtrs[i] << endl;
					recsDisplayed++;
				}
			}
			else if (sub_desc != nullptr) {
				
				for (int i = 0; i < m_iProdItems; i++) {
					if (*m_iProdPtrs[i] == sub_desc) { 
						m_iProdPtrs[i]->linear(true);
						cout.width(4);
						cout << right << i + 1;
						cout << " | " << *m_iProdPtrs[i] << endl;
						recsDisplayed++;
					}
				}
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------";

		}
		else {
			cout << "The list is emtpy!" << endl;
		}
		cout << endl;
		return recsDisplayed;
	}

	
	int AidMan::search(int sku) const
	{
		int idx = 0;
		ifstream file(m_fileName);

		for (int i = 0; i < m_iProdItems; i++) {
			if (*m_iProdPtrs[i] == sku) { 
				idx = i;
				i = m_iProdItems;
			}
			else {
				idx = -1;
			}
		}

		return idx;
	}

	
	void AidMan::addItem()
	{
		int selection;
		int inSKU;

		if (m_fileName == nullptr) {
			cout << "No data file is open!" << endl;
		}
		else if (m_iProdItems == sdds_max_num_items) {
			cout << "Database full!" << endl;

		}
		else {
			cout << "1- Perishable\n2- Non-Perishable\n-----------------\n0- Exit" << endl;
			selection = ut.getInt(0, 2, "> ", nullptr);

			if (selection == 0) {
				cout << "Aborted\n";
			}
			else {

				if (selection == 1) { 
					m_iProdPtrs[m_iProdItems] = new Perishable;
				}
				else if (selection == 2) { 
					m_iProdPtrs[m_iProdItems] = new Item;
				}
				inSKU = m_iProdPtrs[m_iProdItems]->readSku(cin);

				if (search(inSKU) == -1) { 
					m_iProdPtrs[m_iProdItems]->read(cin);
					cout << endl;
					if (m_iProdPtrs[m_iProdItems]) { 
						m_iProdItems++;
					}
					else {
						
						delete m_iProdPtrs[m_iProdItems];
					}
				}
				else {
					cout << "Sku: " << inSKU << " is already in the system, try updating quantity instead.\n" << endl;
					delete m_iProdPtrs[m_iProdItems];
				}
			}
		}
	}

	
	void AidMan::doActionByDescr(const char* action)
	{
		string inDescr = { 0 };
		int inSKU;
		int idxFound;

		cout << "Item description: ";
		cin >> inDescr;

		if (list(inDescr.c_str()) > 0) { 
			inSKU = ut.getInt(10000, 99999, "Enter SKU: ", nullptr);
			idxFound = search(inSKU);
			if (idxFound == -1) { 
				cout << "SKU not found!\n";
			}
			else { 
				if (strcmp(action, "remove") == 0) { 
					remove(idxFound);
				}
				else if (strcmp(action, "update") == 0) { 
					updateQty(idxFound);
				}
			}
		}
		else {
			cout << "No matches found!\n";
		}
	}

	
	void AidMan::remove(int index)
	{
		int confirm;
		int reps = (m_iProdItems - 1) - index;
		cout << "Following item will be removed: " << endl;
		m_iProdPtrs[index]->linear(false);
		m_iProdPtrs[index]->display(cout);
		cout << endl;
		cout << "Are you sure?\n1- Yes!\n0- Exit\n";
		confirm = ut.getInt(0, 1, "> ", nullptr);

		switch (confirm) {
		case 1: 
			delete m_iProdPtrs[index]; 
			for (int i = 0; i < reps; i++) {
				m_iProdPtrs[index + i] = m_iProdPtrs[index + (i + 1)]; 
			}
			m_iProdPtrs[m_iProdItems - 1] = nullptr;
			cout << "Item removed!\n" << endl;
			break;
		case 0: 
			cout << "Aborted!\n" << endl;
			break;
		}
	}

	
	void AidMan::updateQty(int index)
	{
		int confirm;
		int maxNeeded;
		int inputQty;

		cout << "1- Add\n2- Reduce\n0- Exit\n";
		confirm = ut.getInt(0, 2, "> ", nullptr);

		switch (confirm) {
		case 1: 
			maxNeeded = m_iProdPtrs[index]->qtyNeeded() - m_iProdPtrs[index]->qty(); 
			if (maxNeeded == 0) { 
				cout << "Quantity Needed already fulfilled!\n" << endl;
			}
			else {
				inputQty = ut.getInt(1, maxNeeded, "Quantity to add: ", nullptr);
				*m_iProdPtrs[index] += inputQty;
				cout << inputQty << " items added!\n" << endl;
			}
			break;
		case 2: 
			if (m_iProdPtrs[index]->qty() == 0) { 
				cout << "Quaintity on hand is zero!\n" << endl;
			}
			else {
				inputQty = ut.getInt(1, m_iProdPtrs[index]->qty(), "Quantity to reduce: ", nullptr);
				*m_iProdPtrs[index] -= inputQty;
				cout << inputQty << " items removed!\n" << endl;
			}
			break;
		case 0: 
			cout << "Aborted!\n" << endl;
			break;
		}
	}

	void AidMan::sort()
	{
		iProduct* temp;

		for (int i = 0; i < m_iProdItems; i++) {
			for (int j = i + 1; j < m_iProdItems; j++) {
				if (*m_iProdPtrs[i] < *m_iProdPtrs[j]) {
					temp = m_iProdPtrs[i]; 
					m_iProdPtrs[i] = m_iProdPtrs[j]; 
					m_iProdPtrs[j] = temp; 
				}
			}
		}

		cout << "Sort completed!\n" << endl;
	}

	
	bool operator<(const iProduct& lhs, const iProduct& rhs)
	{
		return (lhs.qtyNeeded() - lhs.qty()) < (rhs.qtyNeeded() - rhs.qty());
	}
}