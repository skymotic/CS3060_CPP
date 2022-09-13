/*
 * main.cpp
 *
 *  Created on: Sep 11, 2022
 *      Author: Luke O'Brien
 *
 *  Program Description:
 *  	This program takes in a set of data and then calculates the Mode
 *  	if there is one, the program will return it with location of each occurrence.
 *  	otherwise program will return a -1 to indicate no mode
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

//prototypes
int getArraySize();
void setArrayData(int*, int);
int getMode(int*, int);

// ----- ----- ----- ----- ----- Main
int main()
{
	int arrSize = getArraySize();
	int arrMode[arrSize];

	setArrayData(arrMode, arrSize);

	int mode = getMode(arrMode, arrSize);

	cout << "\nThe mode of the following number set is:" << endl << "\t" << mode << endl;

	//If there is a Mode, print each index the mode appears at in the array
	if(mode != -1)
	{
		cout << "\nAppears at index/s:" << endl << "\t";

		for(int x=0; x<arrSize; x++){
			if(arrMode[x] == mode){
				cout << x << " ";
			}
		}
		cout << endl;
	}
}

/*		getArraySize
 * Description:
 * The following prompts the user for the overall size of the array
 * then checks the input for validity before returning value
 */
int getArraySize()
{
	int temp;
	cout << "Please enter the quantity of numbers in the array:" << endl;
	cout << "\t";

	//Asks for user input, then does a data check until condition is met
	//Condition: input > 0
	bool checkMet = false;
	while(!checkMet){
		cin >> temp;

		if(temp < 0){
			cout << "\tNumber must be above 0; try again" << endl;
		}
		else{
			checkMet = true;
		}
	}

	return temp;
}

/*		setArrayData
 * Description:
 * The following prompts the user for each data entry to be entered
 * into the array. Each prompt is checked for validity
 */
void setArrayData(int *arr, int arrSize)
{
	cout << "Please Enter each value to be considered for Mode; hit ENTER after each entry" << endl;

	int temp;
	for(int x=0; x<arrSize; x++)
	{
		cout << "\t" << x+1 << ":\t";

		//Asks for user input, then does a data check until condition is met
		//Condition: input > 0
		bool checkMet = false;
		temp = 0;
		while(!checkMet){
			cin >> temp;

			if(temp < 0){
				cout << "\t\tNumber must be above 0; try again" << endl;
			}
			else{
				checkMet = true;
			}
		}
		arr[x] = temp;
	}
	cout << "done" << endl;
}

/*		getMode
 * Description:
 * The following will take and array and scan through it calculating the mode
 * If found the function will return the mode
 * else function returns -1
 */
int getMode(int *arr, int arrSize)
{
	//used to track occurrence of each number
	int modeTrack[arrSize] = {};

	//scans through array to count each occurrence of each number
	//keeping track in modeTrack
	for(int x=0; x<arrSize; x++)
	{
		for(int y=0; y<arrSize; y++)
		{
			if( (x != y) && (arr[x] == arr[y]) ){
				modeTrack[x]++;
			}
		}
	}

	//Scans modeTrack to see which value had the highest occurrence
	int largest = -1;
	for(int x=0; x<arrSize; x++)
	{
		if(modeTrack[x] > modeTrack[largest]){
			largest = x;
		}
	}

	//checks if there is a mode
	if(largest == -1){
		return -1;
	}
	return arr[largest];
}
