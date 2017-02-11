#pragma once
#include "Card.h"
#include <vector>


class Deck
{
private:
	std::vector<Card> deck;
public:
	Deck();
	~Deck();
	void showDeck();
	void shuffleDeck();
	Card getCard();
	void removeCard();
};

