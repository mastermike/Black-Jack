#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <string>

Player::Player(std::string Face, int Money)
{
	money = Money;
	name = Face;
}

void Player::drawCard(Deck& deck)
{
	hand.push_back(deck.getCard());
	deck.removeCard();
}

Player::Player() //default constructor initiates name and money to default values
{
	money = 10000;
	std:: cin >> name;
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

void Player::updatePoints()
{
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		points += i->getfaceVal();
	}
}

void Player::showCards()
{
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		i->display();
	}
}

void Player::placeBet()
{
	std::cin >> bet;
	money -= bet;
}

int Player::getBet()
{
	return bet;	
}