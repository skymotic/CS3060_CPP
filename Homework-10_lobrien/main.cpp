/*
 * main.cpp
 *
 *  Created on: Nov 13, 2022
 *      Author: Luke O'Brien
 * 
 *  Program Description:
 *  The following program is designed to take in a file and count
 *  the occurrences of each word
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "NumUnit.h"
using namespace std;

int main()
{
	// Creating and opening Data.txt file
	ifstream myfile;
	myfile.open("Data.txt");

	// Counting all the words in the file and putting it in counter
	int counter = 0;
	string word;
	while(myfile >> word) { counter++; }

	// Resetting the File IO Pointer & creating the Object Ptr Array
	// dictionary, Filling it will nulls
	myfile.clear(); myfile.seekg(0);
	NumUnit *dictionary[counter];
	for(int x=0; x<counter; x++) { dictionary[x] = NULL; }

	//While there is a next word
	while(myfile >> word)
	{
		bool check = false;
		int index = 0;

		// Cycle through the Dictionary array to check for Duplicates
		// setting the 'Check' flag if duplicate is found. returning index of duplicate
		for(int x=0; x<counter; x++){
			if(!check && dictionary[x] != NULL){
				if(dictionary[x]->getWord() == word){
					check = true;
					index = x;
				}
			}
		}

		// If there is duplicate, increase word frequency in object
		if(check)
			dictionary[index]->incFreq();
		
		// If No duplicate, find next open spot and create NumUnit Object
		else
		{
			bool secondCheck = false;
			for(int x=0; x<counter; x++){
				if(dictionary[x] == NULL && !secondCheck){
					dictionary[x] = new NumUnit(word);
					secondCheck = true;
				}
			}
		}

	}

	myfile.close();

	//Scanning through Dictionary array and printing results
	for(int x=0; x<counter; x++)
		if(dictionary[x] != NULL)
			dictionary[x]->print();


	cout << "print done" << endl;

}
