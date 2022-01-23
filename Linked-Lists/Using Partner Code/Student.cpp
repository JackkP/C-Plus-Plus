//Jack Porter, January 2022
//Student.cpp file for Student Lists using Linked Lists project

#include "Student.h"

using namespace std;

Student::Student(char* f, char* l, float g, int newId){ //constructor with ID
	first = f;
	last = l;
	gpa = g;
	id = newId;
}

char* Student::getFirst(){ //return first name
	return first;
}

char* Student::getLast(){ //return last name
	return last;
}

float Student::getGPA(){ //return GPA
	return gpa;
}

int Student::getID(){ //return ID
	return id;
}

Student::~Student(){ //destructor
	delete first;
	delete last;
}
