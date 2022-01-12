#include "Node.h"

using namespace std;

Node::Node(Student* newStudent){ //constructor
	stdntPtr = newStudent;
}

Node* Node::getNext(){ //return pointer to next node
	return Next;
}

void Node::setNext(Node* newNext){ //set a pointer to the next node
	Next = newNext;
}

Student* Node::getStudent(){ //get student pointer
	return stdntPtr;
}

Node::~Node(){ //destructor
	delete stdntPtr;
}
