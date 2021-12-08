#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "Videogame.h"
#include <vector>

using namespace std;

/* Jack Porter, Period 1 C++, December 6th 2021, "classes"
 * 
 * This is a database program to store types of media
 * Three types of media can be stored: Music, Movies, and Videogames
 * Functionality includes listing, adding and removing, and searching all stored objects.
 */ 


//This function works by looking through every character until the first characters match, then seeing if the following characters in the key match.
bool strContains(char* string, char* key){ //function for search function to check if a string contains another string (key)
	
	if(strlen(key) > strlen(string)) return false; //sanity check - if the key is longer than the string then impossible
	
	for(int i = 0; string[i] != '\0'; i++){ //for every character in string		
		if(toupper(string[i]) == toupper(key[0])){ //check if it matches the first character of the key
			for(int j = 0; j < strlen(key); j++){ //check if the following characters match for string and key
				if(toupper(string[i+j]) != toupper(key[j])) break; //if there is no match, break the check and return to the next character in string
				if(j == strlen(key)-1) return true; //if all characters match, return true
			}
		}
	}
	return false;


}

int main(){
	
	vector<Media*> m;
	
	//start message
	cout << "Welcome to the Media Database!" << endl;
	
	int numMed = 0;
	char next[50];
	

	while(true){
		cout << "========================================\n " << numMed << " things stored - type help for commands\n========================================" << endl; //message to print number of objects stored and prompt commands and give help if needed
		cin.get(next, 50); //get next command
		cin.get();


		if(strcmp(next, "help") == 0){ //print help message
			cout << "========================================\n\nadd - add a media to the database\nprint - list everything in the database\nsearch - search by name or by title\ndelete - delete a media by title and year\nquit - exit the program\n" << endl;
		}


		else if(strcmp(next, "add") == 0){ //add a media
			while(true){ //get media type to add
				cout << "what type of media would you like to add? (videogame/music/movie)" << endl; //prompt
				cin.get(next, 50); //next command
				cin.get();
				if(strcmp(next, "music") == 0 || strcmp(next, "videogame") == 0 || strcmp(next, "movie") == 0){ //if its a valid type then contiune
					break;
				}
				else cout << "try again" << endl;
			}
			//get data necessesary for new object
			
			//these two are shared
			char* title = new char[50]; //get title
			cout << "Title? ";
			cin.get(title, 50);
			cin.get();
			
			int year = 0; //get year (don't care about handling non integer values, we'll just let it break)
			cout << "Year? ";
			cin >> year;
			cin.get();

			//Music
			if(strcmp(next, "music") == 0){

				float duration = 0; // get duration
				cout << "Duration? (minutes) ";
				cin >> duration;
				cin.get();

				char* artist = new char[50]; //get artist
				cout << "Artist? ";
				cin.get(artist, 50);
				cin.get();

				char* publisher = new char[50]; //get artist
				cout << "Publisher? ";
				cin.get(publisher, 50);
				cin.get();

				Music* ptr = new Music(title, year, duration, artist, publisher); //create new music pointer
				m.push_back(ptr); //add pointer to vector
			}

			//Movie
			else if(strcmp(next, "movie") == 0){
				
				char* director = new char[50]; // get dirctor
				cout << "Director? ";
				cin.get(director, 50);
				cin.get();

				float duration = 0; //get duration
				cout << "Duration? (minutes) ";
				cin >> duration;
				cin.get();

				float rating = 0; //get rating
				cout << "Rating? ";
				cin >> rating;
				cin.get();

				Movie* ptr = new Movie(title, year, director, duration, rating); //create new movie pointer
				m.push_back(ptr); //add pointer to vector

			}

			//Videogame
			else if(strcmp(next, "videogame") == 0){
				
				char* publisher = new char[50]; //get title
				cout << "Publisher? ";
				cin.get(publisher, 50);
				cin.get();

				float rating = 0; //get rating
				cout << "Rating? ";
				cin >> rating;
				cin.get();

				Videogame* ptr = new Videogame(title, year, publisher, rating); //create new videogame pointer
				m.push_back(ptr); //add pointer to vector

			}
			
			numMed++; //add one to the number of stored things
		}


		else if(strcmp(next, "print") == 0){ //print all medias
			for (vector<Media*>::iterator ptr = m.begin(); ptr < m.end(); ptr++){ //iterate through m
				(*ptr)->print();
			}
		}

		//search and delete
		else if(strcmp(next, "search") == 0 || strcmp(next, "delete") == 0){ //search for medias by title or year (for both search and delete)
			
			bool del = false;
			if(strcmp(next, "delete") == 0) del = true;
			while(true){ //get search by title or by year
				cout << "what would you like to search by? (title/year)" << endl;
				cin.get(next, 50);
				cin.get();
				if(strcmp(next, "title") == 0 || strcmp(next, "year") == 0){
					break;
				}
				else cout << "try again" << endl;
			}

			
			if(strcmp(next, "title") == 0){ //search by title (figure out if value searched for is contained in any title)
				cout << "Keywords? "; //get keywords to search for
				cin.get(next, 50);
				cin.get();
				
				cout << "\nSearch Results:" << endl;
				
				for(vector<Media*>::iterator ptr = m.begin(); ptr < m.end(); ptr++){ //check every object
					
					if(strContains((*ptr)->getTitle(), next)) (*ptr)->print(); //if the title contains the keyword print it

				}
				if(del){ //if these objects are being deleted
					
					char* confirm = new char[50]; //delete confirmation
					
					while(true){ //get yes or no confirmation
						cout << "are you sure you want to delete? (yes/no))" << endl;
						
						cin.get(confirm, 50);
						cin.get();
						if(strcmp(confirm, "yes") == 0 || strcmp(confirm, "no") == 0){
							break;
						}
						else cout << "try again" << endl;
					}
					int numdeleted = 0;
					bool done = false; //do until all objects are deleted
					while(!done){
						done = true; //set to done
						for(vector<Media*>::iterator ptr = m.begin(); ptr < m.end(); ptr++){ //check every object			
							if(strContains((*ptr)->getTitle(), next)) { //if the year matches
								(*ptr) -> ~Media(); //delete object
								m.erase(ptr); //erase from vector
								numdeleted++; //count the number of objects to delete
								done = false; //if there is one in there, not done
								break;
							}
						}
					}
						
					cout << "deleted " << numdeleted << " objects" << endl;
					numMed -= numdeleted; //update the number of objects		
				}
			}
			

			else if(strcmp(next, "year") == 0){ //figure out if this year matches year for every object
				cout << "Year? "; //get year to search by
				int cmpYear = 0;
				cin >> cmpYear;
				cin.get();

				cout << "\nSearch Results:" << endl;

				for (vector<Media*>::iterator ptr = m.begin(); ptr < m.end(); ptr++){ //iterate through m and check every year
					if((*ptr)->getYear() == cmpYear){ //if the year matches
						(*ptr)->print(); //print
					}
				}

				if(del){ //if these objects are being deleted
					
					while(true){ //get yes or no confirmation
						cout << "are you sure you want to delete? (yes/no))" << endl;
						cin.get(next, 50);
						cin.get();
						if(strcmp(next, "yes") == 0 || strcmp(next, "no") == 0){ //if valid, continue
							break;
						}
						else cout << "try again" << endl;
					}
					if(strcmp(next, "yes") == 0){ //if delete confirmed then perform search again (yes, its inefficient)
						int numdeleted = 0;
						bool done = false; //to delete all objects in vector
						while(!done){
							done = true; //set to done
							for(vector<Media*>::iterator ptr = m.begin(); ptr < m.end(); ptr++){ //check every object			
								if((*ptr)->getYear() == cmpYear) { //if the year matches
								
									(*ptr) -> ~Media(); //delete object
									m.erase(ptr); //erase from vector
									numdeleted++; //count the number of objects to delete
									done = false; //if there is one in there, not done
									break;
								}
							}
						}
						cout << "deleted " << numdeleted << " objects" << endl;
						numMed -= numdeleted; //update the number of objects
					}
				}
			}
		}


		else if(strcmp(next, "quit") == 0){ 
			break;
		}


		else{
			cout << "command not recognized, please try again" << endl;
		}
	}

	return 0;

}
