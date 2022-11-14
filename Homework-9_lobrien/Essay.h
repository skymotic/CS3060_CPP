/*
 * Essay.h
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#include "Grades.h"

#ifndef ESSAY_H_
#define ESSAY_H_

class Essay : Grades
{
private:
	const int maxScore = 100;
	int score;

public:
	Essay() : Grades() { score = 0; }
	void setGrade(int x) { score = x; Grades::setGrade(score/maxScore);}
	int getScore() { return score; }
	int getMaxScore() { return maxScore; }

};

#endif /* ESSAY_H_ */
