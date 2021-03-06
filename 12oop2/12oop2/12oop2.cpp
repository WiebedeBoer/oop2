// 12oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Overloading the << operator

//Create overloaded operator<< functions in the critter_farm.cpp program so that
//cout << crit << endl;
//will display a critter’s name and
//cout << myFarm << endl;
//will display the names of all critters in a farm.
//Don’t forget to declare the respective functions a friend of Critter and Farm so they can access the private members.

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class critter
class Critter
{
public:
	Critter(const string& name = "");
	string GetName() const;
	friend void Peek(const Critter& aCritter); //peeking
	friend ostream& operator<<(ostream& os, const Critter& aCritter);

private:
	string m_Name;
};


//Critter::Critter(const string& name) :
//	m_Name(name)
//{}

//constructor
Critter::Critter(const string& name)
{
	cout << "constructor called\n";
	m_pName = new string(name);
}


//destructor
~Critter() 
{
	cout << "destructor called\n";
	delete m_pName;
}

Critter::Critter(const Critter& c)
{
	cout << "copy constructor called\n";
	m_pName = new string(*(c.m_pName));
}


//overloading critter
Critter& Critter::operator= (const Critter& c) 
{
	cout << "overloaded";
	if (this != &c) {
		delete m_pName;
		m_pName = new string(*(c.m_pName));
	}
	return *this;
}

inline string Critter::GetName() const
{
	return m_Name;
}

//class farm
class Farm
{
public:
	Farm(int spaces = 1);
	void Add(const Critter& aCritter);
	void RollCall() const;

private:
	vector<Critter> m_Critters;
};

Farm::Farm(int spaces)
{
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
	for (vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end();
		++iter)
	{
		cout << iter->GetName() << " here.\n";
	}
}

//peeking
void Peek(const Critter& aCritter) 
{
	cout << aCritter.m_Name << endl;
}

//overloading operator
ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}

int main()
{
	Critter crit("Poochie");
	//cout << "My critter's name is " << crit.GetName() << endl;

	cout << "Calling Peek() to access crit's private data member, m_Name: \n";
	Peek(crit);

	cout << "\nCreating critter farm.\n";
	Farm myFarm(3);

	cout << "\nAdding three critters to the farm.\n";
	myFarm.Add(Critter("Moe"));
	myFarm.Add(Critter("Larry"));
	myFarm.Add(Critter("Curly"));

	cout << "\nCalling Roll...\n";
	myFarm.RollCall();

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
