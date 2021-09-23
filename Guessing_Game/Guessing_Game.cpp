#include <iostream>
#include <ctime> 
#include <cstring>

/* Jack Porter, 9/15/2021
 *
 * Command Line Guessing Game
 *
 * This program randomly generates a number between 0 and 100 (inclusive) 
 * and has the player guess what the number was while giving 'too low' or
 * 'too high' feedback.
 */

using namespace std;

int main(){
	
	cout << "Welcome to guessing game!\nGuess a number! Your goal is to pinpoint the random number between 0 and 100!" << endl;
	
	while(true) { //game loop
		
		//seed the RNG and set the random number
		srand(time(NULL)); 
		int number = rand()%101;
		
		//reset random number and prompt
		int guesses = 0;
		cout << "First guess:\n";
	
		int guess = 0;
		
		//use a string for input so non integer inputs can be handled and not break
		char strIn[100];
		
		//guess loop
        	while(true) {
			guesses++;
			
			//until a valid number is guessed
			while(true){
				cin >> strIn;

				try {
					guess = stoi(strIn);
					break;
				}
				catch(std::invalid_argument) {cout << "please enter a number\n";}
			}
			
			//correct guess
                	if(guess == number) {break;}
			
			else if(guess < number) {cout << "Too low, ";}
			else {cout << "Too high, ";}
			cout << "guess again!\n";
        
		}
		cout << "Correct! it took you " << guesses << " guesses!\n\nPlay again? (y/n)" << endl;
		
		//again, use a string to handle other inputs
		char next[100];

		while(true) {//untill a valid input is recieved
			cin >> next;
			if(next == "y" || next == "n") {break;}
			cout << "'" << next << "'" << " is not 'y' or 'n'. Please enter 'y' or 'n'" << endl;
		}

		if(next == "n") {break;}

	}
        return 0;
}
