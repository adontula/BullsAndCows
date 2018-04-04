#pragma once

#include "FBullCowGame.h"
#include <map>

// to make syntax Unreal friendly
#define TMap std::map

FBullCowGame::FBullCowGame() { 
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = "plane"; // this MUST be an isogram

	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (!IsIsogram(Guess)) { // if Guess is not an isogram
		return EWordStatus::Not_Isogram; 
	}
	else if (!IsLowerCase(Guess)) { // if Guess is not lowercase 
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

bool FBullCowGame::IsIsogram(FString Word) const {
	// treat 0 or 1 letter words as isograms
	if (Word.length() <= 1) return true;
	// can use unordered set or TSet (Unreal); using map for practice
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const {
	for (auto Letter : Word) {
		if (!islower(Letter)) return false;
	}
	return true;
}
