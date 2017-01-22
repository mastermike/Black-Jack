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


Player::~Player()
{
}


int& Player::get_money()
{
	return money;
}

std::string& Player::get_name()
{
	return name;
}