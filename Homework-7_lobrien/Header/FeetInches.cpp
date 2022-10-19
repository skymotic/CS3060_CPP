/*
 * FeetInches.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: Luke O'Brien
 */

#include "FeetInches.h"

FeetInches::FeetInches()
{
	feet = 0;
	inches = 0;
}

FeetInches::FeetInches(int feetInput, int inchesInput)
{
	feet = feetInput;
	inches = inchesInput;
}

FeetInches::FeetInches(const FeetInches& obj)
{
	feet = obj.feet;
	inches = obj.inches;
}

int FeetInches::toInches()
{
	return (feet * 12) + inches;
}

double FeetInches::toFeet()
{
	return (toInches())/FOOTMARKER;
}

int FeetInches::getFeet()
{
	return feet;
}

int FeetInches::getInches()
{
	return inches;
}

FeetInches FeetInches::multiply(FeetInches x)
{
	int tempA = x.toInches() * toInches();
	int tempB = tempA/FOOTMARKER;
	tempA = tempA%FOOTMARKER;
	FeetInches tempC(tempB, tempA);
	return tempC;
}

void FeetInches::print()
{
	printf("%d Feet and %d Inches\n OR %d total inches", feet, inches, (feet*12)+inches );
}
