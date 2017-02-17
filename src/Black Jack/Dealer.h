#pragma once
#include "Deck.h"
#include "Player.h"


class Dealer
{
private:
	int pot = 0;
	Deck deck;
	std::list<Card> hand; //list of dealer's hand
	int points = 0;
public:
	Dealer();
	~Dealer();
	Deck& getDeck();
	void updatePot(Player&);
	void resetPot();
	void drawCard(); //"draws" a card from the "deck"
	void showCards(); //displays the player's current hand
	void showCard();
	void updatePoints();
	int getPoints();
	void deal(Player&);
	void showPoints();
	std::list<Card>& getHand();
	void playerWin(Player&);
	void dealerWin(Player&);
	void unDeal(Player&);
	int getPot();
	
};