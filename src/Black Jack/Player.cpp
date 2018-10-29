#include "Player.h"
#include "Deck.h"
#include <iostream>
#include "Dealer.h"
#include <string>

Player::Player(std::string Face, int Money)
{
	money = Money;
	name = Face;
}

void Player::drawCard(Deck& deck)
{
	hand.push_back(deck.getCard());
	deck.pop_back();
}

Player::Player() //default constructor initiates name and money to default values
{
	money = 10000;
	name = "None";
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
	points = 0;
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		points += i->getfaceVal();
	}
}




void Player::showCards()
{
	updatePoints();
	std::cout << "You have: " << points << " points.\n";
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		i->display();
	}

}

void Player::placeBet()
{
	std::cin >> bet;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "That's not an integer. Please enter an integer only bet:\n";



		placeBet();
	}
	else
	{
		if ((bet <= 0) || (bet > money))
		{
			std::cout << "Error; Unable to process your bet.\nPlease enter your bet: ";
			placeBet();
		}
		else
			money = money - bet;
			
	}
	
}

int Player::getBet()
{
	return bet;	
}

void Player::recieveMoney(int i)
{
	money += 2*i;
}


int Player::getPoints()
{
	return points;
}

std::list<Card>& Player::getHand()
{
	return hand;
}

