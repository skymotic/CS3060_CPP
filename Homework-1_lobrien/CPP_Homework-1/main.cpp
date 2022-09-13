/*
 * main.cpp
 *
 *  Created on: Aug 28, 2022
 *      Author: Luke O'Brien
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Prototypes
int getRoomNum();
double getPaintPrice();
void setRoomData(double*, int);
void calcResults(int, double*, double);
void printRecipt(int, double, double, double, double);

//Global Variables
const double laborPrice = 25;
const double hoursToPaintRatio = (double)8/110;
const double sizeToPaintRatio = (double)1/110;

// ----- ----- ----- ----- ----- main
int main()
{
	int roomNum = getRoomNum();
	const double paintPrice = getPaintPrice();
	double roomArr[roomNum] = {};
	setRoomData(roomArr, roomNum);

	calcResults(roomNum, roomArr, paintPrice);

	return 0;
}

/* getRoomNum:
 * This function prompts the user with a questions, then takes
 * the input, temporarily storing it before returning it
 */
int getRoomNum()
{
	bool checkMet = false;
	int rooms;

	//The while loop is for Error Checking the input
	while(!checkMet)
	{
		cout << "How many rooms are there to paint?" << endl;
		cin >> rooms;

		if(rooms >= 1){
			checkMet = true;
		}
		else{
			cout << "Invalid input, There must be atleast 1 room to paint, Please try again." << endl;
		}
	}

	return rooms;
}

/* getPaintPrice:
 * This function prompts the user for the paint price, temporarily
 * storing it until it and return the value
 */
double getPaintPrice()
{
	bool checkMet = false;
	double price;

	//The while loop is for Error Checking the input
	while(!checkMet)
	{
		cout << "What is the price of the paint /gal?" << endl;
		cin >> price;

		if(price >= 10){
			checkMet = true;
		}
		else {
			cout << "Invalid input, Paint must be above $10, Please try again." << endl;
		}
	}

	return price;
}

/* setRoomData
 * This function takes the number of rooms and an array passed
 * by reference to systematically prompt and set the size of the
 * room
 */
void setRoomData(double *arr, int sizeOfArr)
{
	for(int x=0; x<sizeOfArr; x++)
	{
		bool checkMet = false;

		//The while loop is for Error Checking the input
		while(!checkMet)
		{
			cout << "How many squarefeet is Room #" << x+1 << "?" << endl;
			cin >> arr[x];

			if(arr[x] > 0){
				checkMet = true;
			}
			else{
				cout << "Invalid Input, Please try again." << endl;
			}
		}
		cout << "----------\n";
	}
}

/*
 * This function takes all the data and uses it to complete the final
 * calculations needed to give the customer the correct price for
 * labor and paint
 */
void calcResults(int sizeOfArr, double *arr, double price)
{
	//process total amount of sqrfeet to paint
	double totalSize;
	for(int x=0; x<sizeOfArr; x++)
	{
		totalSize = totalSize + arr[x];
	}

	double totalHours = totalSize * (double)hoursToPaintRatio;
	double totalLaborCost = (double)laborPrice*totalHours;

	//Calculates paint by fraction, but then rounds up a can (for potential mistakes in painting)
	int totalPaint = totalSize * sizeToPaintRatio +1;
	double totalPaintCost = price * totalPaint;

	printRecipt(totalPaint, totalHours, totalPaintCost, totalLaborCost, totalSize);
}

/* printRecipt
 * Prints out the Recipt with all the compelted calculations and final numbers
 * all nicely rounded to 2 decimal places where applicable
 */
void printRecipt(int paint, double labor, double paintCost, double laborCost, double size)
{
	cout << "Thank you for choosing O'Brien Painting" << endl;
	cout << "********************" << endl;
	cout << "Total SqrFeet:\t\t\t" << int(size) << endl;
	cout << "Number of paint cans:\t\t" << paint << endl;
	cout << "Number of hours expected:\t" << setprecision(2)<< fixed << labor << endl;
	cout << "Cost of Paint:\t\t\t$" << setprecision(2) << fixed << paintCost << endl;
	cout << "Cost of Labor\t\t\t$" << setprecision(2) << fixed << laborCost << endl;
	cout << "********************" << endl;
	cout << "total Cost:\t\t\t$" << setprecision(2) << fixed << paintCost + laborCost << endl;
}
