/***********************************************************************
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace sdds {

    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    CarInventory::CarInventory() {
        resetInfo();
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        resetInfo();
        setInfo(type, brand, model, year, code, price);
    }

    CarInventory::~CarInventory() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        if (type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0.0) {
            m_type = new char[strlen(type) + 1];
            m_brand = new char[strlen(brand) + 1];
            m_model = new char[strlen(model) + 1];
            strcpy(m_type, type);
            strcpy(m_brand, brand);
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        else {
            resetInfo();
        }
        return *this;
    }


    void CarInventory::printInfo() const {
        std::cout.setf(std::ios::left);
        std::cout << "| ";
        std::cout.width(10);
        std::cout << m_type;
        std::cout << " | ";
        std::cout.width(16);
        std::cout << m_brand;
        std::cout << " | ";
        std::cout.width(16);
        std::cout << m_model;
        std::cout << " | ";
        std::cout << m_year;
        std::cout << " |  ";
        std::cout << m_code;
        std::cout << " | ";
        std::cout.unsetf(std::ios::left);
        std::cout.width(9);
        std::cout.setf(std::ios::right);
        std::cout.precision(2);
        std::cout.setf(std::ios::fixed);
        std::cout << double(m_price);
        std::cout.unsetf(std::ios::right);
        std::cout << " |" << std::endl;
    }






    bool CarInventory::isValid() const {
        return (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0.0);
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) {
        // Check if any of the pointers is nullptr
        if (m_type == nullptr || m_brand == nullptr || m_model == nullptr || car.m_type == nullptr || car.m_brand == nullptr || car.m_model == nullptr) {
            return false;
        }

        // Comparing the attributes
        return (strcmp(m_type, car.m_type) == 0 &&
            strcmp(m_brand, car.m_brand) == 0 &&
            strcmp(m_model, car.m_model) == 0 &&
            m_year == car.m_year);
    }


    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1;
    }
}
