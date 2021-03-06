// 8oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Using default arguments, write a function that asks the user for a number and returns that number. 
//The function should accept a string prompt from the calling code. 
//If the caller doesn’t supply a string for the prompt, the function should use a generic prompt.
//Next, using function overloading, write a function that achieves the same results.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int askNumber(string prompt = "Enter a number: ");
int askNumber(int guess);

int main() {
	int number = askNumber("Enter a num: ");
	cout << "You entered: " << number << endl;

	int mynumber;
	cout << "Enter another number: ";
	cin >> mynumber;
	mynumber = askNumber(mynumber);
	cout << "You entered: " << mynumber << endl;
	return 0;
}

int askNumber(string prompt) {
	int mynumber;
	cout << prompt;
	cin >> mynumber;
	return mynumber;
}

int askNumber(int mynumber) {
	int guess2 = mynumber;
	return guess2;

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
