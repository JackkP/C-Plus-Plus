//Jack Porter, January 2022
//Student.cpp file for Student Lists using Linked Lists project

#include "Student.h"

using namespace std;

Student::Student(char* f, char* l, int g, int newId){ //constructor with ID
	first = f;
	last = l;
	gpa = g;
	id = newId;
}

char* Student::getFirst(){
	return first;
}

char* Student::getLast(){
	return last;
}

int Student::getGPA(){
	return gpa;
}

int Student::getID(){ //return ID
	return id;
}
