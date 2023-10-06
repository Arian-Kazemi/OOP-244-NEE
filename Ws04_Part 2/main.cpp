/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
Full Name  : Arian Kazemi
Student ID#: 181613217
Email      : akazemi4@myseneca.ca
Section    : NEE

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
   int noOfLabels;

   
   Label  // Creating a lable for title of the:
      theProgram("/-\\|/-\\|"),
      test1,
      test2("ABCDEFGH");
   test1.printLabel();
   test2.printLabel();
   theProgram.printLabel();
   test1.text("Testing one, two, three");
   test1.printLabel() << endl;
   theProgram.text("Professor's Label Maker Program Tester");
   theProgram.printLabel() << endl << endl;

   
   cout << "Number of labels to create: ";   // cout number of labels 
   cin >> noOfLabels;
   cin.ignore(10000, '\n');

  
   LabelMaker lblMkr(noOfLabels); // Create a LabelMaker for the number of 
   
   lblMkr.readLabels();  // Ask for the label texts
   
   lblMkr.printLabels(); // Print the labels
   return 0;
}