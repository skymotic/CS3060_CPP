/*
 * main.cpp
 *
 *  Created on: Oct 1, 2022
 *      Author: Luke O'Brien
 *
 *  Program Description:
 *  The following program creates a class called 'Car'
 *  and uses that class to create an object (an instance of a class)
 *  that is able to run object functions and data accessors
 */

// Pre-Processor Directives
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

//Declaring namespace
using namespace std;

//Classes
class Car
{
	int yearModel;
	string make;
	int speed;

public:
	//Constructor w/ inputs
	Car(int carYear, string carMake, int carSpeed) {
		yearModel = carYear;
		make = carMake;
		speed = carSpeed;
	}

	//constructor w/o inputs
	Car() {
		yearModel = 0; speed = 0; make = {};
		cout << "Enter car Year" << endl;
		cin >> yearModel;
		cout << "Enter Cars Make" << endl;
		getline(cin, make); cin.ignore();
	}

	// Accessors
	int getYear() { return yearModel; }
	string getMake() { return make; }
	int getSpeed() { return speed; }

	// Functions
	void accelerate() { speed += 5; }
	void brake() { speed -= 5; }
};

//Prototypes
void printCar(Car);

// ----- ----- ----- ----- ----- Main
int main()
{
	// Creates a 'Car' object w/ the following data
	Car myCar(2017, "Subaru Outback", 25);
	printCar(myCar);

	cout << "\nStarting Acceleration:" << endl;

	// Runs the Accelerate function 5 times
	for(int x=0; x<5; x++){
		myCar.accelerate();
		printCar(myCar);
	}

	cout << "\nStarting Braking:" << endl;

	// Runs the Brake Function 5 times
	for(int x=0; x<5; x++){
		myCar.brake();
		printCar(myCar);
	}

	return 0;
}

/*		printCar
 * Description:
 * The following will print out all the stats of a
 * Car object
 */
void printCar(Car x)
{
	printf("The %d %s is going %d MPH\n", x.getYear(), x.getMake().c_str(), x.getSpeed());
}
