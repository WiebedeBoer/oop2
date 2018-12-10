#include "house.h"
#include "player.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//class house
class House : public GenericPlayer
{
public:
	House(const string& name = "House");

	virtual ~House();

	//indicates whether house is hitting - will always hit on 16 or less
	virtual bool IsHitting() const;

	//flips over first card
	void FlipFirstCard();
};

House::House(const string& name) :
	GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
	return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
	{
		m_Cards[0]->Flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}