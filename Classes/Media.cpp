#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

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
Media::~Media(){
	delete[] title;
}
