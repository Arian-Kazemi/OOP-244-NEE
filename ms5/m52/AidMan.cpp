/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#include <iostream>
#include <fstream>
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
#include "Perishable.h"


using namespace std;
namespace sdds

{
   unsigned int AidMan::menu() const
   {
      cout << "Aid Management System" << endl <<
         "Date: " << Date() << endl <<
         "Data file: " << (m_fileName == nullptr ? "No file" : m_fileName) << endl <<
         "---------------------------------\n";
      return m_mainMenu.run();
   }

   AidMan::AidMan()
   {
      m_mainMenu.set(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");
      m_fileName = nullptr;
      m_numOfIproduct = 0;
   }

   AidMan::~AidMan()
   {
      delete[] m_fileName;
      deallocate();
   }

   void AidMan::run()
   {
      int numList;
      int input;
      int val = 999;
      do
      {
         val = menu();
         if (val != 0 && val != 7 && m_fileName == nullptr) val = 7;
         switch (val)
         {
         case 0:
            cout << "Exiting Program!" << endl;
            save();
            break;
         case 1:
            cout << endl << "****List Items****\n";
            numList = list();
            if (numList)
            {
               cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
               cin.clear();
               cin.get();
               if (cin.peek() != '\n')
               {
                  input = ut.getint(1, numList);
                  m_iproduct[input - 1]->linear(false);
                  m_iproduct[input - 1]->display(cout);
                  cout << endl;
               }
            }
            cout << endl;
            break;
         case 2:
            cout << endl << "****Add Item****\n";
            add();
            break;
         case 3:
            cout << endl << "****Remove Item****\n\n";
            break;
         case 4:
            cout << endl << "****Update Quantity****\n\n";
            break;
         case 5:
            cout << endl << "****Sort****\n\n";
            break;
         case 6:
            cout << endl << "****Ship Items****\n\n";
            break;
         case 7:
            cout << endl << "****New/Open Aid Database****\n";
            load();
            cout << m_numOfIproduct << " records loaded!\n" << endl;
            break;
         }
      } while (val);
   }

   void AidMan::save()
   {
      if (m_fileName)
      {
         ofstream ofstr(m_fileName);
         for (int i = 0; m_iproduct[i] != 0; i++)
         {
            m_iproduct[i]->save(ofstr);
            ofstr << "\n";
         }

      }
   }

   void AidMan::deallocate()
   {
      for (int i = 0; i < sdds_max_num_items; i++)
      {
         delete m_iproduct[i];
      }
      m_numOfIproduct = 0;
   }

   void AidMan::load()
   {
      char input, fileName[100];
      unsigned int i = 0;
      bool valid;
      save();
      deallocate();
      cout << "Enter file name: ";
      cin >> fileName;
      ut.alocpy(m_fileName, fileName);
      ifstream ifstr(m_fileName);
      if (ifstr.is_open())
      {
         while (ifstr)
         {
            input = ifstr.peek();
            for (i = 0, valid = false; !valid; i++)
            {
               if (input == '1')
               {
                  if (m_iproduct[i] == 0)
                  {
                     m_iproduct[i] = new Perishable;
                     valid = true;
                  }
               }
               else if (input > '0' && input <= '9')
               {
                  if (m_iproduct[i] == 0)
                  {
                     m_iproduct[i] = new Item;
                     valid = true;
                  }
               }
               else
               {
                  ifstr.setstate(ios::badbit);
                  valid = true;
               }
            }
            if (m_iproduct[m_numOfIproduct])
            {
               m_iproduct[m_numOfIproduct]->load(ifstr);
               if (m_iproduct[m_numOfIproduct]->operator bool())
               {
                  m_numOfIproduct++;
               }
               else
               {
                  ut.dealoSingle(m_iproduct[m_numOfIproduct]);
               }
            }
         }
      }
      else
      {
         cout << "Failed to open " << m_fileName << " for reading!" << endl <<
            "Would you like to create a new data file?" << endl <<
            "1- Yes!" << endl <<
            "0 - Exit" << endl << "> ";
         cin >> i;
         if (i)
            ofstream ofstr(m_fileName);
      }
   }

   void AidMan::add()
   {
      int input;
      if (m_numOfIproduct >= sdds_max_num_items)
         cout << "Database full!";
      else
      {
         cout << "1- Perishable" << endl <<
            "2- Non-Perishable" << endl <<
            "-----------------" << endl <<
            "0- Exit" << endl <<
            "> ";
         switch (ut.getint(0, 2))
         {
         case 1:
            m_iproduct[m_numOfIproduct] = new Perishable;
            input = m_iproduct[m_numOfIproduct]->readSku(cin);
            if (search(input) == -1)
            {
               m_iproduct[m_numOfIproduct]->read(cin);
               if (m_iproduct[m_numOfIproduct]->operator bool())
               {
                  m_numOfIproduct++;
               }
               else
               {
                  m_iproduct[m_numOfIproduct]->display(cout);
                  ut.dealoSingle(m_iproduct[m_numOfIproduct]);
               }
            }
            else
            {
               ut.dealoSingle(m_iproduct[m_numOfIproduct]);
               cout << "Sku: " << input << " is already in the system, try updating quantity instead.\n";
            }
            break;
         case 2:
            m_iproduct[m_numOfIproduct] = new Item;
            input = m_iproduct[m_numOfIproduct]->readSku(cin);
            if (search(input) == -1)
            {
               m_iproduct[m_numOfIproduct]->read(cin);
               if (m_iproduct[m_numOfIproduct]->operator bool())
               {
                  m_numOfIproduct++;
               }
               else
               {
                  m_iproduct[m_numOfIproduct]->display(cout);
                  ut.dealoSingle(m_iproduct[m_numOfIproduct]);
               }
            }
            else
            {
               ut.dealoSingle(m_iproduct[m_numOfIproduct]);
               cout << "Sku: " << input << " is already in the system, try updating quantity instead.\n";
            }
            break;
         default:
            cout << "Aborted\n";
         }
         cout << endl;
      }
   }

   int AidMan::list(const char* sub_desc)
   {
      unsigned int i = 0;
      cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl <<
         "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
      if (!sub_desc)
      {
         for (i = 0; m_iproduct[i] != 0; i++)
         {
          
            cout << "   " << i + 1;
            cout << " | ";
            m_iproduct[i]->linear(true);
            cout << *m_iproduct[i] << endl;
         }
         cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
      }
      else
      {
         for (i = 0; m_iproduct[i] != 0; i++)
         {
            cout << "   " << i + 1;
            cout << " | ";
            if (*m_iproduct[i] == sub_desc)
               cout << *m_iproduct[i] << endl;
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
         }
      }
      if (!i)
      {
         cout << "The list is emtpy!" << endl;
      }
      return i;
   }

   int AidMan::search(int sku) const
   {
      int index = -1;
      for (int i = 0; m_iproduct[i] != 0 && i < sdds_max_num_items && index == -1; i++)
      {
         if (*m_iproduct[i] == sku)
            index = i;
      }
      return index;
   }

}