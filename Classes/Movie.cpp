#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(char* newTitle, int newYear, char* newDirector, float newDuration, float newRating):Media(newTitle, newYear){
	director = newDirector;
	duration = newDuration;
	rating = newRating;
}

Movie::~Movie(){
	delete[] director;
}

char* Movie::getDirector(){
	return director;
}
float Movie::getDuration(){
	return duration;
}
float Movie::getRating(){
	return rating;
}
