#pragma once
#include <string>
#include "student.h"
using namespace std;

class NetworkStudent : public Student {
	public:
		NetworkStudent();
		NetworkStudent(string ID, string firstN, string lastN, string eMailAdd, int age, int numDays[], Degree degreeprogram);

		//virtual methods from Student class overridden:
		Degree getDegreeProgram();
		void print();

		//destructor for NetworkStudent:
		~NetworkStudent();
};