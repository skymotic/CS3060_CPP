/*
 * main.cpp
 *
 *  Created on: Oct 10, 2022
 *      Author: Luke O'Brien
 *
 *  Description:
 *  The following Program takes input from the user
 *  and runs a series of checks to make sure it meets a
 *  set list of complexity requirements
 */

//Pre-Processor
#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>

//Program Definitions
#define PWLENGTH 8

// Defining Namespace
using namespace std;

// Prototypes
void removeNewLine(string&);
bool checkPwLength(string);
bool checkPwCase(string);
bool checkPwNum(string);
bool checkPwSpecial(string);
bool checkPwALL(string);

// ----- ----- ----- ----- ----- Main
int main()
{
	string input;
	cout << "Please enter the password you'd like to use:" << endl;
	cout << "\t";
	getline(cin, input);
	removeNewLine(input);
	if(checkPwALL(input)){
		cout << "Password is valid.\n\tThank you!" << endl;
	}
	else
	{
		cout << "Password is NOT valid.\n\tTry Again." << endl;
		main();
	}
}

void removeNewLine(string& x)
{
    x = regex_replace( x, regex("\\r\\n|\\r|\\n"), "" );
}

/*		Check Password Length
 * Description:
 * Checks input string and returns true if string meets
 * the length requirements
 */
bool checkPwLength(string str)
{
	if(str.length() >= PWLENGTH)
		return true;
	return false;
}

/*		Check Password Case
 * Description:
 * Checks a input string and returns true if string has
 * both 1 upper case letter and 1 lower case letter
 */
bool checkPwCase(string str)
{
	bool upperCheck = false;
	bool lowerCheck = false;

	for(int x=0; x<(int)str.length(); x++)
	{
		if(str[x] > 64 && str[x] < 91){
			upperCheck = true;
		}
		if(str[x] > 96 && str[x] < 123){
			lowerCheck = true;
		}
	}

	if(upperCheck && lowerCheck)
		return true;
	return false;
}

/*		Check Password Number
 * Description:
 * Checks input string and returns true if there is a
 * Number present
 */
bool checkPwNum(string str)
{
	for(int x=0; x<(int)str.length(); x++)
	{
		if(str[x] > 47 && str[x] < 58)
			return true;
	}
	return false;
}

/*		Check Password Special Character
 * Description:
 * Checks input string and returns true if there is a
 * Special character present
 */
bool checkPwSpecial(string str)
{
	string checkChars = "~@#$%^&*(!)-_=+{}[]|\\;:\"<>,./?";
	for(int x=0; x<(int)str.length(); x++)
	{
		for(int y=0; y<(int)checkChars.length(); y++)
		{
			if(str[x] == checkChars[y])
				return true;
		}
	}
	return false;
}

/*		Check Password
 * Description:
 * Using all of the Checks above, this function will only
 * return true if all Checks are met
 */
bool checkPwALL(string str){
	if(checkPwSpecial(str) && checkPwNum(str) && checkPwCase(str) && checkPwLength(str))
		return true;
	return false;
}
