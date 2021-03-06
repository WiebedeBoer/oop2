// 7oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//The program hangman.cpp implements the hangman game. The player has to guess the word to win the game by suggesting letters.

//Include a function to get the player’s guess 
//and another function to determine whether the player’s guess is in the secret word.

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
//const string THE_WORD;

int main()
{
	// set-up
	const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

	vector<string> words;  // collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];            // word to guess
	int wrong = 0;                               // number of incorrect guesses
	string soFar(THE_WORD.size(), '-');          // word guessed so far
	string used = "";                            // letters already guessed
	char wordguess ='?';

	cout << "Welcome to Hangman.  Good luck!\n";

	// main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;
		cout << "\n Press ? and enter and then enter the word in uppercase and enter to guess the entire word is.\n";

		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); //make uppercase since secret word in uppercase
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);

		}

		if (guess != '?') {
			used += guess;
		}
		
		void getTheGuess(const string THE_WORD, char guess, int wrong, string soFar, char wordguess); //guess the word function

	}

	// shut down
	if (wrong == MAX_WRONG)
		cout << "\nYou've been hanged!";
	else
		cout << "\nYou guessed it!";

	cout << "\nThe word was " << THE_WORD << endl;

	return 0;
}

//guess the word function
void getTheGuess(const string THE_WORD, char guess, int wrong, string soFar, char wordguess) {

	if (THE_WORD.find(guess) != string::npos)
	{
		cout << "That's right! " << guess << " is in the word.\n";

		// update soFar to include newly guessed letter
		for (unsigned int i = 0; i < THE_WORD.length(); ++i)
		{
			if (THE_WORD[i] == guess)
			{
				soFar[i] = guess;
			}
		}
	}
	else if (guess == wordguess) {
		void guessingWord(const string THE_WORD, int wrong); //guessing the entire word

	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		++wrong;
	}

}

//guessing he word function
void guessingWord(const string THE_WORD, int wrong) {
	string myword;
	cout << "You want to guess the word. \n";
	cout << "Enter your guess: \n";
	cin >> myword;
	if (THE_WORD == myword) {
		cout << "\nYou guessed it!";
		cout << "\nThe word was " << THE_WORD << endl;
		return 0;
	}
	else {
		cout << "Sorry, " << myword << " isn't the word.\n";
		++wrong;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
