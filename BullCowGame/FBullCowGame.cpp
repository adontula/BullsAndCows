#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { 
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (false) { // if Guess is not an isogram
		return EWordStatus::Not_Isogram;
	}
	else if (false) { // if Guess is not lowercase
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) { // if Guess is the wrong length
		return EWordStatus::Wrong_Length;
	}
	else { // Guess is valid
		return EWordStatus::OK;
	}
}

// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	// increment turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	// loop through all letters in guess
	for (int32 i = 0; i < WordLength; i++) {
		// compare all letters to letters in the hidden word
		for (int32 j = 0; j < WordLength; j++) {
			if (MyHiddenWord[i] == Guess[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	bGameIsWon = BullCowCount.Bulls == WordLength ? true : false;
	// compare letters against the hidden word
	return BullCowCount;
}
