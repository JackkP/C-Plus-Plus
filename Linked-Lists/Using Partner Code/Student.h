//Jack Porter, January 2022
//Student header file for Student Lists using Linked Lists project
using namespace std;

class Student{
	public:
		Student(char* f, char* l, float g, int ID); //constructor
		
		char* getFirst();
		char* getLast();
		float getGPA();
		int getID();
		~Student();

	private:
		char* first;
		char* last;
		float gpa;
		int id;

};
