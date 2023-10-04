/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
	bool load(Employee& arg) {
		bool ok = false;
		char name[128];
		if ((read(arg.m_empNo) == 1) && (read(arg.m_salary) == 1) && (read(name) == 1)) {
			ok = true;
			int i = strlen(name);
			arg.m_name = new char[i + 1];
			strcpy(arg.m_name, name);
		}
		
		return ok;
	}

	// TODO: Finish the implementation of the 0 arg load function 
	bool load() {
		bool ok = false;
		int i = 0;
		if (openFile(DATAFILE))
		{

			ok = true;
			noOfEmployees = noOfRecords();

			employees = new Employee[noOfEmployees];

			for (i = 0; i < noOfEmployees; i++)
			{
				load(employees[i]);

			}
			closeFile();
			
		}
		else {
			cout << "Could not open data file: " << DATAFILE << endl;
		}
		return ok;
	}

	// TODO: Implementation for the display functions go here
	void display(const Employee& employee)
	{
		std::cout << employee.m_empNo << ": " << employee.m_name << ", $";

		// Check if the salary has no decimal places
		if (employee.m_salary == static_cast<int>(employee.m_salary)) {
			std::cout << std::fixed << std::setprecision(0) << employee.m_salary;
		}
		else {
			std::cout << std::fixed << std::setprecision(2) << employee.m_salary;
		}

		std::cout << std::endl;
	}



	void display()
	{
		sort();
		std::cout << "Employee Salary report, sorted by employee number" << std::endl;
		std::cout << "no- Empno, Name, Salary" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;

		for (int i = 0; i < noOfEmployees; i++)
		{
			std::cout << i + 1 << "- ";
			display(employees[i]);
		}
	}

	// TODO: Implementation for the deallocateMemory function goes here

	void deallocateMemory()
	{
		if (employees != nullptr)
		{
			for (int i = 0; i < noOfEmployees; i++)
			{
				delete[] employees[i].m_name;
			}
			delete[] employees;
			employees = nullptr;
		}
	}

}