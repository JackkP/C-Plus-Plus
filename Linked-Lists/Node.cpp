#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node(int* newStudent){
	Student = newStudent;
}

Node* Node::getNext(){
	return Next;
}

void Node::setNext(Node* newNext){
	Next = newNext;
}

int* Node::getStudent(){
	return Student;
}

Node::~Node(){
	delete Student;
}
