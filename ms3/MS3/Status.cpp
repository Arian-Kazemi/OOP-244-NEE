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
#include<iostream>
#include<cstring>
#include"Status.h"
using namespace std;
namespace sdds
{
    Status::Status(const char* desc)
    {
        if (desc != nullptr) {
            delete[] Description;
            Description = new char(strlen(desc) + 1);
            strcpy(Description, desc);
        }
        else {
            Description = nullptr;
        }
        Code = 0;
    }

    Status::Status(const Status& S)
    {
        if (S.Description != nullptr) {
            delete[] Description;
            Description = new char[strlen(S.Description) + 1];
            strcpy(Description, S.Description);
            Code = S.Code;
        }
        else {
            Description = nullptr;
        }
    }

    Status& Status::operator=(const Status& S)
    {
        if (this != &S) {
            delete[] Description;
            Description = nullptr;
            Description = new char[strlen(S.Description) + 1];
            strcpy(Description, S.Description);
            Code = S.Code;
        }
        return *this;
    }

    Status& Status::operator=(int statusCode)
    {
        Code = statusCode;
        return *this;
    }

    Status& Status::operator=(const char* desc)
    {
        if (desc != nullptr) {
            delete[] Description;
            Description = nullptr;
            Description = new char[strlen(desc) + 1];
            strcpy(Description, desc);
        }
        else {
            Description = nullptr;
        }

        return *this;
    }

    Status::~Status()
    {
        delete[] Description;
        Description = nullptr;
    }

    Status::operator int() const
    {
        return Code;
    }

    Status::operator const char* () const
    {
        return Description;
    }

    Status::operator bool() const
    {
        return Description == nullptr;
    }

    Status& Status::clear()
    {
        delete[] Description;
        Description = nullptr;
        Code = 0;
        return *this;
    }

    ostream& Status::display(ostream& ostr) const
    {
        if (Code != 0) {

            ostr << "ERR#" << Code << ": " << Description;

        }
        else {

            ostr << Description;

        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Status& S) {
        if (S.operator bool() == false) {
            S.display(ostr);
        }
        return ostr;
    }




}