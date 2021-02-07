#pragma once
#include <string>
#include "student.h"
using namespace std;

class SecurityStudent : public Student {
	public:
		SecurityStudent(); //empty constructor
		SecurityStudent(string ID, string firstN, string lastN, string eMailAdd, int age, int numDays[], Degree degreeprogram); //full constructor (included Degree type here)

		//virtual methods from Student class are overridden here:
		Degree getDegreeProgram();
		void print();

		//destructor for SecurityStudent:
		~SecurityStudent();
};