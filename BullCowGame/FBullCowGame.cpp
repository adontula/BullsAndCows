#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const {
	return false;
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const {
	return EWordStatus::OK; // TODO make actual error checking
}

// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	
	int32 HiddenWordLength = MyHiddenWord.length();
	// loop through all letters in guess
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare all letters to letters in the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
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
		// compare letters against the hidden word
	return BullCowCount;
}
