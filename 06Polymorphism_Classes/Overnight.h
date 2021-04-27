#pragma once
//***************************************************************************
// File name:		Overnight.h
// Author:			Taylor Isaac
// Date:				4/23/2021
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
		Overnight();
		virtual bool read(istream&);
		virtual void print(ostream&);
		
		int getVol() const { return mVol; }

		// These are pure virtual functions where the parent can't just call it.
		virtual double getCost();
		virtual int getDaysForDelivery();
		virtual double getInsuranceExpense(double) const;
		virtual double getRushExpense(double) const;
	

	private:
		int mVol;
		double insuranceCostMultiplier;
		double rushCostMultiplier;
	};