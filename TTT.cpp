#include <iostream>
#include <cstring>

using namespace std;

void clearBoard(char board[3][3]);
void printBoard(char board[3][3]);
bool isValidInput(char input[3], char board[3][3]);
char checkMatchEnd(char board[3][3]);


int main() {

  //define and initialize game board
  char board[3][3];

  //declare winning totals
  int xWins = 0;
  int oWins = 0;

  //outer match loop (always plays again after a game)
  while (true) {

    //shows messages
    cout << "Beginning a new round..." << endl;
    
    //resets for a new match
    bool xTurn = true;
    clearBoard(board);
    printBoard(board);

    //inner game loop, the turn by turn logic
    while (checkMatchEnd(board) == 'F') { 

      //get player input
      //No, I didn't use AI, I just learned shorthand if-else on my own. 
      cout << endl << "It is " << (xTurn ? "X" : "O") << "'s turn." << endl;

      //asks repeatedly until the user enters a valid coordinate
      char input[3];
      do {
	cout << "Enter the coordinate for your move:" << endl;
	cin.get(input, 3);
	cin.get();
      } while (!isValidInput(input, board));

      //plays the move onto the board
      board[int(input[0]) - 97][int(input[1]) - 49] = xTurn ? 'X' : 'O';
      printBoard(board);

      xTurn = !xTurn;
    }

    //game over
    //show result and update totals
    if (checkMatchEnd(board) == 'X') {
      cout << endl << "X wins!" << endl;
      xWins++;
    }
    else if (checkMatchEnd(board) == 'O') {
      cout << endl << "O wins!" << endl;
      oWins++;
    }
    else {
      cout << endl << "Tie." << endl;
    }

    cout << endl << endl;
 
  }
  
  return 0;
}

void clearBoard(char board[3][3]) {
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      board[y][x] = ' ';
    }
  }
}

void printBoard(char board[3][3]) {
  cout << endl << "  1 2 3" << endl;
  cout << "a " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
  cout << "b " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
  cout << "c " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl << endl;
  
}

bool isValidInput(char input[3], char board[3][3]) {
  //checks for invalid input
  if ((input[0] != 'a' && input[0] != 'b' && input[0] != 'c') || (input[1] != '1' && input[1] != '2' && input[1] != '3')) {
    cout << "Please enter a valid input (ex: \"a1\")" << endl;
    return false;
  }

  //checks for occupied spaces
  else if (board[int(input[0]) - 97][int(input[1]) - 49] != ' ') {
    cout << "That spot is already occupied, choose another coordinate." << endl;
    return false;
  }
  
  return true;
}

char checkMatchEnd(char board[3][3]) {
  //checks all win conditions
  if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
    return board[0][0];
  }
  else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
    return board[1][0];
  }
  else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
    return board[2][0];
  }
  else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
    return board[0][0];
  }
  else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[1][2]) {
    return board[0][1];
  }
  else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
    return board[0][2];
  }
  else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  else if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
    return board[2][0];
  }

  //checks for tie
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[y][x] == ' ') {
	return 'F'; //false, the game hasn't ended
      }
    }
  }

  return 'T'; //tie
  
    
}
