/* ------------------------------------------------------
Workshop 1 part 2
Full Name :Arian Kazemi
Email Address :akazemi4@myseneca.ca
Student ID :181613217
------------------------------------------------------*/

#ifndef NAMESPACE_CSTRTOOLS_H 
#define NAMESPACE_CSTRTOOLS_H



namespace sdds {


	char toLower(char ch);    // takes a character as input and converts it to lowercase


	int strCmp(const char* s1, const char* s2);

	const char* strStr(const char* str, const char* find);
	void strCpy(char* des, const char* src);

	int strLen(const char* str);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);//removes non-alphabetic characters


	void toLowerCaseAndCopy(char des[], const char source[]);

}
#endif
