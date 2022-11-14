/*
 * PassFailExam.h
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#include "Grades.h"

#ifndef PASSFAILEXAM_H_
#define PASSFAILEXAM_H_

class PassFailExam : Grades
{
private:
	const int maxScore = 10;
	int score;

public:
	PassFailExam() : Grades() { score = 0; }
	void setGrade(int x) { score = x; Grades::setGrade(score/maxScore);}
	int getGrade() { return score; }
	int getMaxScore() { return maxScore; }

};

#endif /* PASSFAILEXAM_H_ */
