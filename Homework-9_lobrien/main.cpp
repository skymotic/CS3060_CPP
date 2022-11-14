/*
 * main.cpp
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "courseGrades.h"

int main()
{
	CourseGrades classroom;
	GradedActivity theLab;
	PassFailExam thePassFail;
	Essay theEssay;
	FinalExam theFinal;
	string input;

	printf("Out of %d; Please enter the grade for the Lab\n\t:", theLab.getMaxScore());
	cin >> input;
	theLab.setGrade(int(input));

	printf("Out of %d; Please enter the grade for the Pass/Fail Exam\n\t:", thePassFail.getMaxScore());
	cin >> input;
	thePassFail.setGrade(int(input));

	printf("Out of %d; Please enter the grade for the Essay\n\t:", theEssay.getMaxScore());
	cin >> input;
	theEssay.setGrade(int(input));

	printf("Out of %d; Please enter the grade for the Final Exam\n\t:", theFinal.getMaxScore());
	cin >> input;
	theFinal.setGrade(int(input));


	classroom.setLab(theLab);
	classroom.setPassFailExam(thePassFail);
	classroom.setEssay(theEssay);
	classroom.setPassFailExam(theFinal);

	classroom.print();

}
