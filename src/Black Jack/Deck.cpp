#include "Deck.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>
#include <chrono>
#include <vector>

Deck::Deck()
{
	for (int i = 0; i != 1; i++)
	{
	
			deck.push_back(Card("Hearts", "2", 2, false));
			deck.push_back(Card("Hearts", "3", 3, false));
			deck.push_back(Card("Hearts", "4", 4, false));
			deck.push_back(Card("Hearts", "5", 5, false));
			deck.push_back(Card("Hearts", "6", 6, false));
			deck.push_back(Card("Hearts", "7", 7, false));
			deck.push_back(Card("Hearts", "8", 8, false));
			deck.push_back(Card("Hearts", "9", 9, false));
			deck.push_back(Card("Hearts", "10", 10, false));
			deck.push_back(Card("Hearts", "J", 11, true));
			deck.push_back(Card("Hearts", "Q", 12, true));
			deck.push_back(Card("Hearts", "K", 13, true));
			deck.push_back(Card("Hearts", "A", 14, true));
			deck.push_back(Card("Diamonds", "2", 2, false));
			deck.push_back(Card("Diamonds", "3", 3, false));
			deck.push_back(Card("Diamonds", "4", 4, false));
			deck.push_back(Card("Diamonds", "5", 5, false));
			deck.push_back(Card("Diamonds", "6", 6, false));
			deck.push_back(Card("Diamonds", "7", 7, false));
			deck.push_back(Card("Diamonds", "8", 8, false));
			deck.push_back(Card("Diamonds", "9", 9, false));
			deck.push_back(Card("Diamonds", "10", 10, false));
			deck.push_back(Card("Diamonds", "J", 11, true));
			deck.push_back(Card("Diamonds", "Q", 12, true));
			deck.push_back(Card("Diamonds", "K", 13, true));
			deck.push_back(Card("Diamonds", "A", 14, true));
			deck.push_back(Card("Spades", "2", 2, false));
			deck.push_back(Card("Spades", "3", 3, false));
			deck.push_back(Card("Spades", "4", 4, false));
			deck.push_back(Card("Spades", "5", 5, false));
			deck.push_back(Card("Spades", "6", 6, false));
			deck.push_back(Card("Spades", "7", 7, false));
			deck.push_back(Card("Spades", "8", 8, false));
			deck.push_back(Card("Spades", "9", 9, false));
			deck.push_back(Card("Spades", "10", 10, false));
			deck.push_back(Card("Spades", "J", 11, true));
			deck.push_back(Card("Spades", "Q", 12, true));
			deck.push_back(Card("Spades", "K", 13, true));
			deck.push_back(Card("Spades", "A", 14, true));
			deck.push_back(Card("Clubs", "2", 2, false));
			deck.push_back(Card("Clubs", "3", 3, false));
			deck.push_back(Card("Clubs", "4", 4, false));
			deck.push_back(Card("Clubs", "5", 5, false));
			deck.push_back(Card("Clubs", "6", 6, false));
			deck.push_back(Card("Clubs", "7", 7, false));
			deck.push_back(Card("Clubs", "8", 8, false));
			deck.push_back(Card("Clubs", "9", 9, false));
			deck.push_back(Card("Clubs", "10", 10, false));
			deck.push_back(Card("Clubs", "J", 11, true));
			deck.push_back(Card("Clubs", "Q", 12, true));
			deck.push_back(Card("Clubs", "K", 13, true));
			deck.push_back(Card("Clubs", "A", 14, true));
		
	}
}


void Deck::blackjackrules()
{
	for (std::vector<Card>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		if (i->getfaceVal() > 10 && i->getFace() != "A")
			i->changeVal(10);
		if (i->getFace() == "A")
			i->changeVal(11);
	}
}

Card Deck::getCard()
{
	return deck.back();
}

void Deck::pop_back()
{
	deck.pop_back();
}




void Deck::showDeck()
{
	for (std::vector<Card>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		i->display();
	}
}

void Deck::shuffleDeck()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
}

Deck::~Deck()
{
}

void Deck::push_back(Card card)
{
	deck.push_back(card);
}

void Deck::size() {
	std::cout << deck.size() << '\n';
}