/*
 * GradedActivity.h
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#include "Grades.h"

#ifndef GRADEDACTIVITY_H_
#define GRADEDACTIVITY_H_

class GradedActivity : Grades
{
private:
	const int maxScore = 100;
	int score;

public:
	GradedActivity() : Grades() { score = 0; }
	void setGrade(int x) { score = x; Grades::setGrade(score/maxScore);}
	int getGrade() { return score; }
	int getMaxScore() { return maxScore; }
};


#endif /* GRADEDACTIVITY_H_ */
