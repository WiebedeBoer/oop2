// 2oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::cout << "Hello World!\n"; 
}

#include "pch.h"
#include <iostream>
using namespace std;

//opg 2 calculate avg with user input of three numbers

int main()
{
	double input1;
	double input2;
	double input3;

	double avg;

	cout << "Please enter a valid number: ";
	cin>> input1;

	cout << "Please enter a valid number: ";
	cin >> input2;

	cout << "Please enter a valid number: ";
	cin >> input3;

	avg = (input1 + input2 + input3) / 3.0;
	
	cout << "Hello World!\n";
	cout << "total divided by three is average " << avg << endl;

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
