#pragma once
#include "Deck.h"
#include "Hand.h"
#include <string>

class Player{
private:
	int money; //player's current amount of money for betting
	std::string name; //player's name
	Hand hand;
	int bet = 0;
public:
	Player(std::string, int);
	Player();
	~Player();
	const int& getMoney();
	const std::string& getName();
	void changeName(); //changes player's name using cin
	void drawCard(Deck&); //"draws" a card from the "deck"
	void receiveCard(const Card& card);
	void showCards(); //displays the player's current hand
	void placeBet();
	int getBet();
	void recieveMoney(int);
	int getPoints();
	const Hand& getHand() const;
	Hand& getHand();
};
