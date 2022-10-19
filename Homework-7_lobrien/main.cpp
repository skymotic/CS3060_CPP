/*
 * main.cpp
 *
 *  Created on: Oct 18, 2022
 *      Author: Luke O'Brien
 */

#include <stdio.h>
#include <iomanip>
#include <iostream>

#include "Header/FeetInches.h"
#include "Header/RoomCarpet.h"
#include "Header/RoomDimensions.h"

using namespace std;

int main()
{
	int feetInput, inchesInput;
	cout << "Please Enter the width of the room in feet, then inches\nEX: 10 11" << endl;
	cin >> feetInput; cin >> inchesInput;
	FeetInches width(feetInput, inchesInput);

	cout << "Please Enter the Length of the room in feet, then inches\nEX: 10 11" << endl;
	cin >> feetInput; cin >> inchesInput;
	FeetInches length(feetInput, inchesInput);

	double priceInput;
	cout << "What is the price of the carpet by Square foot" << endl << "$";
	cin >> priceInput;

	RoomDimensions roomDimension(width, length);
	RoomCarpet room(roomDimension, priceInput);
	cout << endl;

	printf("Width: %d\"%d\'\tHeight: %d\"%d\'\n",
					room.getDemensions().getWidth().getFeet(),
					room.getDemensions().getWidth().getInches(),
					room.getDemensions().getLength().getFeet(),
					room.getDemensions().getLength().getInches());
	printf("The Price Estimate is:\t$%.2lf", room.getCost());
}
