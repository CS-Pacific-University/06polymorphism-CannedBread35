//***************************************************************************
// File name:		Source.cpp
// Author:			Taylor Isaac
// Date:				4/28/2021
// Class:				CS 250
// Assignment:  06Polymorphism
// Purpose:			Demonstrate the mail class
//***************************************************************************

#include "Parcels.h"
#include "Letter.h"
#include "Overnight.h"
#include "Postcard.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vld.h>
const int OPTION_ONE = 1;
const int OPTION_TWO = 2;
const int OPTION_THREE = 3;
const int OPTION_FOUR = 4;
const int OPTION_FIVE = 5;
const string INPUT_FILE = "parcels.txt";
int printOptionMenuAndGetChoice();
void openFileForRead(ifstream& rInfile);
void closeFileForRead(ifstream& rInfile);
void printAllParcels(int index, Parcels* apcParcelsObjs[]);
int obtainInitialTID();
using namespace std;

//***************************************************************************
// Function:		main
//
// Description:	contains the necessary components, variables, and functions
//							to execute tasks and operate on parcel related activity
// 
// Parameters:	None
//
// Returned:		EXIT_SUCCESS
//***************************************************************************

int main() {
  const int MAX_NUMB_ARRAY = 25;
  const string PROMPT_CHOICE = "Choice> ";
  const char POSTCARD_SYMBOL = 'P';
  const char LETTER_SYMBOL = 'L';
  const char OVERNIGHT_SYMBOL = 'O';
  char parcelEat = '.';
  int index = 0;
  int initialID = -1;
  int userChoice = -2;
  bool bIsValidTID = false;
  double eatCost = 0;
  Parcels* apcParcelsObjs[MAX_NUMB_ARRAY] = { nullptr };
  ifstream cInFile;

  openFileForRead(cInFile);
  cout << "Mail Simulator!\n";
  while (cInFile >> parcelEat) {
    switch (parcelEat) {
    case POSTCARD_SYMBOL: apcParcelsObjs[index] = new Postcard();
      apcParcelsObjs[index]->read(cInFile);
      ++index;
      break;
    case LETTER_SYMBOL:  apcParcelsObjs[index] = new Letter();
      apcParcelsObjs[index]->read(cInFile);
      ++index;
      break;
    case OVERNIGHT_SYMBOL: apcParcelsObjs[index] = new Overnight();
      apcParcelsObjs[index]->read(cInFile);
      ++index;
      break;
    default: break;
    }
  }

  while (OPTION_FIVE != userChoice) {
    userChoice = printOptionMenuAndGetChoice();
    if (OPTION_ONE == userChoice) {
      printAllParcels(index, apcParcelsObjs);
    }

    else if (OPTION_FOUR == userChoice) {
      
        initialID = obtainInitialTID();
        if (apcParcelsObjs[initialID - 1] != nullptr) {
          bIsValidTID = Parcels::getValidUserTID(index, apcParcelsObjs,
            initialID);
          if (bIsValidTID) { 
            cout << "Delivered!\n";
            cout << apcParcelsObjs[initialID - 1]->getDaysForDelivery();
            cout << " Day, " << "$" 
                 << apcParcelsObjs[initialID - 1]->getCost();
            cout << "\n";
            apcParcelsObjs[initialID - 1]->print(cout);
            delete apcParcelsObjs[initialID - 1];
            apcParcelsObjs[initialID - 1] = { nullptr };
          }
       }
    } 
    else if (OPTION_TWO == userChoice) {
      initialID = obtainInitialTID();
      if (apcParcelsObjs[initialID - 1] != nullptr) {
        bIsValidTID = Parcels::getValidUserTID(index, apcParcelsObjs,
          initialID);
        if (bIsValidTID) {
          cout << "Added Insurance for $";
          eatCost = (apcParcelsObjs[initialID - 1]->getCost());
    
          cout << apcParcelsObjs[initialID - 1]->
                                                getInsuranceExpense(eatCost);

          cout << "\n";
          apcParcelsObjs[initialID - 1]->addInsurance();
          apcParcelsObjs[initialID - 1]->print(cout);
        }
      }
    }
    else if (OPTION_THREE == userChoice) {
      initialID = obtainInitialTID();
      if (apcParcelsObjs[initialID - 1] != nullptr) {
        bIsValidTID = Parcels::getValidUserTID(index, apcParcelsObjs,
          initialID);
        if (bIsValidTID) { 
          cout << "Added Rush for $";
          eatCost = (apcParcelsObjs[initialID - 1]->getCost());
          cout << apcParcelsObjs[initialID - 1]->getRushExpense(eatCost);
          cout << "\n";
          apcParcelsObjs[initialID - 1]->addRush();
          apcParcelsObjs[initialID - 1]->print(cout);
        }
      }
    }
  }
  for (int start = 0; start < MAX_NUMB_ARRAY; start++) {
    delete (apcParcelsObjs[start]);
  }
  closeFileForRead(cInFile);
  return EXIT_SUCCESS;
}

//***************************************************************************
// Function:		printOptionMenuAndGetChoice
//
// Description:	Outputs desired description or criterium with the option of 
//              allowing the user to input a choice
//
// Parameters:	None
// 
// Returned:		int - the returned valid choice as a number displayed from
//                    menu
//***************************************************************************

int printOptionMenuAndGetChoice() {
  int userChoice = -1;
  cout << "\n1. Print All\n2. Add Insurance\n3. Add Rush\n4. Deliver\n5. ";
  cout << "Quit\n\n";
  do {
    cout << "Choice> ";
    cin >> userChoice;
  } while (!(OPTION_ONE == userChoice ||
             OPTION_TWO == userChoice ||
             OPTION_THREE == userChoice ||
             OPTION_FOUR == userChoice ||
             OPTION_FIVE == userChoice));
  return userChoice;
}

//***************************************************************************
// Function:		openFileForRead
//
// Description:	opens file, checking for proper opening
//							
// Parameters:	rInfile - specified input file
//              
// Returned:		None
//***************************************************************************

void openFileForRead(ifstream& rInfile) {
 // const string INPUT_FILE = "parcels.txt";
  rInfile.open(INPUT_FILE);
  if (!rInfile.is_open()) {
    cout << "Error opening file.";
    exit(EXIT_FAILURE);
  }
}

//***************************************************************************
// Function:    closeFileForRead
//
// Description: closes a file opened for reading
// 
// Parameters:  rInfile - the object used to close the file to be read
//
// Returned:    None
//***************************************************************************

void closeFileForRead(ifstream& rInfile) {
  rInfile.close();
}

//***************************************************************************
// Function:    printAllParcels
//
// Description: when user chooses option 1, it prints all associated parcels
// 
// Parameters:  index - the correct amount of positions associated with the 
//                      array of pointers
//  
//              *apcArrayOfParcels[] - allows an array of pointers of class 
//                                     Parcels to be passed in
//
// Returned:    None
//***************************************************************************

void printAllParcels(int index, Parcels *apcArrayOfParcels[]) {
  cout << "\n";
  for (int start = 0; start < index; start++) {
    if (apcArrayOfParcels[start] != nullptr) {
        apcArrayOfParcels[start]->print(cout);
    }
  }
}

//***************************************************************************
// Function:    obtainInitialTID
//
// Description: gets initial TID from user. We do not know if it's valid yet
// 
// Parameters:  None
//
// Returned:    int - the user's inputted initial tracking ID number
//***************************************************************************

int obtainInitialTID() {
  int initialTID = -1;
  cout << "\nTID> ";
  cin >> initialTID;
    return initialTID;
}