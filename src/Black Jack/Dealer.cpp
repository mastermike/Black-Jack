#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>

Dealer::Dealer(){

}
Dealer::~Dealer(){

}
void Dealer::showCard(){
	hand.begin()->display();
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

static bool shouldHit() const {
	return hand.getPoints() < 17; // Dealer hits on 16 or less
}