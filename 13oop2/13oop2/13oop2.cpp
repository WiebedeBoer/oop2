// 13oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Extending a class
//Improve the simple_boss2.cpp program by adding a new class, FinalBoss, that is derived from the Boss class.

//The FinalBoss class should define a new method, MegaAttack(), that inflicts 10 times the amount of damage 
//as the SpecialAttack() method does.

#include "pch.h"
#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy();
	void Attack() const;

protected:
	int m_Damage;
};

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	Boss();
	void SpecialAttack() const;

//private:
protected:
	int m_DamageMultiplier;
};

Boss::Boss() :
	m_DamageMultiplier(3)
{}

//final boss class
class FinalBoss : public Boss
{
public:
	FinalBoss();
	void MegaAttack() const;

private:
	int m_SADamageMultiplier;
};

//sub final boss
FinalBoss::FinalBoss() :
	m_SADamageMultiplier(10)
{}

//constrctor
void FinalBoss::MegaAttack() const
{
	cout << "Mega Attack inflicts " << (m_SADamageMultiplier *(m_DamageMultiplier * m_Damage));
	cout << " damage points!\n";
}

void Boss::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
	cout << " damage points!\n";
}

int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	cout << "\nCreating a boss.\n";
	//Boss boss1;
	//boss1.Attack();
	//boss1.SpecialAttack();
	//mega
	FinalBoss finalboss1;
	finalboss1.Attack();
	finalboss1.SpecialAttack();
	finalboss1.MegaAttack();
	finalboss1.MegaAttack();

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
