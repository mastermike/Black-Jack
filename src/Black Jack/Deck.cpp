#include "Deck.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>
#include <chrono>
#include <vector>

Deck::Deck()
{
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			deck.push_back(Card("Hearts", "Two", 2));
			deck.push_back(Card("Hearts", "Three", 3));
			deck.push_back(Card("Hearts", "Four", 4));
			deck.push_back(Card("Hearts", "Five", 5));
			deck.push_back(Card("Hearts", "Six", 6));
			deck.push_back(Card("Hearts", "Seven", 7));
			deck.push_back(Card("Hearts", "Eight", 8));
			deck.push_back(Card("Hearts", "Nine", 9));
			deck.push_back(Card("Hearts", "Ten", 10));
			deck.push_back(Card("Hearts", "Jack", 11));
			deck.push_back(Card("Hearts", "Queen", 12));
			deck.push_back(Card("Hearts", "King", 13));
			deck.push_back(Card("Hearts", "Ace", 14));

		case 1:
			deck.push_back(Card("Diamonds", "Two", 2));
			deck.push_back(Card("Diamonds", "Three", 3));
			deck.push_back(Card("Diamonds", "Four", 4));
			deck.push_back(Card("Diamonds", "Five", 5));
			deck.push_back(Card("Diamonds", "Six", 6));
			deck.push_back(Card("Diamonds", "Seven", 7));
			deck.push_back(Card("Diamonds", "Eight", 8));
			deck.push_back(Card("Diamonds", "Nine", 9));
			deck.push_back(Card("Diamonds", "Ten", 10));
			deck.push_back(Card("Diamonds", "Jack", 11));
			deck.push_back(Card("Diamonds", "Queen", 12));
			deck.push_back(Card("Diamonds", "King", 13));
			deck.push_back(Card("Diamonds", "Ace", 14));
		case 2:
			deck.push_back(Card("Spades", "Two", 2));
			deck.push_back(Card("Spades", "Three", 3));
			deck.push_back(Card("Spades", "Four", 4));
			deck.push_back(Card("Spades", "Five", 5));
			deck.push_back(Card("Spades", "Six", 6));
			deck.push_back(Card("Spades", "Seven", 7));
			deck.push_back(Card("Spades", "Eight", 8));
			deck.push_back(Card("Spades", "Nine", 9));
			deck.push_back(Card("Spades", "Ten", 10));
			deck.push_back(Card("Spades", "Jack", 11));
			deck.push_back(Card("Spades", "Queen", 12));
			deck.push_back(Card("Spades", "King", 13));
			deck.push_back(Card("Spades", "Ace", 14));
		case 3:
			deck.push_back(Card("Clubs", "Two", 2));
			deck.push_back(Card("Clubs", "Three", 3));
			deck.push_back(Card("Clubs", "Four", 4));
			deck.push_back(Card("Clubs", "Five", 5));
			deck.push_back(Card("Clubs", "Six", 6));
			deck.push_back(Card("Clubs", "Seven", 7));
			deck.push_back(Card("Clubs", "Eight", 8));
			deck.push_back(Card("Clubs", "Nine", 9));
			deck.push_back(Card("Clubs", "Ten", 10));
			deck.push_back(Card("Clubs", "Jack", 11));
			deck.push_back(Card("Clubs", "Queen", 12));
			deck.push_back(Card("Clubs", "King", 13));
			deck.push_back(Card("Clubs", "Ace", 14));
		}
	}
}

Card Deck::getCard()
{
	return deck.back();
}

void Deck::removeCard()
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