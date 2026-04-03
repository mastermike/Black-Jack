#include "Dealer.h"
#include <iostream>

Dealer::Dealer(){

}
Dealer::~Dealer(){

}
void Dealer::showCard() const{
	if (!hand.isEmpty()) {
		hand.getCards().begin()->display();
	}
}

void Dealer::showCards(bool hideHoleCard){
	std::cout << "Dealer's Hand:" << std::endl;
	int index = 0;
	for (const auto& card : hand.getCards()) {
		if (index == 0 && hideHoleCard) {
			std::cout << "\t[Hidden Card]" << std::endl;
		} else {
			card.display();
		}
		index++;
	}
}
void Dealer::receiveCard(const Card& card){
	hand.addCard(card);
}

int Dealer::getPoints() const{
	return hand.getPoints();
}

bool Dealer::shouldHit() const {
	return hand.getPoints() < 17;
}

void Dealer::clearHand(){
	hand.clear();
}

const Hand& Dealer::getHand() const{
	return hand;
}

Hand& Dealer::getHand(){
	return hand;
}
