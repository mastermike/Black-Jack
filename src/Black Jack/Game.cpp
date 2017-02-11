#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <iostream>


Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{
	std::cout << "Welcome to BlackJack!\nPlease enter your name: ";
	Player player;
	Dealer dealer;
	std::cout << "Pleace place your bet: ";
	player.placeBet();
	std::cout << "You bet: $" << player.getBet() << " You have $" << player.getMoney() << " left\n";
	std::cout << std::endl << "The Dealer will now deal the cards.\n\n";
	dealer.deal(player);
	std::cout << "???\n";
	
}