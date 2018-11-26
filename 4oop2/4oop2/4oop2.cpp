// 4oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
enum choice
{
	1 = 'too low',
	2 = 'too high',
	3 ='you guessed it'

};
*/

int main()
{
    
	cout << "Pick a random number between 1 and 100. The computer has to guess the number. ";
	cout << "1 is too low, 2 is too high, 3 is you guessed it. ";

	int tries = 0;
	int myNum;
	int CompNum;
	int myCheck;
	int minNum = 1;
	int maxNum = 100;

	do
	{
		++tries;
		//1st try
		if (tries == 1) {
			CompNum = 50;
			cout << "\nComputer's guess: ";
			cout << CompNum;
			cin >> myCheck;
			if (myCheck == 1)
			{
				cout << "\n I am too low..!\n\n";
				minNum = CompNum;
				CompNum = 75;
				
			}
			else if (myCheck == 2)
			{
				cout << "\n I am too high..!\n\n";
				maxNum = CompNum;
				CompNum = 25;
			}
			else if (myCheck == 3)
			{
				cout << "\n I got your number\n\n in " << tries << " try!\n\n";
				myNum = CompNum;
			}
			else {
				cout << "\n invalid choice, pick 1 or 2 or 3\n\n";
			}
		}
		//more tries
		else {
			cout << "\nComputer's guess: ";
			cout << CompNum;
			cin >> myCheck;
			if (myCheck == 1)
			{
				cout << "\n I am too low..!\n\n";
				minNum = CompNum;
				CompNum = floor((minNum + maxNum) / 2);
			}
			else if (myCheck == 2)
			{
				cout << "\n I am too high..!\n\n";
				maxNum = CompNum;
				CompNum = floor((minNum + maxNum) / 2);
			}
			else if (myCheck == 3)
			{
				cout << "\n I got your number\n\n in just " << tries << " tries!\n\n";
				myNum = CompNum;
			}
			else {
				cout << "\n invalid choice, pick 1 or 2 or 3\n\n";
			}
		}		

	} while (myNum != CompNum);
	
	//std::cout << "Hello World!\n"; 


	/*
	    srand(static_cast<unsigned int>(time(0)));  //seed random number generator

    int secretNumber = rand() % 100 + 1;  // random number between 1 and 100
    int tries = 0;
    int guess;
    
    cout << "\tWelcome to Guess My Number\n\n";

    do
    {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;

        if (guess > secretNumber)
        {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low!\n\n";
        }
        else
        {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        }

    } while (guess != secretNumber);
	*/



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
