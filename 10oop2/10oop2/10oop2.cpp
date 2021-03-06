// 10oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//The program mad-lib.cpp generates a simple story based on user input.
//Improve the Mad Lib program by using references to make the program more efficient.
//pointers

//Improve the Mad Lib program(mad - lib.cpp) as introduced in the previous exercise 
//so that no string objects are passed to the function that tells the story.
//Instead, the function should accept pointers to string objects.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
//void tellStory(string name, string noun, int number, string bodyPart, string verb);
void tellStory(string* const name, string* const noun, int* const number, string* const bodyPart, string* const verb);

int main()
{
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a verb: ");

	//tellStory(name, noun, number, bodyPart, verb);
	tellStory(&name, &noun, &number, &bodyPart, &verb);

	return 0;
}

string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory(string *name, string *noun, int *number, string *bodyPart, string *verb)
{
	cout << "\nHere's your story:\n";
	cout << "The famous explorer ";
	cout << &name;
	cout << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of ";
	cout << &noun;
	cout << " when one day, the ";
	cout << &noun;
	cout << " found the explorer.\n";
	cout << "Surrounded by ";
	cout << &number;
	cout << " " << &noun;
	cout << ", a tear came to ";
	cout << &name << "'s ";
	cout << &bodyPart << ".\n";
	cout << "After all this time, the quest was finally over. ";
	cout << "And then, the ";
	cout << &noun << "\n";
	cout << "promptly devoured ";
	cout << &name << ". ";
	cout << "The moral of the story? Be careful what you ";
	cout << &verb;
	cout << " for.";
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


