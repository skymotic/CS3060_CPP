/*
 * FeetInches.cpp
 *
 *  Created on: Oct 18, 2022
 *      Author: Luke O'Brien
 *
 *  Class Description:
 *  This class is meant for objectional use. It is an easy way to store a measurement of
 *  something in the American Standard of Feet and Inches.
 */

#pragma once

#ifndef FEET_INCHES_H
#define FEET_INCHES_H

#include <stdio.h>
#define FOOTMARKER 12

class FeetInches
{
	int feet;
	int inches;
public:

	FeetInches();
	FeetInches(int, int);
	FeetInches(const FeetInches&);

	int toInches();
	double toFeet();

	int getFeet();
	int getInches();

	FeetInches multiply(FeetInches);
	void print();
};

#endif
