#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

/* Jack Porter, C++, October 28, 2021
 * <--STUDENT LIST-->
 *
 * This program is a rudimentary commandline student database that stores the names, id numbers, and GPA of students.
 * Commands include 'add', 'print', 'delete', and 'quit'.
 * A student struct is created as is a vector of student pointers which independently stores each student
 */

// a student contains:
struct student {
	char first[50];
	char last[50];
	int ID;
	float GPA;

};

//to pint a list of all students
void print(vector<student*>* list){
	// Iterate through vector elements from begin() to end() and print information for each student
	for (vector<student*>::iterator ptr = list->begin(); ptr < list->end(); ptr++)
        	std::cout << (*ptr)->ID << ": " << (*ptr)->last << ", " << (*ptr)->first << ", GPA: " << std::setprecision(2) << std::fixed << (*ptr)->GPA << endl;
      
}

//to remove a student from list by ID
int Delete(vector<student*>* list, int id) {
	//search the vector for an iterator that points to a student with the matching ID
	for (vector<student*>::iterator ptr = list->begin(); ptr < list->end(); ptr++) {
        	if( (*ptr)->ID == id){
			
			//delete the student and then the pointer in the vector
			cout << "Deleted "<< (*ptr)->first << " " << (*ptr)->last << ", ID: " << (*ptr)->ID << endl;
			delete (*ptr);
			list->erase(ptr);
			return 0;
		}
	}
	return 1;
}


int main() {
	
	vector<student*>* list = new vector<student*>;
	
	//number of students in the database
	int numStud = 0;
	
	//UI loop
	while(true) {
		
		//formatting
		cout << "=====================================================" << endl;
		cout << "Student Database: " << numStud << " students" << endl;

		cout << "Type 'add' to add a student\n 'delete' to remove a student\n 'print' to list the students\n 'quit' to quit" << endl;
		
		char next[100];
		cin.get(next, 100);
		cin.get();
		
		cout << "=====================================================" << endl;
		
		//add a student
		if(strcmp(next, "add") == 0){
			char p[50];
			//prompt all 4 pieces of information necessesary for a student
			student* s = new student;
			cout << "First Name?" << endl;
			cin.get(s->first, 50);
			cin.get();
			cout << "Last Name?" << endl;
			cin.get(s->last, 50);
			cin.get();
			cout << "GPA?" << endl;
			cin.get(p, 50);
			cin.get();
			s->GPA = atof(p);
			cout << "ID?" << endl;
			cin.get(p, 50);
			cin.get();
			s->ID = atoi(p);

			//make sure that a student with this ID does not already exist
			bool usable = true;
			for (vector<student*>::iterator ptr = list->begin(); ptr < list->end(); ptr++) {
        			if( (*ptr)->ID == s->ID){
			
					//delete the student and then the pointer in the vector
					cout << "This student already exists " << endl;
					delete (s);
					usable = false;
					break;
				}
			}
			//if no student already exists, add this pointer to the list vector
			if(usable) list->push_back(s); numStud++; cout << "Added " << s->first << " " << s->last << ", ID: " << s->ID << endl;

		}
		//delete a student

		else if(strcmp(next, "delete") == 0){
			
			//prompt the student id and then delete

			cout << "Student ID?" << endl;
			int id = 0;
			cin >> id;
			cin.get();
			//if the delete completes remove one student from the ttracker
			if(Delete(list, id) == 0) numStud --;
			else cout << "that student does not exist" << endl;
		}
		
		
		//print the list of students
		else if(strcmp(next, "print") == 0){
			print(list);
		}
		
		//quit the application
		else if(strcmp(next, "quit") == 0){
			cout << "quitting" << endl;
			break;
		}

	}
}
