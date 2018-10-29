#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>

Dealer::Dealer()
{

}
Dealer::~Dealer()
{

}
void Dealer::deal(Player& player)
{
	deck.shuffleDeck();
	player.drawCard(deck);
	this->drawCard();
	player.drawCard(deck);
}
void Dealer::showPoints()
{
	std::cout << points << std::endl;
}
Deck& Dealer::getDeck()
{
	return deck;
}
void Dealer::drawCard()
{
	hand.push_back(deck.getCard());
	deck.pop_back();
}
void Dealer::showCard()
{
	hand.begin()->display();
}
void Dealer::updatePoints()
{
	points = 0;
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		points += i->getfaceVal();
	}
}
int Dealer::getPoints()
{
	return points;
}
void Dealer::showCards()
{
	updatePoints();
	std::cout << "The Dealer has " << points << " points.\n";
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		i->display();
	}

}
void Dealer::resetPot()
{
	pot = 0;
}
void Dealer::updatePot(Player& player)
{
	pot += player.getBet();
}


std::list<Card>& Dealer::getHand()
{
	return hand;
}

void Dealer::playerWin(Player& player)
{
	player.recieveMoney(pot);
	std::cout << "You won.\n";
	pot = 0;
}

void Dealer::dealerWin(Player& player)
{
	std::cout << "Dealer won...\n";
	
	pot = 0;
}



void Dealer::unDeal(Player& player)
{

	while (hand.empty() == false)
	{
		std::list<Card>::iterator i = hand.begin();
		deck.push_back(*i);
		hand.pop_front();
	}

	while (player.getHand().empty() == false)
	{
		std::list<Card>::iterator j = player.getHand().begin();
		deck.push_back(*j);
		player.getHand().pop_front();

	}
}

int Dealer::getPot()
{
	return pot;
}