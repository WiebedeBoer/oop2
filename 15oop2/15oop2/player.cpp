#include "player.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "hand.cpp"

using namespace std;

//class player
class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
	GenericPlayer(const string& name = "");

	virtual ~GenericPlayer();

	//indicates whether or not generic player wants to keep hitting
	virtual bool IsHitting() const = 0;

	//returns whether generic player has busted - has a total greater than 21
	bool IsBusted() const;

	//announces that the generic player busts
	void Bust() const;

protected:
	string m_Name;
};

GenericPlayer::GenericPlayer(const string& name) :
	m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
	cout << m_Name << " busts.\n";
}

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");

	virtual ~Player();

	//returns whether or not the player wants another hit       
	virtual bool IsHitting() const;

	//announces that the player wins
	void Win() const;

	//announces that the player loses
	void Lose() const;

	//announces that the player pushes
	void Push() const;
};

Player::Player(const string& name) :
	GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
	cout << m_Name << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
	cout << m_Name << " wins.\n";
}

void Player::Lose() const
{
	cout << m_Name << " loses.\n";
}

void Player::Push() const
{
	cout << m_Name << " pushes.\n";
}
