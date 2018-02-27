#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// entry point for the application
int main() { 
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PlayGame() {
	FBullCowGame BCGame; 

	constexpr int NUM_GUESSES = 5;
	for (int i = 0; i < NUM_GUESSES; i++) {
		std::string Guess = GetGuess();
		// repeat the guess back to them
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
}

void PrintIntro() {
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH <<
		" letter isogram I'm thinking of?\n\n";
}

//get a guess from the player
std::string GetGuess() {
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)?\n";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
