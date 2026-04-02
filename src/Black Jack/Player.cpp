#include "Player.h"
#include <iostream>
#include <limits>

Player::Player(std::string Face, int Money){
	money = Money;
	name = Face;
}

void Player::drawCard(Deck& deck){
	receiveCard(deck.drawCard());
}

void Player::receiveCard(const Card& card){
	hand.addCard(card);
}

Player::Player(){ //default constructor initiates name and money to default values
	money = 10000;
	name = "None";
}

void Player::changeName(){
	std::cin >> name;
}

Player::~Player(){
}

const int& Player::getMoney(){
	return money;
}

const std::string& Player::getName(){
	return name;
}

void Player::showCards(){
	std::cout << "You have: " << hand.getPoints() << " points.\n";
	for (const auto& card : hand.getCards())
	{
		card.display();
	}
}

void Player::placeBet(){
	while (true){
		std::cin >> bet;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That's not an integer. Please enter an integer only bet:\n";
			continue;
		}

		if ((bet <= 0) || (bet > money))
		{
			std::cout << "Error; Unable to process your bet.\nPlease enter your bet: ";
			continue;
		}

		money = money - bet;
		return;
	}
}

int Player::getBet(){
	return bet;	
}

void Player::recieveMoney(int i){
	money += 2*i;
}


int Player::getPoints(){
	return hand.getPoints();
}

const Hand& Player::getHand() const{
	return hand;
}

Hand& Player::getHand(){
	return hand;
}

