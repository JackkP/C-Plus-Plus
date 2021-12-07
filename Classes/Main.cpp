#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include <vector>

using namespace std;


int main(){
	
	vector<Media*> m;
	
	//start message
	cout << "Welcome to the Media Database!\n========================================" << endl;
	
	char next[30];
	while(true){
		cout << "type help for commands" << endl; //message to prompt commands and give help if needed
		cin.get(next, 30);
		cin.get();
		if(strcmp(next, "help") == 0){ //print help message
			cout << "\n========================================\n\nadd - add a media to the database\nprint - list everything in the database\nsearch - search by name or by title\ndelete - delete a media by title and year\nquit - exit the program\n\n========================================" << endl;
		}
		else if(strcmp(next, "add") == 0){ //add a media
			
		}
		else if(strcmp(next, "print") == 0){ //print all medias
			
		}
		else if(strcmp(next, "search") == 0){ //search for medias by title or year and print matching medias
			while(true){ //get search by title or by year
				cout << "what would you like to search by? (title/year)" << endl;
				cin.get(next, 30);
				cin.get();
				if(strcmp(next, "title") == 0 || strcmp(next, "year") == 0){
					break;
				}
				else cout << "try again" << endl;
			}
			if(strcmp(next, "title") == 0){ //search by title (figure out if value searched for is contained in any title)
				cout << "searching by title" << endl;
			}
			else if(strcmp(next, "year") == 0){ //figure out if this year matches year for every object
				cout << "searching by year" << endl;
				int cmpYear = 0;
				cin >> cmpYear;

				for (ptr = m.begin(); ptr < m.end(); ptr++){ //iterate through m and check every year
					if(m.getYear() == cmpYear;){ //if the year matches
						m.print();
					}
				}
			}
		}
		else if(strcmp(next, "delete") == 0){
			
		}
		else if(strcmp(next, "quit") == 0){ 
			break;
		}
		else{
			cout << "command not recognized, please try again" << endl;
		}

	}

}
