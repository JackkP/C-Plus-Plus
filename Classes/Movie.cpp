#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;
//constructor with superclass constructor
Movie::Movie(char* newTitle, int newYear, char* newDirector, float newDuration, float newRating):Media(newTitle, newYear){
	director = newDirector;
	duration = newDuration;
	rating = newRating;
}

//destuructor
Movie::~Movie(){
	//delete objects that are stored in Movie class as pointers
	delete[] director;
}

//functions for returning values of stuff
char* Movie::getDirector(){
	return director;
}
float Movie::getDuration(){
	return duration;
}
float Movie::getRating(){
	return rating;
}
