/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
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

#include <iostream>
#include "cstring.h"
namespace sdds {
    void strCpy(char* des, const char* src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        while (src[i] != '\0' && i < len)
        {
            des[i] = src[i];
            i++;
        }
        if (i < len)
        {
            des[i] = '\0';
        }
    }

    int strCmp(const char* s1, const char* s2)
    {
        for (; *s1 == *s2; s1++, s2++)
        {
            if (*s1 == '\0')
                return 0;
        }
        return *s1 - *s2;
    }

    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i;
        for (i = 0; *s1 == *s2 && i < len; s1++, s2++, i++)
        {
            if (*s1 == '\0')
                return 0;
        }
        if (i == len)
            return 0;
        return *s1 - *s2;
    }


    int strLen(const char* s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }
        return i;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        int len1 = strLen(str1);
        int len2 = strLen(str2);

        for (int i = 0; i <= len1 - len2; i++)
        {
            int j;
            for (j = 0; j < len2; j++)
            {
                if (str1[i + j] != str2[j])
                {
                    break;
                }
            }
            if (j == len2)
            {
                return &str1[i];
            }
        }
        return nullptr;
    }


    void strCat(char* des, const char* src)
    {
        int len1 = strLen(des);
        int len2 = strLen(src);

        int i, j;
        for (i = len1, j = 0; j < len2; i++, j++)
        {
            des[i] = src[j];
        }
        des[i] = '\0';
    }
}