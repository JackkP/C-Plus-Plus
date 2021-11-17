#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;


int main(){
	
	char* title = new char[50];
	strcpy(title, "test title");
	Media* test = new Media(title, 1995);
	cout << test->getYear() << ", " << test->getTitle();

}
