/*
 * main.cpp
 *
 *  Created on: Sep 18, 2022
 *      Author: Luke O'Brien
 *
 *  Program Description:
 *  Program creates a structure to hold and maintain
 *  all customer information. Program contains functions
 *  to manipulate and search each entry.
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

// Structure to hold all customer Data
struct customerProfile
{
	string name;
	string address;
	string csz; //City, state, Zip
	double balance;
	string lastPayment;
};

//Prototypes
void addData(customerProfile&);
void removeNewLine(string&);

void changeName(customerProfile&);
void changeAddress(customerProfile&);
void changeCSZ(customerProfile&);
void changeBal(customerProfile&);
void changeLastDate(customerProfile&);
int userSelection(customerProfile[], int);
void editMenu(customerProfile&);
void printProfile(customerProfile);
int profileSearch(customerProfile[], int);


// ----- ----- ----- ----- ----- Main
int main()
{
	//Asks uer how many customer profiles need to be
	//made and stored in the array.
	int arrLength;
	cout << "how many profiles would you like to create?" << endl;
	cin >> arrLength;

	//Variables defining the main storage and content of
	//all customer profiles
	customerProfile arr[arrLength];

	//Scans through entire array and defines each value
	for(int x=0; x<arrLength; x++) { addData(arr[x]); cout << endl; }
	cout << endl << "Data Entered" << endl;

	//Starts a loop; beginning of top level menu
	//	Loop ends if exit code '3' is entered
	int input = -1;
	while(input != 3){
		cout << "Please select the function you'd like to do:" << endl;
		cout << "\t[1] Print\n\t[2] Edit\n\t[3] Exit\n\t[4] Search\n" << endl;
		cin >> input;

		//handles userInput and directs to sub menus/functions
		switch(input)
		{
			case 1: printProfile(arr[userSelection(arr, arrLength)]); break;
			case 2: editMenu(arr[userSelection(arr, arrLength)]); break;
			case 4:
				int temp = profileSearch(arr, arrLength);
				if(temp == -1)
					cout << "A Profile matching that pattern does not exist\n";
				else
					printProfile(arr[temp]);
				break;
		}
	}
	cout << "Program End" << endl;
}

/*		AddData
 * Description:
 * This function calls upon all change functions
 * to get the first time values set for the structure
 */
void addData(customerProfile& x)
{
	cout << "New Customer" << endl;
	changeName(x);
	changeAddress(x);
	changeBal(x);
	changeLastDate(x);
}

/*		RemoveNewLine
 * Description:
 * Removes an 'newLine' values from a string using
 * RegEx
 */
void removeNewLine(string& x)
{
    x = regex_replace( x, regex("\\r\\n|\\r|\\n"), "" );
}

/*		ChangeName
 * Description:
 * This Function asks the user to update the name
 * stored in the structure.
 * Then error checks the input to verify a value
 * was entered
 */
void changeName(customerProfile& x)
{
	string temp;
	cout << "\tInput the customers new Name:\t";

	//input and error checking
	bool checkMet = false;
	while(!checkMet){
		getline(cin, temp);
		removeNewLine(temp);
		if(temp.length() > 2){
			checkMet = true;
			x.name = temp;
		}
		else
			cout << "Please enter a value";

	}
}

/*		ChangeAddress
 * Description:
 * This function asks user to update the Address
 * stored in the structure for address
 * Then does error checking on the input to verify
 * a value was entered
 */
void changeAddress(customerProfile& x)
{
	string temp;
	cout << "\tInput " << x.name << "'s new address:\t";

	//Input and Error Chekcing
	bool checkMet = false;
	while(!checkMet){
		getline(cin, temp);
		removeNewLine(temp);
		if(temp.length() > 2){
			checkMet = true;
			x.address = temp;
		}
		else
			cout << "\t\tPlease enter a value";

	}
	changeCSZ(x);
}

/*		ChangeCSZ
 * CSZ = City, State, Zip
 * Description:
 * This function asks the user to update the
 * City, State and Zip
 * Then error checks the input to make sure a value
 * was entered
 */
void changeCSZ(customerProfile& x)
{
	string temp;
	cout << "\tInput " << x.name << "'s new City State, and Zip:\t";

	//input and error checking
	bool checkMet = false;
	while(!checkMet){
		getline(cin, temp);
		removeNewLine(temp);
		if(temp.length() > 2){
			checkMet = true;
			x.csz = temp;
		}
		else
			cout << "\t\tPlease enter a value";

	}
}

/*		ChangeBal
 * Description:
 * This function asks the user to update the
 * balance of the users account
 * Then does error checking on input to verify the value
 * entered was positive.
 */
void changeBal(customerProfile& x)
{
	int temp;
	string temp1;
	cout << "\tInput the customers new Balance:\t";

	//input and error checking
	bool checkMet = false;
	while(!checkMet){
		getline(cin, temp1);
		removeNewLine(temp1);
		temp = stod(temp1);
		if(temp > 0){
			checkMet = true;
			x.balance = temp;
		}
		else
			cout << "\t\tPlease enter a value above 0";

	}
}

/*		ChangeLastDate
 * Description:
 * This function asks the user to update the
 * Date of last payment.
 * Then does error checking on input to make sure a value
 * was entered
 */
void changeLastDate(customerProfile& x)
{
	string temp;
	cout << "\tInput the customers Last Date of Payment:\t";

	//input and error checking
	bool checkMet = false;
	while(!checkMet){
		getline(cin, temp);
		removeNewLine(temp);
		if(temp.length() > 2){
			checkMet = true;
			x.lastPayment = temp;
		}
		else
			cout << "\t\tPlease enter a value";

	}
}

/*		UserSelection
 * Description:
 * This function displays all the users stored in the
 * array in a numbered menu for the user to easily select
 *
 * Returns array index of selected user
 */
int userSelection(customerProfile arr[], int arrLength)
{
	int userSel;
	cout << "Please enter the number for your customer selection:" << endl;

	//displays all users and asks for input
	for(int x=0; x<arrLength; x++)
		cout << "[" << x+1 << "] " << arr[x].name << endl;
	cin >> userSel;
	return userSel-1;
}

/*		EditMenu
 * Description:
 * This function Displays and manages an edit menu on the
 * console screen for the user to easily choose what types
 * of edits they would like to make to the profile
 */
void editMenu(customerProfile& profile)
{
	//lists all selections for menu
	int editSelection;
	string editTypes[] = { "Change name", "Change Address",
						   "Change City, State, ZIP" , "Change Balance",
						   "Change Date of Last Payment" };

	//displays menu and asks for input
	cout << "Please enter the number of the type of edit you'd like to make" << endl;
	for(int x=0; x<5; x++)
		cout << "[" << x+1 << "] " << editTypes[x] << endl;
	cin >> editSelection;

	//directs the users selection to proper edit function
	switch(editSelection) {
		case 1: changeName(profile); break;
		case 2: changeAddress(profile); break;
		case 3: changeCSZ(profile); break;
		case 4: changeBal(profile); break;
		case 5: changeLastDate(profile); break;
	}
}

/*		PrintProfile
 * Description:
 * This function takes the structure and prints out all
 * the data stored within.
 * Prints: Name, Address, Balance, and Last Payment Date
 */
void printProfile(customerProfile x)
{
	printf("Printing Customer Profile:\n");
	printf("\tCustomer's Name:\t\t%s\n", x.name.c_str());
	printf("\tCustomer's Address:\t\t%s\n\t\t\t\t\t%s\n", x.address.c_str(), x.csz.c_str());
	printf("\tCustomer's Balance:\t\t$%.2lf\n", x.balance);
	printf("\tCustomer's Last Payment Date: \t%s\n\n", x.lastPayment.c_str());
}

/*		ProfileSearch
 * Description:
 * This functions takes a 'pattern' to search for from
 * the user, then compares every substring of every profile
 * before returning a match or not.
 */
int profileSearch(customerProfile arr[], int arrLength)
{
	string pattern;

	cout << "Please Enter your search pattern" << endl;
	cin >> pattern;

	//Top Level for scans through each profile
	for(int x=0; x<arrLength; x++)
	{
		//Bottom Level for scans through all substrings of the name
		for(int y=0; y<arr[x].name.length()- pattern.length(); y++)
		{
			if(arr[x].name.substr(y, pattern.length()) == pattern)
			{
				cout << x << endl;
				return x;
			}
		}
	}
	return -1;
}
