//Nick Peterson, shared to Jack Porter January 2022
//Node.h file for Student Lists using Linked Lists project

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;



class Node {
 public:
  Node(Student*);
  ~Node();
  void setNext(Node* newnext);
  Node* getNext();
  Student* getStudent();
 private:
  Node* next;
  Student* student;
  
};
#endif
