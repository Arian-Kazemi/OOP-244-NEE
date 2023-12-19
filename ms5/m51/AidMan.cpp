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


#include "AidMan.h"
#include "Perishable.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<limits>


using namespace std;
namespace sdds {

	unsigned int AidMan::menu() const
	{

		
			cout << "Aid Management System" << endl;
			cout << "Date: " << c_date << endl;

			
			cout << "Data file: " << ((fileName) ? fileName : "No file")
				<< "\n"
				<< "---------------------------------" << endl;
		

		
		return mainMenu.run();
	}
	AidMan::AidMan(const char* file) :
		fileName(nullptr),
		mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),
		c_date(Date())
	{

	}

	void AidMan::run() {
		unsigned int choice{};
		ifstream ifstr;
		


		do {
			choice = menu();
			
			if ( (choice == 1 || choice == 2|| choice==3 || choice==4 || choice==5 || choice==6)&&(fileName==nullptr)) {
				choice = 7; 
			}
			switch (choice) { 
			case 1:

					std::cout << "\n****List Items****\n";
					list();
					break;
				
					
			case 2:
					std::cout << "\n****Add Item****\n\n";break;
			case 3:
					std::cout << "\n****Remove Item****\n\n";break;
			case 4:
					std::cout << "\n****Update Quantity****\n\n";break;
			case 5:
					std::cout << "\n****Sort****\n\n";break;
			case 6:
					std::cout << "\n****Ship Items****\n\n";break;
			case 7:
					std::cout << "\n****New/Open Aid Database****\n";
					load("data.dat");
					break;
			case 0:
					std::cout << "Exiting Program!\n";break;
			default:
					std::cout << "Invalid option!\n\n";break;
			}

		} while (choice!=0);
		ifstr.close();
		
	}
	void AidMan::save()
	{
		if (fileName)
		{
			
			ofstream outfile(fileName);

			
			if (outfile.is_open())
			{
				for (int i = 0; i < noOfRecs; i++)
				{
				
					Product[i]->save(outfile);
					outfile << '\n';
				}
				

				
				outfile.close();
				
			}
			else
			{
				cout << "Failed to open " << fileName << " for writing!" << endl;
			}
		}
	}

	bool AidMan::load(const char* filename)
	{
		if (fileName)
		{
			delete[] fileName;
			fileName = nullptr;
		}
		if (filename != nullptr && filename[0] != '\0') {
			fileName = new char[strlen(filename) + 1];
			strcpy(fileName, filename);
		}
		ifstream ifstr(filename);
		
		if (!ifstr.is_open())
		{
			cout << "Failed to open"<<filename<< "for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			int choice = 0;
			cin >> choice;
			if (choice==1)
			{
				ofstream outfile(fileName);
				if (!outfile.is_open())
				{
					cout << "Failed to create new data file!" << endl;
					return false;
				}
				outfile.close();
			}
			return false;
		}

		
		noOfRecs = 0;

		
		while (!ifstr.eof() && noOfRecs < sdds_max_num_items)
		{
			
			if (ifstr.peek() >= '1' && ifstr.peek() <= '3')
			{
				
				Product[noOfRecs] = new Perishable;
			}
			
			else if (ifstr.peek() >= '4' && ifstr.peek() <= '9')
			{
				
				Product[noOfRecs] = new Item;
			}
			else
			{
				
				ifstr.clear();
				ifstr.ignore(1000, '\n');
				continue;  
			}

			
			Product[noOfRecs]->load(ifstr);

			
			if (*Product[noOfRecs])
			{
				noOfRecs++;
			}
		}
		if (*this)
		{
			cout << "Enter file name: " << fileName << endl;
			cout << noOfRecs << " records loaded!\n" << endl;
			
		}
		save();
		
		return (noOfRecs > 0);
	}


	int AidMan::list(const char* sub_desc) const
	{
		int rowNum = 0;
		int number = 0;
		bool validInput = true;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < noOfRecs; i++)
		{

			if (sub_desc == nullptr)
			{
				Product[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
			else if (sub_desc){
				
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		do {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore();
			if (cin.peek() == '\n') {
			
				cout << "\n";
				break;
			}
			cin >> number;
			if (number >= 1 && number <= rowNum) {
				Product[number - 1]->linear(false);
				Product[number - 1]->display(cout);
				cout << '\n' << '\n';
				

			}
			else {
				cout << "Invalid input. Please enter a valid row number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cin.get(); 

		} while (!validInput);

		
		return rowNum;

	}

	void AidMan::deallocate()
	{
		for (size_t i = noOfRecs; i > 0;)
		{
			--i;
			delete Product[i];
			Product[i] = nullptr;
		}
		noOfRecs = 0;
	}


	AidMan::~AidMan()
	{
		delete[] fileName;
		fileName = nullptr;
		deallocate();

	}



}

