// 11oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//The Critter Caretaker game (critter_caretaker.cpp) puts the player in charge of his own virtual pet.

//The player is responsible for keeping the critter happy.
//He can feed and play with the critter to keep it in a good mood.
//He can also listen to the critter to learn how the critter is feeling, which can range from happy to mad.

//Improve the Critter Caretaker program so that you can enter an unlisted menu choice 
//that reveals the exact values of the critter’s hunger and boredom levels.


#include "pch.h"
#include <iostream>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void ShowHungerBoredom(); //function to show hunger and boredom 
	void DisplayLevels(); // function for displaying levels 

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time = 1);

};

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	cout << "I'm a critter and I feel ";

	int mood = GetMood();
	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "okay.\n";
	}
	else
	{
		cout << "happy.\n";
	}

	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp.\n";

	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheee!\n";

	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

//function to show hunger and boredom
void Critter::ShowHungerBoredom()
{
	if ((m_Hunger <= 4) && (m_Boredom <= 4))
	{
		cout << "I'm full and but i'm not bored. \n";
	}
	else if ((m_Hunger <= 4) && ((m_Boredom > 3 && m_Boredom <= 10)))
	{
		cout << "I'm full, but i'm kinda bored.\n";
	}
	else if ((m_Hunger <= 4) && (m_Boredom >= 10))
	{
		cout << "I'm full, but i'm very bored. \n";
	}
	else if ((m_Boredom <= 4) && ((m_Hunger > 4 && m_Hunger < 10)))
	{
		cout << "I'm kinda hungry, but i'm not bored. \n";
	}
	else if (((m_Boredom > 4 && m_Boredom < 10)) && ((m_Hunger > 4 && m_Hunger < 10)))
	{
		cout << "I'm kinda hungry and i'm kinda bored. \n";
	}
	else if ((m_Boredom >= 10) && ((m_Hunger > 4 && m_Hunger < 10)))
	{
		cout << "I'm kinda hungry, but i'm very bored. \n";
	}
	else if ((m_Hunger >= 10) && (m_Boredom <= 4))
	{
		cout << "I'm starving, but i'm not bored. \n";
	}
	else if ((m_Hunger >= 10) && ((m_Boredom > 4 && m_Boredom < 10)))
	{
		cout << "I'm starving, and i'm kinda bored. \n";
	}
	else if ((m_Hunger >= 10) && (m_Boredom >= 10))
	{
		cout << "I'm starving, and i'm very bored! \n";
	}
}

//function to display levels
void Critter::DisplayLevels()
{
	cout << "\nCritter Hunger Level: " << m_Hunger << ".\n";
	cout << "\nCritter Boredum Level: " << m_Boredom << ".\n";
}

int main()
{
	Critter crit;

	int choice = 1;  //start the critter off talking
	while (choice != 0)
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4: //secret menu option that displays levels
			crit.DisplayLevels();
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
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
