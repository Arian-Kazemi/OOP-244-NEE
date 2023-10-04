/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
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
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
	bool read(int& employee_number)
	{
		bool result = false;
		if (fscanf(fptr, "%d,", &employee_number) == 1)
		{
			result = true;
		}
		return result;
	}

	bool read(double& employee_salary)
	{
		bool result = false;
		if (fscanf(fptr, "%lf,", &employee_salary) == 1)
		{
			result = true;
		}
		return result;
	}

	bool read(char* employee_name)
	{
		bool result = false;
		if (fscanf(fptr, "%[^\n]\n", employee_name) == 1)
		{
			result = true;
		}
		return result;
	}

}