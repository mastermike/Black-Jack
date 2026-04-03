#include "Hand.h"

void Hand::addCard(const Card& card) {
	cards.push_back(card);
}
void Hand::clear() {
	cards.clear();
}

int Hand::getPoints() const {
	int totalPoints = 0;
	int aceCount = 0;
	for (const auto& card : cards) {
		totalPoints += card.getfaceVal();
		if (card.getFace() == "A") {
			aceCount++;
		}
	}
	while (totalPoints > 21 && aceCount > 0) {
		totalPoints -= 10; // Treat Ace as 1 instead of 11
		aceCount--;
	}
	return totalPoints;
}

const std::list<Card>& Hand::getCards() const {
	return cards;
}

std::size_t Hand::size() const {
	return cards.size();
}

bool Hand::isEmpty() const {
	return cards.empty();
}
