#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(char* newTitle, int newYear, char* newDirector, float newDuration, float newRating):Media(newTitle, newYear){
	Director = newDirector;
	duration = newDuration;
	rating = newRating;
}

char* Movie::getDirector(){
	return Director;
}
float Movie::getDuration(){
	return duration;
}
float Movie::getRating(){
	return rating;
}
