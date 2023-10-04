/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
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
#include "Population.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

namespace sdds {
    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    Population* data = nullptr;
    int dataSize = 0;

    bool getPostalCode(char* postal_code_prefix) {
        std::cout << "Population Report" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "Enter postal code:" << std::endl;
        std::cout << "> ";
        std::cin.getline(postal_code_prefix, 4);

        // Use strcmp to compare strings
        if (std::strcmp(postal_code_prefix, "all") == 0) {
            postal_code_prefix[0] = '\0';  // Set it to an empty string
        }

        return postal_code_prefix[0] != '!';
    }



    bool load(const char* filename, const char* partial_postal_code_prefix) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return false;
        }

        // Count the number of matching records
        dataSize = 0;
        std::string line;
        while (std::getline(file, line)) {
            if (startsWith(line.c_str(), partial_postal_code_prefix)) {
                dataSize++;
            }
        }

        // Allocate memory for matching records
        data = new Population[dataSize];

        // Rewind file and load data
        file.clear();
        file.seekg(0, std::ios::beg);
        int index = 0;
        while (std::getline(file, line)) {
            if (startsWith(line.c_str(), partial_postal_code_prefix)) {
                std::sscanf(line.c_str(), "%3s,%d", data[index].postalCode, &data[index].population);
                index++;
            }
        }

        //// Sort the data based on postal codes
        //std::sort(data, data + dataSize, [](const Population& a, const Population& b)
        //{
        //    return std::strcmp(a.postalCode, b.postalCode) < 0;
        //});
        sort();

        return true;
    }



    //void sort() {
    //    std::sort(data, data + dataSize, [](const Population& a, const Population& b) {
    //        return a.population < b.population;
    //        });
    //}
    void sort()
    {
        int i, k;
        Population keyValue;
        for (i = 1; i < dataSize; i++) 
        {
            keyValue = data[i];
            for (k = i - 1; k >= 0 && data[k].population > keyValue.population; k--)
            {
                data[k + 1] = data[k]; 
            }

            data[k + 1] = keyValue;
        }
    }

    void display() {
        std::cout << "Postal Code: population" << std::endl;
        std::cout << "-------------------------" << std::endl;
        int totalPopulation = 0;
        for (int i = 0; i < dataSize; i++) {
            std::cout << i + 1 << "- " << data[i].postalCode[0] << data[i].postalCode[1] << data[i].postalCode[2] << ":  " << data[i].population << std::endl;
            totalPopulation += data[i].population;
        }
        std::cout << "-------------------------" << std::endl;
        std::cout << "Population of the listed areas: " << totalPopulation << std::endl;
    }

    void deallocateMemory() {
        delete[] data;
        data = nullptr;
    }
}