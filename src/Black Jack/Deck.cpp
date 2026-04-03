#include "Deck.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <random>

Deck::Deck(){
	static const std::array<std::string, 4> suits = { "Hearts", "Diamonds", "Spades", "Clubs" };
	static const std::array<std::string, 13> faces = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

	deck.reserve(suits.size() * faces.size());
	for (const auto& suit : suits) {
		for (std::size_t i = 0; i < faces.size(); ++i) {
			const bool isAce = faces[i] == "A";
			const bool isFaceCard = faces[i] == "J" || faces[i] == "Q" || faces[i] == "K" || isAce;
			int faceValue = static_cast<int>(i) + 2;
			if (faces[i] == "J" || faces[i] == "Q" || faces[i] == "K") {
				faceValue = 10;
			}
			else if (isAce) {
				faceValue = 11;
			}
			deck.push_back(Card(suit, faces[i], faceValue, isFaceCard));
		}
	}
}

Card Deck::drawCard(){
	Card card = deck.back();
	deck.pop_back();
	return card;
}

void Deck::showDeck(){
	for (std::vector<Card>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		i->display();
	}
}

void Deck::shuffleDeck(){
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
}

Deck::~Deck(){
}

void Deck::push_back(const Card& card){
	deck.push_back(card);
}

std::size_t Deck::size() const {
	return deck.size();
}

bool Deck::isEmpty() const {
	return deck.empty();
}
