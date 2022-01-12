#ifndef NODE_H //header guard
#define NODE_H
#include "Student.h"

using namespace std;

class Node{
	public:
		Node(Student* student); //constructor

		Node* getNext(); //get next Node pointer
		void setNext(Node*); //set the next pointer to the corresponding node pointer
		
		Student* getStudent(); //get student pointer
		
		~Node(); //destructor

	private:
		Student* stdntPtr; //pointer to student
		Node* Next; //pointer to next node

};

#endif
