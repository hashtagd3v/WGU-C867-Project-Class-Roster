#include <iostream>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() : Student() {
	//calls constructor from Student class first then add:
	degreeprogram = NETWORKING;
}

NetworkStudent::NetworkStudent(string ID, string firstN, string lastN, string eMailAdd, int age, int numDays[], Degree degreeprogram) : Student (ID, firstN, lastN, eMailAdd, age, numDays) {
	degreeprogram = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORKING;
}

void NetworkStudent::print() {
	this->Student::print();
	cout << "\tDegree Program: " << "NETWORKING" << endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}