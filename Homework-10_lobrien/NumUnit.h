/*
 * NumUnit.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Luke O'Brien
 *
 *  Class Description:
 *  Class is designed to hold a word and count the occurrences
 *  of said word
 */

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

#ifndef NUMUNIT_H_
#define NUMUNIT_H_

class NumUnit
{
private:
	string word;
	int freq;

public:
	NumUnit(string x) {
		word = x;
		freq = 1;
	}
	NumUnit(){
		word = "";
		freq = 0;
	}

	void setWord(string x) { word = x; }
	string getWord() { return word; }
	void incFreq() { freq += 1; }
	void dexFreq() { freq -= 1; }
	void setFreq(int x) { freq = x; }
	int getFreq() { return freq; }

	void print()
	{
		printf("|%-10s|%-5d|\n", word.c_str(), freq);
	}

};

#endif /* NUMUNIT_H_ */
