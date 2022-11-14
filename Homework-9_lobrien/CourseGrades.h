/*
 * CourseGrades.h
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

#include "GradedActivity.h"
#include "PassFailExam.h"
#include "Essay.h"
#include "FinalExam.h"

#ifndef COURSEGRADES_H_
#define COURSEGRADES_H_
const int arrLength = 4;
class CourseGrades
{
private:
	Grades * grades;

public:
	CourseGrades()
	{
		for(int x=0; x<arrLength; x++)
		{
			grades[x] = 0;
		}
	}
	void setLab(GradedActivity x) { grades[0] = &x; }
	void setPassFailExam(PassFailExam& x) { grades[1] = &x; }
	void setEssay(Essay& x) { grades[2] = &x; }
	void setPassFailExam(FinalExam& x) { grades[3] = &x; }

	void print()
	{
		printf("Lab Grade:\t%d\n", grades[0].getGrade());
		printf("Pass/Fail Exam Grade:\t%d\n", grades[1].getGrade());
		printf("Essay Grade:\t%d\n", grades[2].getGrade());
		printf("Final Exam Grade:\t%d\n", grades[3].getGrade());
	}

};

#endif /* COURSEGRADES_H_ */
