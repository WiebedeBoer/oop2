// 6oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program using vectors and iterators that allows a user to maintain a list of his or her favorite games.

//The program should allow the user to
//list all game titles
//add a game title
//remove a game title

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	std::vector<string> games;  // collection of games
	int myoption;



	while (myoption !=4)
	{

		cout << "\n\n press 1 to enter a game.";
		cout << "\n\n press 2 to remove a game.";
		cout << "\n\n press 3 to show a list of all games.";
		cout << "\n\n press 4 to quit.";
		cin >> myoption;

		if (myoption == 1) {
			string mygame = "";
			cout << "\n\nEnter your game.";
			cin >> mygame;
			games.push_back(mygame);
		}
		else if (myoption == 2) {
			string mygame = "";
			cout << "\n\nRemove a game.";
			cin >> mygame;
			for (unsigned i = 0; i < games.size(); ++i) {
				if (games[i] == mygame)
				{
					games.erase(games.begin() + i); // why not erase?
				}
			}
			
		}
		else if (myoption == 3) {
		
			cout << "\n\nList if your games: \n\n";

			for (unsigned i = 0; i < games.size(); ++i)
				std::cout << ' ' << games[i];

		}
		else if (myoption == 4) {
			return 0;

		}

	}


	return 0;
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
