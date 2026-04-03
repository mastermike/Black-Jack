#pragma once
#include "Hand.h"


class Dealer{
private:
	Hand hand;
public:
	Dealer();
	~Dealer();
	void showCards(bool hideHoleCard = false); //displays the dealer's current hand
	void showCard() const;
	void receiveCard(const Card& card);
	int getPoints() const;
	bool shouldHit() const;
	void clearHand();
	const Hand& getHand() const;
	Hand& getHand();
};
