#include <iostream>
#include <cstring>
#include <iomanip>

#include "Node.h"

using namespace std;

/* Jack Porter, January 2022, C++ - Jason Galbraith
 * Linked List colaborative project
 */

void printForward(Node* n){ //function to print out students from the head to the end of the list
	if(!n) return;
	Student* s = n->getStudent();
	cout << s->getFirst() << " ";
	cout << s->getLast() << ", ";
	cout << s->getID() << ", GPA: ";
	cout << std::setprecision(2) << std::fixed << s->getGPA() << endl; //print gpa with 2 decimal places
	printForward(n->getNext()); //use recursion to print next student
}

float gpaSum(Node* n, float total){ //recursive function to return the summ of all student GPAs
	if(!n) return total;
	return gpaSum(n->getNext(), total+n->getStudent()->getGPA());
}

bool searchID(Node* n, int ID){ //recursively search for a student that matches this ID (used for avoiding duplicates)
	if(!n) return false;
	if (n->getStudent()->getID() == ID){
		return true;
	}
	return searchID(n->getNext(), ID);
}
void insertAfter(Node* n, Node* a){ //recursively insert a somewhere after node n
	//if n is the end of the list insert a
	if(!n->getNext()){
		n->setNext(a);
		return;
	}
	//if the node after n is greater than A insert a after a
	if(n->getNext()->getStudent()->getID() > a->getStudent()->getID()){ 	
		a->setNext(n->getNext());
		n->setNext(a);
		return;
	}
	else insertAfter(n->getNext(), a);
}

void addByID(Node*& head, Student* s){ //add a student in the correct place (in the linked list) by ID	
	Node* newNode = new Node(s); //create a new node
	newNode->setNext(NULL); //set the node to default to null next pointer
	if (!head) { head = newNode; return; } //if the head is a null pointer insert the student

	//if the new student has a smaller id than the head student insert it
	if (s->getID() < head->getStudent()->getID()){
		newNode->setNext(head); //set the new node to point to the first node
		head = newNode; //set the head to the new node
		return;
	}
	//if the student has a greater id than the head student
	insertAfter(head, newNode);
}

bool removeAfter(Node* n, int ID){ //recursively search for student to remove
	if (!n->getNext()) return false; //if this is the end of the list return false
	if (n->getNext()->getStudent()->getID() == ID){ //if the next node is the student remove it
		Node* tmp = n->getNext()->getNext();
		delete n->getNext();
		n->setNext(tmp);
		return true;
	}
	return removeAfter(n->getNext(), ID); //if there is a student it is somewhere after n->getNext()
}

bool deleteByID(Node*& head, int ID){ //delete a student given the ID
	//if the head is a null pointer no student can be deleted
	if(!head) return false;
	
	//if the head points to student <ID> 
	else if(head->getStudent()->getID() == ID){
		Node* tmp = head->getNext();
		delete head;
		head = tmp;
		return true;
	}
	return removeAfter(head, ID); //if there is a student, it is somewhere after the head
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

		cout << "Type 'add' to add a student\n 'delete' to remove a student\n 'print' to list the students\n 'average' to print the average GPA\n 'quit' to quit" << endl;
		
		char next[100];
		cin.get(next, 100);
		cin.get();
		
		cout << "=====================================================" << endl;
		
		//add a student
		if(strcmp(next, "add") == 0){
			
			char p[50];
			//prompt first name
			char* first = new char[50];
			cout << "First Name?" << endl;
			cin.get(first, 50);
			cin.get();

			//prompt last name
			char* last = new char[50];
			cout << "Last Name?" << endl;
			cin.get(last, 50);
			cin.get();
			
			//prompt gpa
			float gpa;
			cout << "GPA?" << endl;
			cin.get(p, 50);
			cin.get();
			gpa = atof(p);
			
			//prompt ID
			int id;
			cout << "ID?" << endl;
			cin.get(p, 50);
			cin.get();
			id = atoi(p);
			
			if (searchID(head, id)) cout << "Can not have duplicate ID's" << endl;
			else{
				addByID(head, new Student(first, last, gpa, id));
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
			//if the delete completes remove one student from the tracker
			if(deleteByID(head, id) == true) numStud --;
			else cout << "that student does not exist" << endl;
		}
		
		//print the list of students
		else if(strcmp(next, "print") == 0){
			printForward(head);
		}
		
		//print the average gpa
		else if(strcmp(next, "average") == 0){
			if(numStud != 0){
				cout << "Average GPA: " << std::setprecision(2) << std::fixed << (gpaSum(head, 0)/numStud) << endl;
			}
			else cout << "No students to take the average of" << endl;
		}
		//quit the application
		else if(strcmp(next, "quit") == 0){
			cout << "quitting" << endl;
			break;
		}

	}
	return 0;
}
