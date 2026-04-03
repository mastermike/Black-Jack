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
	const int& getMoney() const;
	const std::string& getName() const;
	void changeName(); //changes player's name using cin
	void receiveCard(const Card& card);
	void showCards(); //displays the player's current hand
	bool placeBet(int amount);
	void clearBet();
	int getBet() const;
	void recieveMoney(int amount);
	int getPoints() const;
	void clearHand();
	const Hand& getHand() const;
	Hand& getHand();
};
