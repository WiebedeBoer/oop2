// 14oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Overriding a method
//Improve the abstract_creature.cpp program by adding a new class, OrcBoss, that is derived from Orc.
//An OrcBoss object should start off with 180 for its health data member.
//You should also override the virtual Greet() member function so that it displays : The orc boss growls hello.

#include "pch.h"
#include <iostream>
using namespace std;

//creature
class Creature  //abstract class
{
public:
	Creature(int health = 100);
	virtual void Greet() const = 0;   //pure virtual member function
	virtual void DisplayHealth() const;

protected:
	int m_Health;
};

Creature::Creature(int health) :
	m_Health(health)
{}

void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

//orc
class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet() const;
};

Orc::Orc(int health) :
	Creature(health)
{}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}

//orc boss class
class OrcBoss : public Orc
{
public:
	OrcBoss(int health = 180);
	virtual void Greet() const;
};

//orc boss health
OrcBoss::OrcBoss(int health) :
	Orc(health)
{}

//orc boss greet
void OrcBoss::Greet() const
{
	cout << "The orc boss growls hello.\n";
}

int main()
{
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

	//orc boss
	//Orc* pOrc = new OrcBoss();
	Creature *pOrc = new OrcBoss();
	//OrcBoss pOrc;
	pOrc->Greet();
	pOrc->DisplayHealth();

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
