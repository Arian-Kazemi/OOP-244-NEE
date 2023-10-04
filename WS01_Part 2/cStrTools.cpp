/* ------------------------------------------------------
Workshop 1 part 2
Full Name :Arian Kazemi
Email Address :akazemi4@myseneca.ca
Student ID :181613217
------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "cStrTools.h"

using namespace sdds;  //// Using name spaces 
using namespace std;

namespace sdds {     //     sdds conrains implementations of various string  functions.


	char toLower(char ch) {                //takes a character and convert it to lower case
		if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
		return ch;
	}

	int strCmp(const char* s1, const char* s2) {    //this function compares two C-style strings and returns an integer as a result.
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0;
		while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
			i++;
		}
		return s1[i] - s2[i];
	}

	const char* strStr(const char* str, const char* find) {
		const char* faddress = nullptr;
		int i, flen = strLen(find), slen = strLen(str);
		for (i = 0; i <= slen - flen && strnCmp(&str[i], find, flen); i++);
		if (i <= slen - flen) faddress = &str[i];
		return faddress;
	}



	void strCpy(char* des, const char* src) {   // This function copies the content of the source string 
		int i;
		for (i = 0; src[i]; i++) des[i] = src[i];
		des[i] = 0;
	}




	int strLen(const char* str) {   //Calculates and returns the length of an input.
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}




	int isAlpha(char ch) {   //checks if it's a letter?
		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
	}




	int isSpace(char ch) {
		return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
	}

	void trim(char word[]) {
		int i;
		while (word[0] && !isAlpha(word[0])) {
			strCpy(word, word + 1);


		}
		i = strLen(word);
		while (i && !isAlpha(word[i - 1])) {

			word[i-- - 1] = 0;
		}
	}

	void toLowerCaseAndCopy(char des[], const char source[]) {
		int i = 0, j = 0;
		for (; source[i] != 0; i++) {


			des[j++] = toLower(source[i]);
		}

		des[j] = 0;
	}

}