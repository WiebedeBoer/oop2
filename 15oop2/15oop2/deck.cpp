#include "deck.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "card.cpp"
#include "hand.cpp"
#include "player.cpp"

using namespace std;

//class deck
class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();

	//create a standard deck of 52 cards
	void Populate();

	//shuffle cards
	void Shuffle();

	//deal one card to a hand
	void Deal(Hand& aHand);

	//give additional cards to a generic player 
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
	Clear();
	//create standard deck
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			Add(new Card(static_cast<Card::rank>(r),
				static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		cout << "Out of cards. Unable to deal.";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	cout << endl;
	//continue to deal a card as long as generic player isn't busted and
	//wants another hit
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;

		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	}
}