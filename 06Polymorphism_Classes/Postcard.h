#pragma once
//***************************************************************************
// File name:		Postcard.h
// Author:			Taylor Isaac
// Date:				5/2/2021
// Class:				CS 250
// Assignment:  06Polymorphism_Classes
// Purpose:			Demonstrate the Postcard class
//***************************************************************************

#include <string>
#include <iostream>
#include "Parcels.h"

using namespace std;

class Postcard : public Parcels {
	public:
		Postcard ();
		virtual bool read (istream&);
		virtual void print (ostream&);

		virtual double getCost (); 
		virtual int getDaysForDelivery ();
		virtual double getInsuranceExpense (double) const;
		virtual double getRushExpense (double) const;

	private:
		string mMessage;
		double mInsuranceFlatRate;
		double mRushCost;
	};