/* This is the console executable that makes use of the BullCow class. 
This acts as a view in a MVC pattern, and is responsible for all user
interaction. For game logic, see the FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point for the application
int main() { 
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PlayGame() {
	BCGame.Reset();
	BCGame.GetMaxTries();

	constexpr int32 NUM_GUESSES = 5;
	// loop while turn number not at NUM_GUESSES valid guesses
	// TODO change from for to while once done validating tries
	for (int32 i = 0; i < NUM_GUESSES; i++) {
		FText Guess = GetGuess(); // TODO make loop checking for valid guesses
		
		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;

		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO add a game summary
}

void PrintIntro() {
	// introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() <<
		" letter isogram I'm thinking of?\n\n";
}

//get a guess from the player
FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << " Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)?\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
