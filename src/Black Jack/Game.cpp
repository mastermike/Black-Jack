#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>



Game::Game()
{
	Player player;
	Dealer dealer;
	dealer.getDeck().blackjackrules();
	this->start(player, dealer);
	
}
Game::~Game()
{
}



void Game::start(Player& player, Dealer& dealer)
{
	std::cout << "Welcome to BlackJack!\n";

	this->bet(player, dealer);
}


void Game::bet(Player& player, Dealer& dealer)
{
	std::cout << "You have $" << player.getMoney() << "\nPlease place your bet: ";
	player.placeBet();
	dealer.updatePot(player);

	std::cout << "You bet $" << player.getBet() << " you have $" << player.getMoney() << " left.\n";
	this->deal(player, dealer);
}

void Game::deal(Player& player, Dealer& dealer)
{
	dealer.deal(player);
	this->evaluate(player, dealer);
	player.showCards();
	dealer.showCards();
	dealer.updatePoints();
	player.updatePoints();
	decision(player, dealer);
}


void Game::decision(Player& player, Dealer& dealer)
{

	if (player.getPoints() == 21)
	{
		std::cout << "BlackJack!\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		stand(player, dealer);
	}

	int decide;
	std::cout << "Press '1' to hit or press '2' to stand.\n";
	std::cin >> decide;
	if (decide == 1)
	{
		player.drawCard(dealer.getDeck());
		evaluate(player, dealer);
		player.updatePoints();
		player.showCards();

		if (player.getPoints() > 21)
		{
			dealer.dealerWin(player);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			reset(player, dealer);
		}
		decision(player, dealer);
	}

	if (decide == 2)
	{
		stand(player, dealer);
	}
	
}


void Game::stand(Player& player, Dealer& dealer)
{
	//std::cout << "\033[2J\033[1;1H";

	std::cout << "The dealer is drawing cards...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	dealer.updatePoints();

	while (dealer.getPoints() < 17)
	{
		dealer.drawCard();
		evaluate(player, dealer);
		dealer.showCards();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			
	}
	whoWon(player, dealer);
}

void Game::whoWon(Player& player, Dealer& dealer)
{
	dealer.updatePoints();
	player.updatePoints();
	if (dealer.getPoints() > 21)
	{
		dealer.playerWin(player);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset(player, dealer);
	}

	if ((player.getPoints() > 21) && (dealer.getPoints() <= 21))
	{
		dealer.dealerWin(player);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset(player, dealer);
	}

	if ((dealer.getPoints() <= 21) && (dealer.getPoints() > player.getPoints()))
	{
		dealer.dealerWin(player);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset(player, dealer);
	}

	if ((player.getPoints() <= 21) && (dealer.getPoints() > 21))
	{

		dealer.playerWin(player);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset(player, dealer);
	}

	if (player.getPoints() == dealer.getPoints())
	{
		std::cout << "Push...\n";
		player.recieveMoney(dealer.getPot() / 2);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset(player, dealer);
	}

	if ((player.getPoints() <= 21) && (dealer.getPoints() < player.getPoints()))
	{

		dealer.playerWin(player);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset(player, dealer);
	}


}

void Game::evaluate(Player& player, Dealer& dealer)
{
	for (std::list<Card>::iterator i = player.getHand().begin(); i != player.getHand().end(); i++)
	{
		if ((i->isaFace() == true) && (i->getFace() != std::string("A")))
		{
			i->changeVal(10);
		}

		if (i->getFace() == std::string("A"))
		{
			i->changeVal(11);
		}

	}
	player.updatePoints();
	for (std::list<Card>::iterator i = player.getHand().begin(); i != player.getHand().end(); i++)
	{
		if ((i->getFace() == std::string("A")) && (player.getPoints() > 21))
		{
			i->changeVal(1);
			player.updatePoints();
		}
	}



	for (std::list<Card>::iterator i = dealer.getHand().begin(); i != dealer.getHand().end(); i++)
	{
		if ((i->isaFace() == true) && (i->getFace() != std::string("A")))
		{
			i->changeVal(10);
		}

		if (i->getFace() == std::string("A"))
		{
			i->changeVal(11);
		}


	}
	dealer.updatePoints();
	for (std::list<Card>::iterator i = dealer.getHand().begin(); i != dealer.getHand().end(); i++)
	{
		if ((i->getFace() == std::string("A")) && (dealer.getPoints() > 21))
		{
			i->changeVal(1);
			dealer.updatePoints();
		}
	}
	dealer.updatePoints();
	player.updatePoints();
	
}


Game::Game(Player& player1, Dealer& dealer1)
{
	player = player1;
	dealer = dealer1;
	this->bet(player, dealer);
}
void Game::reset(Player& player, Dealer& dealer)
{

	if (player.getMoney() <= 0)
	{
		std::cout << "You are out of money.\nGame over.\n";
		this->~Game();
		Game game;
	}
	dealer.unDeal(player);
	std::cout << "Re-dealing Cards...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	bet(player, dealer);

}