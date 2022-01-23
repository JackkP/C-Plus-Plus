#include "Student.h"

using namespace std;

Student::Student(int newId){ //constructor with ID
	id = newId;
}

int Student::getID(){ //return ID
	return id;
}
