#include <iostream>;
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent() : Student() {
	//calls constructor from Student class first then add:
	degreeprogram = SECURITY;
}

SecurityStudent::SecurityStudent(string ID, string firstN, string lastN, string eMailAdd, int age, int numDays[], Degree degreeprogram) : Student(ID, firstN, lastN, eMailAdd, age, numDays) {
	degreeprogram = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY;							//overrides virtual method in student.h
}

void SecurityStudent::print() {
	this->Student::print();					   //calls print for Student class
	cout << "\tDegree Program: " <<  "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}