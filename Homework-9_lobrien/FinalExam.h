/*
 * FinalExam.h
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#include "Grades.h"

#ifndef FINALEXAM_H_
#define FINALEXAM_H_

class FinalExam : Grades
{
private:
	const int maxScore = 50;
	int score;

public:
	FinalExam() : Grades() { score = 0; }
	void setGrade(int x) { score = x; Grades::setGrade(score/maxScore);}
	int getGrade() { return score; }
	int getMaxScore() { return maxScore; }

};

#endif /* FINALEXAM_H_ */
