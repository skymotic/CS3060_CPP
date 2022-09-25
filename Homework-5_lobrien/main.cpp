/*
 * main.cpp
 *
 *  Created on: Sep 25, 2022
 *      Author: Luke O'Brien
 *
 * 	Program Description:
 *  This program creates an array of structures from data given;
 * 	it will then prompt the user if they want to add items, remove items, 
 * 	or list the items. 
 * 	After choosing their action it will propmt the user with a selection of
 *	all 'bins' stored in the array.
 *	They can make their selection and tell it how much to add/remove
 */

//Pre-Processor Directives
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

// Defining Namespace Standard
using namespace std;

//Data Structure
struct partsBin
{
	string name;
	int count;
};

// Function Prototypes
void setData(partsBin[], int);
void addParts(int, partsBin[], int);
void removeParts(int, partsBin[], int);
int partsMenu(partsBin[], int);
void actionMenu(partsBin[], int);
void listStructArr(partsBin[], int);

// ----- ----- ----- ----- ----- Main
int main()
{
	int partsSize = 10;
	partsBin parts[partsSize];

	setData(parts, partsSize);
	actionMenu(parts, partsSize);
}

/*		setData
 * Description:
 * Scans through the array and passed all initial data
 * In true application would be reading from database
 * or file
 */
void setData(partsBin arr[], int arrSize)
{
	string partNames[] = {"Valve", "Bearing", "Bushing",
						"Coupling", "Flange", "Gear",
						"Gear Housing", "Vacuum Gripper",
						"Cable", "Rod"};
	int partCount[] = {10, 5, 15, 21, 7, 5, 5, 25, 18, 12};
	for(int x=0; x<arrSize; x++)
	{
		arr[x].name = partNames[x];
		arr[x].count = partCount[x];
	}
}

/*		addParts
 * Description:
 * Will edit the array and add the number of parts
 * defined by user to the "bin"
 */
void addParts(int sel, partsBin arr[], int arrSize)
{
	int input;
	bool checkMet = false;

	//While loop for input validation;
	//Checking if number entered will equate to invalid total in bin
	while(!checkMet){
		printf("Enter how many parts you are adding to the %s bin\n\t",
													arr[sel].name.c_str());
		cin >> input;
		if((input + arr[sel].count) <= 30)
			checkMet = true;
		else
			cout << "\tTotal Number must be below 30; try again\n" << endl;
	}

	//sets data in array
	arr[sel].count += input;
	printf("\n\n");
}

/*		removeParts
 * Description:
 * Will edit the array and add the number of parts
 * defined by user to the "bin"
 */
void removeParts(int sel, partsBin arr[], int arrSize)
{
	int input;
	bool checkMet = false;

	//While loop for input validation;
	//Checking if number entered will equate to invalid total in bin
	while(!checkMet){
		printf("Enter how many parts you are removing from the %s bin\n\t",
													arr[sel].name.c_str());
		cin >> input;
		if((arr[sel].count - input) >= 0)
			checkMet = true;
		else
			cout << "\tTotal Number must be above 0; try again\n" << endl;
	}

	//Sets data in array
	arr[sel].count -= input;
	printf("\n\n");
}

/*		partsMenu
 * Description:
 * Will Print out an array of "partsBin" before asking
 * for a selection
 */
int partsMenu(partsBin arr[], int arrSize)
{
	int temp;
	printf("Sel\t%-20s%s\n\n", "Part Name", "Count");
	for(int x=0; x<arrSize; x++)
	{
		printf("[%d]\t%-20s%d\n", x+1, arr[x].name.c_str(), arr[x].count);
	}
	printf("\nPlease Enter the number of the item you'd like to edit\n\t");
	cin >> temp;
	printf("\n");
	return temp-1;
}

/*		actionMenu
 * Description:
 * Will Print a list of available actions then asks
 * for a selection of one action
 */
void actionMenu(partsBin arr[], int arrSize)
{
	int input = 0;
	while(input != 4)
	{
		//Lists available actions
		printf("Please enter your action selection:\n");
		printf("\t[1] Adding Parts to bin\n");
		printf("\t[2] Removing Parts from bin\n");
		printf("\t[3] List Bins\n");
		printf("\t[4] Exit Program\n");

		//gets user input
		cin >> input;
		printf("\n\n");

		//Directs selection
		switch(input)
		{
			case 1: addParts(partsMenu(arr, arrSize),arr, arrSize); break;
			case 2: removeParts(partsMenu(arr, arrSize),arr, arrSize); break;
			case 3: listStructArr(arr, arrSize); break;
			case 4: break;
			default: cout << "\t\tInvalid input, Try again" << endl; break;
		}
	}
}

/*		listStructArr	(partsBin)
 * Description:
 * Will list all items for a partsBin structure array
 */
void listStructArr(partsBin arr[], int arrSize)
{
	printf("%-20s%s\n\n", "Part Name", "Count");
	for(int x=0; x<arrSize; x++)
	{
		printf("%-20s%d\n", arr[x].name.c_str(), arr[x].count);
	}
	printf("\n\n");
}
