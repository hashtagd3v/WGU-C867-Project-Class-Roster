#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() : Student() {
	//calls constructor for Student class first then add:
	degreeprogram = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string ID, string firstN, string lastN, string eMailAdd, int age, int numDays[], Degree degreeprogram) : Student(ID, firstN, lastN, eMailAdd, age, numDays) {
	degreeprogram = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << "\tDegree Program: " << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}