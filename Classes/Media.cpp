#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media(char* newTitle, int newYear){
	Title = newTitle;
	year = newYear;
}

char* Media::getTitle(){
	return Title;
}

int Media::getYear(){
	return year;
}
