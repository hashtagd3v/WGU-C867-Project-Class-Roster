#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

Roster::Roster() { //default constructor
	this->max = 0;
	this->lastIndex = -1; //index is set to -1; meaning = empty array
	this->classRosterArray = nullptr;
}

Roster::Roster(int max) { //full constructor; sets max capacity for roster
	this->max = max;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[max]; //students is a pointer pointing at max pointers to Student
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

//********** START PARSING AND ADDING HERE *********************************************************************************************

void Roster::parseString_Add(string row) {
	if (lastIndex < max) {
		lastIndex++;
		Degree degreeprogram;		//FIX ME degreeprogram
								//Check which degree first:
		if (row.back() == 'Y') {
			degreeprogram = SECURITY;
		}
		else if (row.back() == 'K') {
			degreeprogram = NETWORKING;
		}
		else if (row.back() == 'E') {
			degreeprogram = SOFTWARE;
		}
		else {
			cerr << "Invalid Degree Program! Exiting Program." << endl;
			exit(-1);
		}
		//parse through each string by row in the studentData array; using comma as delimiter:
		//Then extract each substr and store in temporary variables

		//Get student ID:
		int firstS = row.find(",");
		string ID = row.substr(0, firstS);  //student ID string

		//extract first name:
		int secondS = firstS + 1;
		firstS = row.find(",", secondS);
		string firstN = row.substr(secondS, firstS - secondS); //first name string

		//extract last name:
		secondS = firstS + 1;
		firstS = row.find(",", secondS);
		string lastN = row.substr(secondS, firstS - secondS);  //last name string

		//extract e-mail address:
		secondS = firstS + 1;
		firstS = row.find(",", secondS);
		string eMailAdd = row.substr(secondS, firstS - secondS);  //email string

		//extract age:
		secondS = firstS + 1;
		firstS = row.find(",", secondS);
		int age = stoi(row.substr(secondS, firstS - secondS));  //age string (also converted to int************)

		//extract each number of days per course
		//EACH DAYS ARE CONVERTED TO INTEGERS here (used stoi):
		secondS = firstS + 1;
		firstS = row.find(",", secondS);
		int numDays1 = stoi(row.substr(secondS, firstS - secondS)); //numDays1 string

		secondS = firstS + 1;
		firstS = row.find(",", secondS);
		int numDays2 = stoi(row.substr(secondS, firstS - secondS)); //numDays 2 string

		secondS = firstS + 1;
		firstS = row.find(",", secondS);
		int numDays3 = stoi(row.substr(secondS, firstS - secondS)); //numDays 3 string

		//Add all temporary variable values here. Add method will create degree types:
		add(ID, firstN, lastN, eMailAdd, age, numDays1, numDays2, numDays3, degreeprogram);

	}
	else {
		cerr << "ERROR! STUDENTS HAS EXCEEDED MAXIMUM FOR ROSTER.\nEXITING PROGRAM NOW.\n";
		exit(-1);
	}
}

//********** END OF PARSING HERE *********************************************************************************************

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram) {
	int numDays[Student::numDaysArraySize];
	numDays[0] = daysInCourse1;
	numDays[1] = daysInCourse2;
	numDays[2] = daysInCourse3;
	
	if (degreeprogram == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDays, degreeprogram);
	}
	else if (degreeprogram == NETWORKING) {
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDays, degreeprogram);
	}
	else if (degreeprogram == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDays, degreeprogram);
	}
	else {
		cerr << "Error in adding student. Exiting program now." << endl;
		exit(-1);
	}
}

void Roster::print_All() {							//calls print method for each student in the array
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray[i])->print();
	}
}

//Removes/Erases student from the roster/list:
void Roster::remove(string studentID) {
	bool positive = false;
	for (int i = 0; i <= lastIndex; i++) {
		if ((this->classRosterArray[i])->getID() == studentID) {	//Student ID found
			positive = true;
			delete this->classRosterArray[i];
			//Rearrange by pointing pointer of last student in roster to fill the gap of deleted student:
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;						//decremented lastIndex to fit correct number of students
		}
	}
	return;
}

void Roster::printDaysInCourse(string studentID) {
	bool positive = false;
	for (int i = 0; i <= lastIndex; i++) {
		if ((this->classRosterArray[i])->getID() == studentID) {
			positive = true;
			int* tempPtr = classRosterArray[i]->getNumDays();
			cout << "Average Days in Course: " << studentID << " is " << (tempPtr[0] + tempPtr[1] + tempPtr[2]) / 3.0 << endl;		//divided int by double to get average
		}
	}
	if (!positive) {
		cout << "Student not found!" << endl;
	}
}


void Roster::printInvalidEmails() {		//checks invalid e-mail addresses: checks if @ and '.' are present; checks for white spaces in string
	cout << "Here are students with invalid e-mail addresses: " << endl;
	bool invalid = false;
	int foundCounter = 0;						//Keeps track of # of invalid e-mails found
	for (int i = 0; i <= lastIndex; i++) {
		invalid = false;
		string p = classRosterArray[i]->getEMail();
		char a = ' ';
		char b = '@';
		char c = '.';
		size_t found = p.find(a);
		if (found != string::npos) {			//if space is found																
			invalid = true;
			cout << "Student ID " << classRosterArray[i]->getID() << ": " << p << endl;
			foundCounter++;
		}
		found = p.find(b);
		if (found == string::npos && !invalid) { //if @ is NOT found
			invalid = true;
			cout << "Student ID " << classRosterArray[i]->getID() << ": " << p << endl;
			foundCounter++;
		}
		found = p.find(c);
		if (found == string::npos && !invalid) { //if . is NOT found
			invalid = true;
			cout << "Student ID " << classRosterArray[i]->getID() << ": " << p << endl;
			foundCounter++;
		}
	}
	if (foundCounter == 0) {				//If no invalid e-mail found print NONE.
		cout << "NONE FOUND." << endl;
	}
}

void Roster::printByDegreeProgram(Degree degreeprogram) {
	cout << "Students by Degree Program: " << degreeType[degreeprogram] << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if ((this->classRosterArray[i])->getDegreeProgram() == degreeprogram) {
			this->classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];  //deletes each student
	}
	delete classRosterArray; //deletes allocated pointers to student
}

//***********************START OF MAIN() *********************************************************************************

int main() {
	int numStudents = 5;		//5 long strings with comma as delimiter

	const string studentData[5] =
	{	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jay,Michalek,jalfant@wgu.edu,29,59,28,62,SOFTWARE" };

	//#1 Print out to screen course title, name, etc.:
	cout << "Scripting and Programming Applications - C867: " << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: #000836599" << endl;
	cout << "Name: Jay Michalek" << endl;

	//#2 Create instance of Roster class: classRoster

	Roster* classRoster = new Roster(numStudents);			

	//#3 Add each student to classRoster:

	cout << "Parsing string data and adding students:\t";
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseString_Add(studentData[i]);					//Parse string array, add as student to roster
	}
	cout << "Done." << endl;

	//#4 Converting pseudo code per requirement:

	cout << "Displaying student data list:" << endl;
	classRoster->print_All();											//Prints all students in roster


	classRoster->printInvalidEmails();									//Prints Invalid Email Adds in roster (loops thru array)
	
	cout << "Displaying Average Number of Days in Course: " << endl;
	for (int i = 0; i < numStudents; i++) {								//Prints Avg Days In Course
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->getID());	
	}
	
	classRoster->printByDegreeProgram(SOFTWARE);						//Print by Degree: Software students only

	cout << "Removing student ID A3:" << endl;							//Remove A3 first time

	classRoster->remove("A3");
	classRoster->print_All();

	cout << "Removing student ID A3:" << endl;							//Remove A3 second time

	bool found = false;
	for (int i = 0; i < numStudents; i++) {
		bool found = false;
		string str = classRoster->getStudentAt(i)->getID();
		if (str == "A3") {
			classRoster->remove("A3");
			found = true;
		}
	}
	if (!found) {
		cout << "Student not found!";
	}

	//#5 Destructor is automatically called.


	return 0;
}
