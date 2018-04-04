/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on MasterMind.
*/


#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const; 

	void Reset(); 
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry = 1;
	FString MyHiddenWord;
	bool bGameIsWon = false;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};