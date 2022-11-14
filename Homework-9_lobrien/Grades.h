/*
 * Grades.h
 *
 *  Created on: Oct 30, 2022
 *      Author: lobr2
 */

#ifndef GRADES_H_
#define GRADES_H_

class Grades
{
private:
	//Grade in percentage
	double grade;

public:
	Grades() { grade = 0; }
	void setGrade(double x) { grade = x; }
	double getGrade() { return grade; }
	double getPercentage() { return grade; }
};

#endif /* GRADES_H_ */
