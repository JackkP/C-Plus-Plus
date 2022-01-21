//Jack Porter, January 2022
//Student header file for Student Lists using Linked Lists project
using namespace std;

class Student{
	public:
		Student(int ID); //constructor
		
		char* getFirst();
		char* getLast();
		int getGPA();
		int getID(); //get id number

	private:
		char* first;
		char* last;
		int gpa;
		int id;

};
