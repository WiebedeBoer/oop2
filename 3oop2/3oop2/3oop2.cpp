// 3oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

enum menuchoice
{
	easy = 1,
	normal = 2,
	hard = 3
	//1 = easy,
	//2 = normal,
	//3 = hard
};

int main()
{
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	int choice;
	cout << "Choice: ";
	cin >> choice;

	menuchoice ch = menuchoice(choice);
	//ch = choice;
	cout << "You picked " << ch <<".\n";

	/*
	switch (choice)
	{
	case 1:
		cout << "You picked Easy.\n";
		break;
	case 2:
		cout << "You picked Normal.\n";
		break;
	case 3:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice.\n";
	}
	*/



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
