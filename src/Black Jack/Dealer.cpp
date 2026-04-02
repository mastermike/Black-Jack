#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>

Dealer::Dealer(){

}
Dealer::~Dealer(){

}
void Dealer::deal(Player& player){
	deck.shuffleDeck();
	player.drawCard(deck);
	this->drawCard();
	player.drawCard(deck);
	this->drawCard();
}
void Dealer::showPoints(){
	std::cout << points << std::endl;
}
Deck& Dealer::getDeck(){
	return deck;
}
void Dealer::drawCard(){
	hand.push_back(deck.drawCard());
}
void Dealer::showCard(){
	hand.begin()->display();
}
void Dealer::updatePoints(){
	points = 0;
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		points += i->getfaceVal();
	}
}
int Dealer::getPoints(){
	return points;
}
void Dealer::showCards(bool hideHoleCard){
	if (hideHoleCard && hand.empty() == false)
	{
		std::cout << "The Dealer shows:\n";
		hand.begin()->display();
		if (hand.size() > 1)
		{
			std::cout << "\t[Hidden card]\n";
		}
		return;
	}

	updatePoints();
	std::cout << "The Dealer has " << points << " points.\n";
	for (std::list<Card>::iterator i = hand.begin(); i != hand.end(); i++)
	{
		i->display();
	}
}
void Dealer::resetPot(){
	pot = 0;
}
void Dealer::updatePot(Player& player){
	pot += player.getBet();
}


std::list<Card>& Dealer::getHand(){
	return hand;
}

void Dealer::playerWin(Player& player){
	player.recieveMoney(pot);
	std::cout << "You won." << " You now have $" << player.getMoney() << "\n";
	pot = 0;
}

void Dealer::dealerWin(Player& player){
	std::cout << "Dealer won..." << " You now have $" << player.getMoney() << "\n";
	
	pot = 0;
}



void Dealer::unDeal(Player& player){

	while (hand.empty() == false){
		std::list<Card>::iterator i = hand.begin();
		deck.push_back(*i);
		hand.pop_front();
	}

	while (player.getHand().empty() == false){
		std::list<Card>::iterator j = player.getHand().begin();
		deck.push_back(*j);
		player.getHand().pop_front();

	}
}

int Dealer::getPot(){
	return pot;
}
