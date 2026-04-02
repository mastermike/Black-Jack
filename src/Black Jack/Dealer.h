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
	void updatePoints();
	void deal(Player&);
	std::list<Card>& getHand();
	int getPot();
	
};
