#ifndef NODE_H
#define NODE_H



using namespace std;

class Node{
	public:
		Node(int* student); //constructor

		Node* getNext(); //get next Node pointer
		void setNext(Node*); //set the next pointer to the corresponding node pointer
		
		int* getStudent(); //get student pointer
		
		~Node(); //destructor

	private:
		int* Student;
		Node* Next;

};

#endif
