#include <iostream>
#include <string>

using namespace std;

int main() {
	constexpr int WORD_LENGTH = 5;

	// introduce the game
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << 
		" letter isogram I'm thinking of?\n\n";

	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess;
	
	// repeat the guess back to them
	cout << "Your guess was " << Guess << endl;

	cout << endl;
	return 0;
}