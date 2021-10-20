#include <cstring>
#include <iostream>

using namespace std;

/* Jack Porter
 * Period 1 C Plus Plus
 */

//declare board array

// This method gets a char for A, B, or C value from system input and avoids invalid responses
char getABC(char A, char B, char C) {
        char out;

        char input[100];

        cin.get(input, 100);
	cin.get();
	
	//if the input is a single char and that char matches a possible input
        if ((input[0] == A || input[0] == B || input[0] == C)  && input[1] == '\0') out = input[0];
        else {
                cout << "invalid input please try again" << endl;
                cout << "(" << A << "/" << B << "/" << C << ")" << endl;
                out = getABC(A, B, C);
        }
        return out;
}

// This Method Checks if the board has a three in a row of a value that is not a space, then returns that value
char checkWin(char (&board)[3][3]){
	
	char rslt;
        for (int i = 0; i<=2; i++ ) { // check all rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                        rslt = board[i][0];
                        break;
                }
        }

        for (int i = 0; i<=2; i++ ) { // check all columns
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                        rslt = board[0][i];
               		break;
		}
        }
	
	// check one diagonal
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
                rslt = board[0][0];

        }
	
	//check other diagonal
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
                rslt = board[2][0];
        }
	
        return rslt;

}


// Printt the board with a nice layout
int printBoard(char (&board)[3][3]){
	cout << "   1   2   3" << endl;
	cout << "a  " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << " " << endl;
	cout << "  ---+---+---" << endl;
	cout << "b  " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << " " << endl;
	cout << "  ---+---+---" << endl;
	cout << "c  " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " << endl;
	return 0;
}
	
// Check to see if the board is full by looking for spaces
bool boardFull(char (&board)[3][3]) {
	bool full = true;
	for(int i = 0; i<=2; i++) {
		for(int a = 0; a<=2; a++) {
			if (board[i][a] == ' ') {
				full = false;
			}
		}
	}
	return full;
}
	
// This method gets a valid move from a player
void getMove(char (& rslt)[3], char (&board)[3][3]) {
	
	char coords[100];
	
	// until a move is made
	while (true){

		cin.get(coords, 100);
		cin.get();
		
		// if the string input is a valid move...
		if ( 49 <= coords[0] && 51 >= coords[0] && 97 <= coords[1] && 99 >= coords[1] && coords[2] == '\0') {
			if (board[coords[0] - 49][coords[1]- 97] == ' ') {
				strcpy(rslt, coords);
				break;
			}
			else {
				cout << "try again" << endl;
			}
		}
		else {
			cout << "try again" << endl;
		}
	}

	return;
}

void clearBoard(char (&board)[3][3]) { // set all characters in board to 0
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	return;

}


int main() {
	
	char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};

	
	cout << "Welcome to Command Line Tic Tac Toe \n" << endl;
	cout << "New Game" << endl;
	cout << "===================" << endl;
	
	int scoreX = 0;
	int scoreO = 0;
	int draws = 0;
			
	
	//continue playing while in this loop
	while (true) {
		
		clearBoard(board);

		cout << "Player 1 (x) starts" << endl;
		char player[10];
		char scoreXDisp[10];
		char scoreODisp[10];
		char drawsDisp[10];
		
		strcpy(player, "1 (x)");
		strcpy(scoreXDisp, " wins");
		strcpy(scoreODisp, " wins");
		strcpy(drawsDisp, " draws");
		

		while (true) { // single game loop, continue playing while in this loop
			
			cout << "#=#=#=#=#=#=#=#=#=#=#  Player " << player << " type coordinates of move (number first and capital letters eg 3b)" << endl;
			printBoard(board);				
			char move[3];
			getMove(move, board);
			
			// if the current player is x, place an x and then switch the turn
			if (strcmp(player, "1 (x)") == 0) {
				board[move[0] - 49][move[1]- 97] = 'x';
				strcpy(player, "2 (o)");
			}
			
			// if the current player is o, place an o and then switch the turn
			else if (strcmp(player, "2 (o)") == 0) {
				board[move[0]- 49][move[1]- 97] = 'o';
				strcpy(player, "1 (x)");
			}
			
			char lastWin = checkWin(board);
			// if x won
			if (lastWin == 'x') {
				scoreX += 1;
				printBoard(board);
				break;
			}
			// if o won
			else if (lastWin == 'o') {
				scoreO += 1;
				printBoard(board);
				break;
			}
			// if a draw
			if (boardFull(board)) {
				draws += 1;
				printBoard(board);
				break;
			}
		}
		// game over, play again?
		
		if (scoreX == 1) {
			strcpy(scoreXDisp, " win");
		}
		if (scoreO == 1) {
			strcpy(scoreODisp, " win");
		}
		if (draws == 1) {
			strcpy(drawsDisp, " draw");
		}
		
		cout << endl;
		cout << "Player 1 (x): " << scoreX << scoreXDisp << " | Player 2 (o): " << scoreO << scoreODisp << " | Draws: " << draws << drawsDisp << endl;
		cout << "============================================================" << endl;
		cout << "Type n for new game, r to reset scores, or q to quit." << endl;
		char next = getABC('n', 'r', 'q');
		if (next == 'r') {
			scoreX = 0;
			scoreO = 0;
			draws = 0;
		}
		else if(next == 'q') {
			return 0;
		}
	}
	
}
