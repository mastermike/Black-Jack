#pragma once
#include "Card.h"
#include <cstddef>
#include <vector>


class Deck{
private:
	std::vector<Card> deck;
public:
	Deck();
	~Deck();
	void showDeck();
	void shuffleDeck();
	Card drawCard();
	void push_back(const Card& card);
	std::size_t size() const;
	bool isEmpty() const;
};

