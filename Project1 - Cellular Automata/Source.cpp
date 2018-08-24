//HENRY WONG
// Project 1 - Cellular Automata
#include <iostream>
#include "Board.h"
#include <string>
using namespace std;

int main() {
	srand(time(NULL)); //for generating random values everytime the user starts program.
	string exit;
	int n = 0;

	cout << "Welcome Cellular Automata!" << endl;
	cout << "___________________________" << endl;
	Board A1;
	//set initial board, along with randomized starting points for humans, vampires, and werewolfs.
	A1.placeBoard();
	A1.setHuman();
	A1.setWere();
	A1.setVamp();
	//displays board.
	A1.showBoard();
	cout << endl << endl;
	//displays humans left.
	A1.checkHuman();

	cout << "__________________________" << endl;
	cout << "Generations passed : " <<  n << endl;
	cout << endl << "Enter how many generations you would like to pass.  Enter 0 to quit. " << endl;
	//lets user input how much generations he wants to pass.
	cin >> n;
	cout << endl;
	while (n > 0) // if user inputs a value greater than 0, the game will continue!
	{
		for (int i = 0; i < n; i++) {
			cout << "___________________________" << endl;
			//update functions for humans, werewolfs, vampires.
			A1.updateHV();
			A1.updateHW();
			A1.updatesH();
			A1.showBoard(); //display board after changes
			cout << endl << endl;
			A1.checkHuman();
			cout << "__________________________" << endl;
			cout << "Generations passed : " << i + 1 << endl;
			cout << endl << "Enter how many generations you would like to pass.    Enter 0 to quit. " << endl;
			cin >> n;
		}

	}
	system("PAUSE");

}
