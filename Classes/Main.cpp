#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"

using namespace std;


int main(){
	
	char* title = new char[50];
	strcpy(title, "test title");
	char* director = new char[50];
	strcpy(director, "test director");
	Movie* test = new Movie(title, 1995, director, 2.2, 6.75);
	cout << test->getYear() << ", " << test->getTitle();

}
