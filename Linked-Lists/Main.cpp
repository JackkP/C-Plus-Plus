#include <iostream>
#include "Node.h"

using namespace std;

int main(){
	
	int i = 12;
	int* ptr = & i;

	Node* node = new Node(ptr);
	
	cout << node->getStudent() << ", " << *node->getStudent() << endl;

	int j = 14;
	ptr = & j;

	Node* node2 = new Node(ptr);
	cout << node2->getStudent() << ", " << *node2->getStudent() << endl;

	node->setNext(node2);
	cout << *node->getNext()->getStudent() << endl;


	return 0;
}
