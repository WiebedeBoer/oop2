// 16oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Template function
//The file twice.cpp contains an overloaded function.
//Rewrite the function twice so that it uses a template.

#include "pch.h"
#include <iostream>

using namespace std;

/*
int twice(int i)
{
	return i + i;
}

double twice(double d)
{
	return d + d;
}
*/

//template
template <class T>
T sum(T a, T b)
{
	T result;
	result = a + b;
	return result;
}

//main
int main()
{
	//cout << twice(5) << endl;
	//cout << twice(5.3) << endl;

	int i = 5, j = 6, k;
	double f = 2.0, g = 0.5, h;
	k = sum<int>(i, j);
	h = sum<double>(f, g);
	cout << k << '\n';
	cout << h << '\n';

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
