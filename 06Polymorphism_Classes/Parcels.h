#pragma once
//***************************************************************************
// File name:		Parcels.h
// Author:			Taylor Isaac
// Date:				5/2/2021
// Class:				CS 250
// Assignment:  06Polymorphism_Classes
// Purpose:			Demonstrate the Parcels class
//***************************************************************************

#include <string>
#include <iostream>

using namespace std;

class Parcels {
public:
	Parcels();
	virtual bool read (istream&);
	virtual void print (ostream&);
	static bool getValidUserTID (int index, Parcels* apcArrayOfParcels[],
															 int userChoice);
	bool getInsuranceTruth ();
	bool getRushTruth ();
	int getWeightOz () const { return mWeightOz; }
	int getDistance () const { return mDistanceToTravel; }

	virtual double getCost () = 0; 
	virtual int getDaysForDelivery () = 0;
	virtual double getInsuranceExpense (double) const = 0;
	virtual double getRushExpense (double) const = 0;

	void addInsurance ();
	void addRush ();

private:
	int mTrackingNumb;
	string mToAddress;
	string mFromAddress;
	int mWeightOz;
	int mDistanceToTravel;
	int mMilesPerDayCanTravel; 
	int mDayMinimumOfTravel; 
	bool mbInsured;
	bool mbRush;
};