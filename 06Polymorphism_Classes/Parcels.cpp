//***************************************************************************
// File name:	 Parcels.cpp
// Author:		 Taylor Isaac
// Date:		   5/2/2021
// Class:		   CS 250
// Assignment: 06Polymorphism_Classes
// Purpose:		 Demonstrate Inheritance using a Parcel
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

//***************************************************************************
// Function:	  read
//
// Description:	reads in specified data (the derived classes will use this 
//							exact function, but add more special things to read in
//
// Parameters:	rcIn - designated input option
//
// Returned:		determination of whether or not data was read in
//***************************************************************************

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
	rcOut << "TID: " << mTrackingNumb << "\tFrom: " << mFromAddress
				<< "\tTo: " << mToAddress;
	if (bInsured) {
		rcOut << "\tINSURED\t";
	}
	if (bRush) {
		rcOut << "\tRUSH";
	}
	
}

//***************************************************************************
// Function:    getUserTID
//
// Description: gets the user input's desired TID. This function checks
//							to see if any of the TID's in the array of pointers matches 
//							up with what the user enters in 
// 
// Parameters:  index							- actual size of array of pointers
// 
//							apcArrayOfParcels - the array of pointers passed in
//							
//							userTID						- passes in the user's inputted initial TID 
// 
// Returned:    returns a boolean variable if valid TID
//***************************************************************************

bool Parcels::getValidUserTID(int index, Parcels* apcArrayOfParcels[],
															int userTID) {
	bool validUserTID = false;
	for (int start = 0; start < index; start++) {
		if (apcArrayOfParcels[start] != nullptr && 
				apcArrayOfParcels[start]->mTrackingNumb == userTID) {
			validUserTID = true;
		}
	}
	return validUserTID;
	}

//***************************************************************************
// Function:    getInsuranceTruth
//
// Description: gets the returned value of the current state of being insured
//							or not
// 
// Parameters:  none
// 
// Returned:    returns a boolean variable of insurance
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
// Returned:    returns a boolean variable of whether or not its rushed
//***************************************************************************

bool Parcels::getRushTruth() {
	return bRush;
}

//***************************************************************************
// Function:		addInsurance
//
// Description:	sets true the state of being insured for the unique type of 
//							parcel
//
// Parameters:	none
// 
// Returned:		none
//***************************************************************************

void Parcels::addInsurance() {
	bInsured = true;
}

//***************************************************************************
// Function:		addRush
//
// Description:	sets true the unique parcel's state of being rushed 
//
// Parameters:	none
// 
// Returned:		none
//***************************************************************************

void Parcels::addRush() {
	bRush = true;
}