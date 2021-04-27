//***************************************************************************
// File name:	 Letter.cpp
// Author:		 Taylor Isaac
// Date:		   4/22/2021
// Class:		   CS 250
// Assignment: 06Polymorphism_Classes
// Purpose:		 Demonstrate Letter and its pertinence to inheritance
//***************************************************************************

#include "Parcels.h"
#include "Letter.h"
#include <iostream>
#include <string>
#include <iomanip>

//***************************************************************************
// Constructor:	Letter
//
// Description:	Provides initialization for the appropiate data member 
//              variables of a letter--this should have pertinence to 
//              inheritance since this class is a derived class
//
// Parameters:	None
//
// Returned:		none
//***************************************************************************

Letter::Letter() : Parcels(), insuranceFlatRate(0.45), 
									 rushCostMultiplier(1.1) {
}

//***************************************************************************
// Function:	  read
//
// Description:	read in the name and SSN
//
// Parameters:	rcIn - designated input option
//
// Returned:		None
//***************************************************************************

bool Letter::read(istream& rcIn) {
	bool bTheTruth = false;
	if (Parcels::read(rcIn)) {
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
//												output file
// 
// Returned:		none
//***************************************************************************

void Letter::print(ostream& rcOut) {
	Parcels::print(rcOut);
	rcOut << "\n";
}

//***************************************************************************
// Function:		getCost
//
// Description:	gets the total running costs if particular attributes are 
//							valid
//
// Parameters:	none
// 
// Returned:		double - the total running cost
//***************************************************************************

double Letter::getCost() {
	const double insuranceCost = 0.45;
	double runningCost = (getWeightOz() * 0.45);
	const double rushMultiplier = 1.1;
	
	if (Parcels::getInsuranceTruth()) {
		runningCost += insuranceCost;
	}

	if (Parcels::getRushTruth()) {
		runningCost *= rushMultiplier;
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
// Returned:		double - the total running number of days required for
//                       delivery
//***************************************************************************

int Letter::getDaysForDelivery() {
	const int MILES_PER_DAY_CAN_TRAVEL = 100;
	int milesToTravel = Parcels::getDistance();
	int daysForDelivery = 0;

	if (MILES_PER_DAY_CAN_TRAVEL >= milesToTravel) {
		daysForDelivery = 1;
	}
	else {
		while (milesToTravel >= 0) {
			(milesToTravel - MILES_PER_DAY_CAN_TRAVEL);
			daysForDelivery++;
		}
	}
	if (Parcels::getRushTruth()) {
		if (daysForDelivery > 1) {
			daysForDelivery -= 1; // IS THIS LOGIC CORRECT?
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
// Returned:		double - the insurance's flat rate for the unique parcel
//***************************************************************************

double Letter::getInsuranceExpense(double currCost) const {
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
// Returned:		double - the rushing expense
//***************************************************************************

double Letter::getRushExpense(double currCost) const {
	double actualRushExpense = 0;
	actualRushExpense = (currCost * rushCostMultiplier);
	return actualRushExpense;
}