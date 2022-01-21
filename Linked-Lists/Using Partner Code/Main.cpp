#include <iostream>
#include <cstring>

#include "Node.h"

using namespace std;

/* Jack Porter, January 2022
 * Linked List colaborative project
 */

void printForward(Node* head){ //function to print out students from the head to the end of the list
	if(!head) return;
	Student* s = head->getStudent();
	cout << s->getFirst() << " ";
	cout << s->getLast() << ", ";
	cout << s->getID() << ", GPA: ";
	cout << s->getGPA() << "\n" << endl;
	printForward(head->getNext());
}

bool searchID(Node* head, int ID){ //search for a student that matches this ID (used for avoiding duplicates)
	Node* n = head;
	while(n){
		if (n->getStudent()->getID() == ID){
			return true;
		}
		n = n->getNext();
	}
	return false;
}

void addByID(Node* head, Student* s){ //add a student in the correct place (in the linked list) by ID

}

bool deleteByID(Node* head, int ID){ //delete a student given the ID
	return false;
}

int main(){
	
	Node* head = NULL;
	
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
			//prompt first name
			//prompt last name
			//prompt ID
			int id;
			//prompt GPA
			if (searchID(head, id)) cout << "Can not have duplicate ID's";
			else{
				addByID(head, new Student(id));
				numStud++;
			}
		}
		
		//delete a student
		else if(strcmp(next, "delete") == 0){
			//prompt the student id and then delete

			cout << "Student ID?" << endl;
			int id = 0;
			cin >> id;
			cin.get();
			//if the delete completes remove one student from the ttracker
			if(deleteByID(head, id) == true) numStud --;
			else cout << "that student does not exist" << endl;
		}
		
		//print the list of students
		else if(strcmp(next, "print") == 0){
			printForward(head);
		}
		
		//quit the application
		else if(strcmp(next, "quit") == 0){
			cout << "quitting" << endl;
			break;
		}

	}
	return 0;
}
