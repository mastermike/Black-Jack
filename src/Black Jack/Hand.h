#pragma once
#include <list>
#include "Card.h"

class Hand {
private:
	std::list<Card> cards;

public:
	void addCard(const Card& card);
	void clear();
	int getPoints() const;
	const std::list<Card>& getCards() const;
};
