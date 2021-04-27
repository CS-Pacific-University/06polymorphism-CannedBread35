#pragma once
//***************************************************************************
// File name:		Parcels.h
// Author:			Taylor Isaac
// Date:				4/22/2021
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
	virtual bool read(istream&);
	virtual void print(ostream&);
	static bool getValidUserTID(int index, Parcels* apcArrayOfParcels[],
															int userChoice);
	bool getInsuranceTruth();
	bool getRushTruth();
	int getWeightOz() const { return mWeightOz; }
	int getDistance() const { return mDistanceToTravel; }

	virtual double getCost () = 0; 
	virtual int getDaysForDelivery() = 0;
	virtual double getInsuranceExpense (double) const = 0; // We include the double for the sake of calculating the overall current cost of Overnight insurance cost
	virtual double getRushExpense(double) const = 0;

	
	void addInsurance();
	void addRush();
private:
	string mTypeOfParcel;
	int mTrackingNumb;
	string mToAddress;
	string mFromAddress;
	int mWeightOz;
	int mDistanceToTravel;
	int mMilesPerDayCanTravel; 
	int mDayMinimumOfTravel; 
	bool bInsured;
	bool bRush;
};

// *Left off with the implementation of adding rush to a parcel
// Left off with these questions down below.
// *Also left off with feeling the need to fix and make insuranceExpense a 
//  parent's private data member variable
// QUESTIONS:
// 0. 
// 0. Should I make the insuranceExpenseOrMultiplier ig a member variable for 
//		the parent class? And then have set functions for each unique derived
//		class? Passing in each unique double insurance expense to set it for 
//		each unique member variable?
// 1. Output error with "INSURED" on line below when you are saying that a 
//		parcel has been INSURED!
// 2. How to correctly delete a specific pointer from the array of pointers,
//		and have it where the next time the parcels are printed, that specific
//		parcel disappears?










// THINGS TO REMEMBER: 
// 1. this pure virtual function, here, it CANNOT be defined in the parent 
// class, but in its derived classes, MUST implement
// 2. (if parent has a pure virtual function need ASAP to implement on 
//     child(s))
// 3. Add pure virtual if it's rquired the derived class needs to override 
// the function. For example, getCost, Parcel, you don't know what type, we 
// don't know exact cost , we need to know what type of parcel to calculate 
// unique cost you can't just get the payCost of the overall class Employee 
// because we doN't know if they're salaried or hourly. If we create a child
// of the employee we have to have a derived function to know how the unique 
// employee gets payed. REQUIRED OVERRIDEN

// 4. Add virtual, employee does know what to do, BUT child might want to 
// change print and read, the original parent function for reading in knows 
// how to read, but the children want to have the option a more specialized 
// function

