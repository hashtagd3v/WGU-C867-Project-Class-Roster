#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster {
	public:
		Roster();
		Roster(int max);

		Student* getStudentAt(int index);
		void parseString_Add(string row); //method to parse string and add degreetype at the end, create Student obj & add to roster
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram); //numDays array values are passed one by one
		void print_All(); //prints all Student list
		void remove(string studentID);		
		void printDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(Degree degreeprogram);
		~Roster();

	private:
		int lastIndex;			//keeps track of last index of student
		int max;				//maximum size of roster
		Student** classRosterArray;		//students is an array of pointers to pointers of students (pointer to pointer)
};