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
void Movie::print(){ // print function
	cout << "Movie - '" << title << "', " << year << ", Director: " << director << ", Duration: " << duration << " mins, Rating: " << rating << endl;
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
