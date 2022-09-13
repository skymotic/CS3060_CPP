/*
 * main.cpp
 *
 *  Created on: Sep 4, 2022
 *      Author: <REDACTED>
 *
 *  Program Description:
 *  	This program is designed to help zoo-keepers track and
 *  	metric the amount of food that the monkeys are eating in
 *  	their exhibit
 *
 *  	After inputting the information as prompted, the program
 *  	will generate a report listing the daily average, the least
 *  	amount of food eaten and by what monkey, then the most amount
 *  	of food eaten and by what monkey
 */

//pre-processor directives
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

//method prototypes
void setFoodAmount(int**, int, int);
void preReportCalc(int**, int, int);
void printReport(int[], int, int[], int[]);
void print2dArray(int**, int, int);

// ***** ***** ***** ***** ***** Start of Main
int main()
{
	// Program is dynamically coded for the values below
	const int daysTracked = 5;
	const int numMonkeys =  3;
	int **monkeyFoodWeekly;

	//Initializes monkeyFoodWeekly
	monkeyFoodWeekly = new int *[daysTracked];
	for(int x=0; x<daysTracked; x++){
		monkeyFoodWeekly[x] = new int[numMonkeys];
	}

	//Method calls
	setFoodAmount(monkeyFoodWeekly, daysTracked, numMonkeys);
	preReportCalc(monkeyFoodWeekly, daysTracked, numMonkeys);
}

/*		setFoodAmount
 * Description:
 * using the size delimiters, this method prompts the user
 * for the amount each monkey was fed over the previous specified time
 * before entering the data into the array passed
 */
void setFoodAmount(int** arr, int colu, int row)
{
	for(int x=0; x<colu; x++){
		cout << "for Day #" << x+1 << " of the week:" <<endl;
		for(int y=0; y<row; y++){
			cout << "\tHow many lbs of food did Monkey #" << y+1 << " eat?:\t";

			//boolean and while for input checking
			bool checkMet = false;
			while(!checkMet){
				cin >> arr[x][y];

				if(arr[x][y] > 0){
					checkMet = true;
				}
				else{
					cout << "\t\tnumber must be above 0; Try again:\t";
				}
			}//end while
		}
		cout << endl;
	}
}

/*		preReportCalc
 * Description:
 * takes set data entered in the array and calculates the following:
 * 		daily average food eaten
 * 		least amount of food eaten
 * 		most amount of food eaten
 * 	before exporting the data to be printed into a report
 */
void preReportCalc(int** arr, int colu, int row)
{
	int dailyAverage[colu] = {};
	int leastEatenWeekly[3] = {arr[colu-1][row-1], row-1, colu-1};
	int mostEatenWeekly[3] = {};

	//Calculate daily average
	for(int x=0; x<colu; x++){
		int temp = 0;
		for(int y=0; y<row; y++){
			temp += arr[x][y];
		}
		dailyAverage[x] = temp/row;
	}

	//Calculate least eaten
	for(int x=0; x<colu; x++){
		for(int y=0; y<row; y++){
			if(arr[x][y] < arr[leastEatenWeekly[2]][leastEatenWeekly[1]]){
				leastEatenWeekly[0] = arr[x][y];
				leastEatenWeekly[1] = y;
				leastEatenWeekly[2] = x;
			}
		}
	}

	//Calculate most eaten
	for(int x=0; x<colu; x++){
		for(int y=0; y<row; y++){
			if(arr[x][y] > arr[mostEatenWeekly[2]][mostEatenWeekly[1]]){
				mostEatenWeekly[0] = arr[x][y];
				mostEatenWeekly[1] = y;
				mostEatenWeekly[2] = x;
			}
		}
	}

	printReport(dailyAverage, colu, leastEatenWeekly, mostEatenWeekly);
}

/*		PrintReport
 * Description:
 * takes in the data previously calculated and prints a report
 *
 * DailyAverage:	each data point is the daily average starting from day #1
 * numDays: 		number of days tracked (length of DailyAverage)
 *
 * leastEatenWeekly/mostEatenWeekly:
 * 		[0] = Value of Least/Most food eaten
 * 		[1] = Monkey # who ate least/most food
 * 		[2] = Day least/most food was eaten
 */
void printReport(int dailyAverage[], int numDays, int leastEatenWeekly[], int mostEatenWeekly[])
{
	cout << "\tWeekly Monkey Food Report" << endl;
	cout << endl <<  "***** ***** ***** ***** *****" << endl << endl;
	cout << "Average amount of food eaten each day:" << endl;
	for(int x=0; x<numDays; x++){
		cout << "\tDay #" << x+1 << ": " << dailyAverage[x] << " lbs" << endl;
	}
	cout << endl <<  "***** ***** ***** ***** *****" << endl << endl;
	cout << "The least amount eaten this week was:" << endl;
	cout << "\t" << leastEatenWeekly[0] << " lbs" << endl;
	cout <<	"\tBy Monkey #" << leastEatenWeekly[1]+1 << endl;
	cout << "\tOn Day #" << leastEatenWeekly[2]+1 << endl;
	cout << endl <<  "***** ***** ***** ***** *****" << endl << endl;
	cout << "The least amount eaten this week was:" << endl;
	cout << "\t" << mostEatenWeekly[0] << " lbs" << endl;
	cout <<	"\tBy Monkey #" << mostEatenWeekly[1]+1 << endl;
	cout << "\tOn Day #" << mostEatenWeekly[2]+1 << endl;
	cout << endl <<  "***** ***** ***** ***** *****" << endl << endl;
	cout << "\t\tEnd of Report";

}

/*		Print2dArray (testing only)
 * Description:
 * Prints each value in a 2d array separated by a space
 * 	Designed for debugging
 */
void print2dArray(int** arr, int colu, int row)
{
	for(int y=0; y<row; y++){
		for(int x=0; x<colu; x++){
			cout << arr[x][y] << " ";
		}
		cout << endl;
	}
}
