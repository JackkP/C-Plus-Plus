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

bool searchID(Node* head, int ID){ //search for a student that matches this ID (used for avoiding duplicates)
	Node* n = head;
	while(n){ //search with iteration
		if (n->getStudent()->getID() == ID){
			return true;
		}
		n = n->getNext();
	}
	return false;
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
	Node* n = head; //keep track of current node
	while (n){ //search by iteration
		//the id is greater than the last id value
		if (!n->getNext() && n->getStudent()->getID() < s->getID()){
			n->setNext(newNode);
			return;
		}
		//the id is greater than the current id and smaller than the next
		else if (s->getID() > n->getStudent()->getID() && s->getID() < n->getNext()->getStudent()->getID()){
			newNode->setNext(n->getNext());
			n->setNext(newNode);
			return;
		}
		n = n->getNext();
	}
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
	Node* n = head;
	
	//if(deleteByID(head->getNext(), ID)) return true;
	while (n->getNext()){ //search by iteration
		if(n->getNext()->getStudent()->getID() == ID){
			Node* tmp = n->getNext()->getNext();
			delete n->getNext();
			n->setNext(tmp);
			return true;
		}
		n = n->getNext();
	}
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
