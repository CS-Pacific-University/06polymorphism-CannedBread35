#pragma once
//***************************************************************************
// File name:		Overnight.h
// Author:			Taylor Isaac
// Date:				5/2/2021
// Class:				CS 250
// Assignment:  06Polymorphism_Classes
// Purpose:			Demonstrate the Overnight class
//***************************************************************************
#include <string>
#include <iostream>
#include "Parcels.h"
using namespace std;

class Overnight : public Parcels {
	public:
		Overnight ();
		int getVol () const { return mVol; }

		virtual bool read (istream&);
		virtual void print (ostream&);
		
		virtual double getCost ();
		virtual int getDaysForDelivery ();
		virtual double getInsuranceExpense (double) const;
		virtual double getRushExpense (double) const;
	
	private:
		int mVol;
		double mInsuranceCostMultiplier;
		double mRushCostMultiplier;
	};