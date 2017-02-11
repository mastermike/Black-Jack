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
	this->drawCard(deck);
	player.drawCard(deck);
}




const Deck& Dealer::getDeck()
{
	return deck;
}

void Dealer::drawCard(Deck& deck)
{
	hand.push_back(deck.getCard());
	deck.removeCard();
}
void Dealer::showCard()
{
	hand.begin()->display();
}

void Dealer::updatePoints()
{
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
	player.placeBet();
	pot += player.getBet();
}