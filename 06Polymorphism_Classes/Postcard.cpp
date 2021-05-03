//***************************************************************************
// File name:	 Postcard.cpp
// Author:		 Taylor Isaac
// Date:		   5/2/2021
// Class:		   CS 250
// Assignment: 06Polymorphism_Classes
// Purpose:		 Demonstrate Inheritance
//***************************************************************************

#include "Parcels.h"
#include "Letter.h"
#include <iostream>
#include "Postcard.h"
#include <string>
#include <iomanip>

//***************************************************************************
// Constructor:	Postcard
//
// Description:	Provides initialization for the appropiate data member 
//              variables of a postcard. This should utilize inheritance for 
//							this class's derived classes
//
// Parameters:	None
//
// Returned:		none
//***************************************************************************

Postcard::Postcard() : Parcels(), mMessage(""), insuranceFlatRate(0.15),
                       rushCost(0.25) {
}

//***************************************************************************
// Function:	  read
//
// Description:	using inherited functionality from its parent class to read
//              in more unique data tailored to its own derived class
//
// Parameters:	rcIn - designated input option
//
// Returned:		determination of whether or not data was read in
//***************************************************************************

bool Postcard::read(istream& rcIn) {
  bool bTheTruth = false;
  Parcels::read(rcIn);
  if (rcIn >> mMessage) {
    bTheTruth = true;
  }
  return bTheTruth;
}

//***************************************************************************
// Function:		print
//
// Description:	prints an object's correct associated information
//
// Parameters:	rcOut - one may specift whether to the console or to an 
//											output file
// 
// Returned:		none
//***************************************************************************

void Postcard::print(ostream& rcOut) {
  Parcels::print(rcOut);
  rcOut << "\t" << mMessage << "\n";
}

//***************************************************************************
// Function:		getCost
//
// Description:	gets the total running costs if particular attributes are 
//							valid
//
// Parameters:	none
// 
// Returned:		the total running cost for the postcard
//***************************************************************************

double Postcard::getCost() {
  double runningCost = 0.15;
  const double insuranceCost = 0.15;
  const double rushCost = 0.25;
 
  if (Parcels::getRushTruth()) {
    runningCost += rushCost;
  }
  if (Parcels::getInsuranceTruth()) {
    runningCost += insuranceCost;
  }
  cout << fixed << setprecision(2);
  return runningCost;
}

//***************************************************************************
// Function:		getDaysForDelivery
//
// Description:	gets the total running number of days if particular 
//              attributes are valid
//
// Parameters:	none
// 
// Returned:		the total running number of days required for delivery of a 
//              postcard
//***************************************************************************

int Postcard::getDaysForDelivery() {
  const int MILES_PER_DAY_CAN_TRAVEL = 10;
  const int ZERO_THRESHOLD = 0;
  const int ONE_DAY_THRESHOLD = 1;
  int milesToTravel = Parcels::getDistance();
  int daysForDelivery = 0;
  
  if (MILES_PER_DAY_CAN_TRAVEL >= milesToTravel) {
    daysForDelivery = 1;
  }
  else {
    while (milesToTravel > ZERO_THRESHOLD) {
      (milesToTravel -= MILES_PER_DAY_CAN_TRAVEL);
      daysForDelivery++;  
    }
  }
  if (Parcels::getRushTruth()) {
    if (daysForDelivery > ONE_DAY_THRESHOLD) {
      daysForDelivery -= 1;
    }
  }
  return daysForDelivery;
}

//***************************************************************************
// Function:		getInsuranceExpense
//
// Description:	returns the calculated insurance expense for the unique
//							parcel
//
// Parameters:	none
// 
// Returned:		the insurance's flat rate for the unique parcel
//***************************************************************************

double Postcard::getInsuranceExpense(double currCost) const {
  return insuranceFlatRate;
}

//***************************************************************************
// Function:		getRushExpense
//
// Description:	returns the calculated rush expense for the unique
//							parcel
//
// Parameters:	currCost - the current cost of the unique type of parcel to 
// 
// Returned:		the rushing expense
//***************************************************************************

double Postcard::getRushExpense(double currCost) const {
  return rushCost;
}