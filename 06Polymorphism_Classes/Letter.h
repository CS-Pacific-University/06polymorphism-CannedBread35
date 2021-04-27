#pragma once
//***************************************************************************
// File name:		Letter.h
// Author:			Taylor Isaac
// Date:				4/27/2021
// Class:				CS 250
// Assignment:  046Polymorphism_Classes
// Purpose:			Demonstrate the Letter class
//***************************************************************************
#include <string>
#include <iostream>
#include "Parcels.h"

using namespace std;

class Letter : public Parcels {
	public:
		Letter ();

		virtual bool read (istream&);
		virtual void print(ostream&);

		virtual double getCost();
		virtual int getDaysForDelivery() ;
		virtual double getInsuranceExpense(double) const;
		virtual double getRushExpense(double) const;

private:
	double insuranceFlatRate;
	double rushCostMultiplier;
};