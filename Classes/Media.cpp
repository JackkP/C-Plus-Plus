#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;
//constructor including variables shared across all media subclasses
Media::Media(char* newTitle, int newYear){
	title = newTitle;
	year = newYear;
}

char* Media::getTitle(){
	return title;
}

int Media::getYear(){
	return year;
}
Media::~Media(){ //destructor deletes object stored as pointer
	delete[] title;
}
