#pragma once
#include <string>
#include "student.h"
using namespace std;

class SoftwareStudent : public Student {
	public:
		SoftwareStudent();
		SoftwareStudent(string ID, string firstN, string lastN, string eMailAdd, int age, int numDays[], Degree degreeprogram);

		//virtual methods from Student class overriden:
		Degree getDegreeProgram();
		void print();

		//destructor for SoftwareStudent:
		~SoftwareStudent();
};