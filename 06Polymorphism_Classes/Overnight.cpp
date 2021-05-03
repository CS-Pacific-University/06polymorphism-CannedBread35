//***************************************************************************
// File name:	 Parcels.cpp
// Author:		 Taylor Isaac
// Date:		   5/2/2021
// Class:		   CS 250
// Assignment: 06Polymorphism_Classes
// Purpose:		 Demonstrate Inheritance
//***************************************************************************

#include "Parcels.h"
#include "Overnight.h"
#include <iostream>
#include <string>
#include <iomanip>

//***************************************************************************
// Constructor:	Overnight
//
// Description:	Provides initialization for the appropiate data member 
//              variables of an overnight package. This should set up 
//              inheritance for this class's derived classes
//
// Parameters:	None
//
// Returned:		none
//***************************************************************************

Overnight::Overnight() : Parcels(), mVol(-1), mInsuranceCostMultiplier(0.25),
												 mRushCostMultiplier(0.75) {

}

//***************************************************************************
// Function:	  read
//
// Description:	using inherited functionality from its parent class to read
//              in more unique data tailored to its own derived class
//
// Parameters:	rcIn - designated input option
//
// Returned:		the truth of whether or not data was successful in reading in
//***************************************************************************

bool Overnight::read(istream& rcIn) {
  bool bTheTruth = false;
  Parcels::read(rcIn);
  if (rcIn >> mVol) {
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

void Overnight::print(ostream& rcOut) {
  Parcels::print(rcOut);
  rcOut << "\tOVERNIGHT!\n";
}

//***************************************************************************
// Function:		getCost
//
// Description:	gets the total running costs if particular attributes are 
//							valid
//
// Parameters:	none
// 
// Returned:		the total running cost
//***************************************************************************

double Overnight::getCost() {
	const double INSURANCE_COST_MULTIPLIER = 1.25;
	const double RUSH_MULTIPLIER = 1.75;
	const int UPPER_BOUND_COST = 100;
	double runningCost = 0;
	if (getVol() > UPPER_BOUND_COST) {
		runningCost = 20;
	}
	if (getVol() <= UPPER_BOUND_COST) {
		runningCost = 12;
	}
	if (Parcels::getInsuranceTruth()) { 
		runningCost *= INSURANCE_COST_MULTIPLIER;
	}
	if (Parcels::getRushTruth()) {
		runningCost *= RUSH_MULTIPLIER; 
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
// Returned:		the total running number of days required for delivery
//***************************************************************************

int Overnight::getDaysForDelivery() {
  const int MAX_MILES_PER_DAY_CAN_TRAVEL = 1000;
  int milesToTravel = Parcels::getDistance();
  int daysForDelivery = 0;

  if (MAX_MILES_PER_DAY_CAN_TRAVEL >= milesToTravel) {
    daysForDelivery = 1;
  }
  else {
      daysForDelivery += 2; 
   }
	if (Parcels::getRushTruth()) {
		daysForDelivery = 1;
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
// Returned:		the insurance's overall rate for the unique parcel
//***************************************************************************

double Overnight::getInsuranceExpense(double currCost) const {
	double actualInsuranceExpense = 0;
	actualInsuranceExpense = (currCost * mInsuranceCostMultiplier); 
	return actualInsuranceExpense;
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

double Overnight::getRushExpense(double currCost) const {
	double actualRushExpense = 0;
	actualRushExpense = (currCost * mRushCostMultiplier);
	return actualRushExpense;
}