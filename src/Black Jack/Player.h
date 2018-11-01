#pragma once
#include "Card.h"
#include "Deck.h"
#include <string>
#include <list>

class Player{
private:
	int money; //player's current amount of money for betting
	std::string name; //player's name
	std::list<Card> hand; //list of player's hand
	int bet = 0;
	int points = 0;
	int decision;
public:
	Player(std::string, int);
	Player();
	~Player();
	const int& getMoney();
	const std::string& getName();
	void changeName(); //changes player's name using cin
	void drawCard(Deck&); //"draws" a card from the "deck"
	void showCards(); //displays the player's current hand
	void placeBet();
	int getBet();
	void updatePoints();
	void recieveMoney(int);
	int getPoints();
	std::list<Card>& getHand();



	
};