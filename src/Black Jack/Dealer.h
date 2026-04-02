#pragma once
#include "Deck.h"
#include "Player.h"
#include "Hand.h"


class Dealer{
private:
	Hand hand;
public:
	Dealer();
	~Dealer();
	void showCards(bool hideHoleCard = false); //displays the dealer's current hand
	void showCard();
	void receiveCard(const Card& card);
	static bool shouldHit() const;
		
};
