#include "Player.h"
#include <iostream>
#include <limits>

Player::Player(std::string Face, int Money){
	money = Money;
	name = Face;
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

const int& Player::getMoney() const{
	return money;
}

const std::string& Player::getName() const{
	return name;
}

void Player::showCards(){
	std::cout << "You have: " << hand.getPoints() << " points.\n";
	for (const auto& card : hand.getCards())
	{
		card.display();
	}
}

bool Player::placeBet(int amount){
	if (amount <= 0 || amount > money)
	{
		return false;
	}

	bet = amount;
	money -= bet;
	return true;
}

void Player::clearBet(){
	bet = 0;
}

int Player::getBet() const{
	return bet;	
}

void Player::recieveMoney(int amount){
	money += amount;
}

int Player::getPoints() const{
	return hand.getPoints();
}

void Player::clearHand(){
	hand.clear();
}

const Hand& Player::getHand() const{
	return hand;
}

Hand& Player::getHand(){
	return hand;
}

