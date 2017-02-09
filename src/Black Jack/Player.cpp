#include "Player.h"
#include <iostream>
#include <string>



Player::Player(std::string Name, int Money, Card Card1, Card Card2)
{
	money = Money;
	name = Name;
	card1 = Card1;
	card2 = Card2;
}

Player::Player()
{
	money = 1000;
	name = "unnamed";
	card1 = Card();
	card2 = Card();
}

void Player::changeName()
{
	std::cin >> name;
}


Player::~Player()
{
	
}


const int& Player::getMoney()
{
	return money;
}

const std::string& Player::getName()
{
	return name;
}