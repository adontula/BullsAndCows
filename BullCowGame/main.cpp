#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// entry point for the application
int main() { 
	PrintIntro();
	PlayGame();
	return 0;
}

void PlayGame() {
	constexpr int NUM_GUESSES = 5;
	for (int i = 0; i < NUM_GUESSES; i++) {
		string Guess = GetGuess();
		// repeat the guess back to them
		cout << "Your guess was " << Guess << endl;
		cout << endl;
	}
}

void PrintIntro() {
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH <<
		" letter isogram I'm thinking of?\n\n";
}

//get a guess from the player
string GetGuess() {
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}