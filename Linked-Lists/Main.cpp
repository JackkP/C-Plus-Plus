#include <iostream>
#include "Node.h"

using namespace std;

/* Jack Porter, January 2022
 * Linked List colaborative project
 */

void startToFinish(Node* head) {
	cout << head->getStudent()->getID() << ",";
	//bullshit code here
	if (head -> getNext() != NULL){
		startToFinish(head->getNext());
	}
}



int main(){
	
	Student* studentPtr = new Student(12);

	Node* node = new Node(studentPtr); //create a node with a student
	
	cout << "pointer to student 1" << node->getStudent() << ", student1 ID: " << node->getStudent()->getID() << endl;

	studentPtr = new Student(10);

	Node* node2 = new Node(studentPtr); //create a second student node
	node2->setNext(NULL);
	cout << "pointer to student2: " << node2->getStudent() << ", student2 ID " << node2->getStudent()->getID() << endl;

	node->setNext(node2); //link second node to first node
	cout << "next student id: " << node->getNext()->getStudent()->getID() << endl;

	startToFinish(node);

	return 0;
}
