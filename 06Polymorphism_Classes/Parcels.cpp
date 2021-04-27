//***************************************************************************
// File name:	 Parcels.cpp
// Author:		 Taylor Isaac
// Date:		   4/22/2021
// Class:		   CS 250
// Assignment: 06Polymorphism_Classes
// Purpose:		 Demonstrate Inheritance
//***************************************************************************

#include "Parcels.h"
#include <iostream>
#include <string>

//***************************************************************************
// Constructor:	Parcels
//
// Description:	Provides initialization for the appropiate data member 
//              variables of a parcel. This should set up inheritance for 
//							this class's derived classes
//
// Parameters:	None
//
// Returned:		none
//***************************************************************************

Parcels::Parcels() {
	mTypeOfParcel = "";
	mTrackingNumb = -1;
	mToAddress = "";
	mFromAddress ="";
	mWeightOz = -1;
	mDistanceToTravel = -1;
	mMilesPerDayCanTravel = -1;
	mDayMinimumOfTravel = -1;
	bInsured = false;
	bRush = false;
}

bool Parcels::read(istream& rcIn) {
	bool bTheTruth = false;
	if (rcIn >> mTrackingNumb >> mToAddress >> mFromAddress >> mWeightOz 
					 >> mDistanceToTravel) {
		bTheTruth = true;
	}
  
  return bTheTruth;
}

//***************************************************************************
// Function:		print
//
// Description:	prints an object's correct associated information
//
// Parameters:	ostream - one may specift whether to the console or to an 
//												output file
// 
// Returned:		none
//***************************************************************************

void Parcels::print(ostream& rcOut) {
	rcOut << "TID: " << mTrackingNumb << "  From: " << mFromAddress
				<< "\tTo: " << mToAddress;
	if (bRush) {
		rcOut << "\tRUSH";
	}
	if (bInsured) {
		rcOut << "\tINSURED";
	}
}

//***************************************************************************
// Function:    getUserTID
//
// Description: gets the user input's desired TID
// 
// Parameters:  index - actual size of array of pointers
// 
//							apcArrayOfParcels - the array of pointers passed in
//							
//							userTID - passes in the user's initial TID 
// 
// Returned:    bool - returns a boolean variable if valid TID
//***************************************************************************

bool Parcels::getValidUserTID(int index, Parcels* apcArrayOfParcels[],
															int userTID) {
	bool validUserTID = false;
	for (int start = 0; start < index; start++) {
		if (apcArrayOfParcels[start]->mTrackingNumb == userTID) {
			validUserTID = true;
		}
	}
	return validUserTID;
	}

//***************************************************************************
// Function:    getInsuranceTruth
//
// Description: gets the returned value of whether or not there is insurance
// 
// Parameters:  none
// 
// Returned:    bool - returns a boolean variable if valid TID
//***************************************************************************

bool Parcels::getInsuranceTruth() {
	return bInsured;
}

//***************************************************************************
// Function:    getRushTruth
//
// Description: gets the returned value of whether or not there is rushed
//							delivery
// 
// Parameters:  none
// 
// Returned:    bool - returns a boolean variable if valid TID
//***************************************************************************

bool Parcels::getRushTruth() {
	return bRush;
}

//***************************************************************************
// Function:		addInsurance
//
// Description:	sets true the insurance to the unique type of parcel
//
// Parameters:	the current state of insurance for the parent's private data
//							member variable of whether or not it is being insured
// 
// Returned:		double - the rushing expense
//***************************************************************************

void Parcels::addInsurance() { // Passing in the 
	bInsured = true;
}

//***************************************************************************
// Function:		addRush
//
// Description:	sets true the unique parcel's state of being rushed 
//
// Parameters:	the current state of being rushed for the parent's private 
//							data member variable of whether or not it is being insured
// 
// Returned:		double - the rushing expense
//***************************************************************************

void Parcels::addRush() {
	bRush = true;
}