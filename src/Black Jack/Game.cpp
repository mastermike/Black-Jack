#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <limits>



Game::Game(){
	mDealer.getDeck().blackjackrules();

}

Game::Game(Player& mPlayer1, Dealer& mDealer1) {
	mPlayer = mPlayer1;
	mDealer = mDealer1;
	Game();
}

Game::~Game(){
}

void Game::start(){
	std::cout << "Welcome to BlackJack!\n";
	while (mPlayer.getMoney() > 0){
		this->bet();
	}
	std::cout << "You are out of money.\nGame over.\n";
}

void Game::bet(){
	std::cout << "You have $" << mPlayer.getMoney() << "\nPlease place your bet: ";
	mPlayer.placeBet();
	mDealer.updatePot(mPlayer);

	std::cout << "You bet $" << mPlayer.getBet() << " you have $" << mPlayer.getMoney() << " left.\n";
	this->deal();
}

void Game::deal(){
	mDealer.deal(mPlayer);
	this->evaluate();
	mPlayer.showCards();
	mDealer.showCards(true);
	mDealer.updatePoints();
	mPlayer.updatePoints();
	decision();
}

void Game::decision(){

	if (mPlayer.getHand().size() == 2 && mPlayer.getPoints() == 21)
	{
		std::cout << "BlackJack!\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		stand();
		return;
	}

	while (true)
	{
		int decide;
		std::cout << "Press '1' to hit or press '2' to stand.\n";
		std::cin >> decide;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid selection.\n";
			continue;
		}

		if (decide == 1)
		{
			mPlayer.drawCard(mDealer.getDeck());
			evaluate();
			mPlayer.updatePoints();
			mPlayer.showCards();

			if (mPlayer.getPoints() > 21)
			{
				mDealer.dealerWin(mPlayer);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				reset();
				return;
			}

			continue;
		}

		if (decide == 2)
		{
			stand();
			return;
		}

		std::cout << "Invalid selection.\n";
	}
	
}


void Game::stand(){
	//std::cout << "\033[2J\033[1;1H";

	std::cout << "The Dealer is drawing cards...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	mDealer.updatePoints();
	mDealer.showCards();

	while (mDealer.getPoints() < 17)
	{
		mDealer.drawCard();
		evaluate();
		mDealer.showCards();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			
	}
	whoWon();
}

void Game::whoWon(){
	mDealer.updatePoints();
	mPlayer.updatePoints();
	if (mDealer.getPoints() > 21){
		mDealer.playerWin(mPlayer);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mPlayer.getPoints() > 21) && (mDealer.getPoints() <= 21)){
		mDealer.dealerWin(mPlayer);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mDealer.getPoints() <= 21) && (mDealer.getPoints() > mPlayer.getPoints())){
		mDealer.dealerWin(mPlayer);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mPlayer.getPoints() <= 21) && (mDealer.getPoints() > 21)){

		mDealer.playerWin(mPlayer);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if (mPlayer.getPoints() == mDealer.getPoints()){
		std::cout << "Push...\n";
		mPlayer.recieveMoney(mDealer.getPot() / 2);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mPlayer.getPoints() <= 21) && (mDealer.getPoints() < mPlayer.getPoints())){

		mDealer.playerWin(mPlayer);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}


}

void Game::evaluate(){
	for (std::list<Card>::iterator i = mPlayer.getHand().begin(); i != mPlayer.getHand().end(); i++){
		if ((i->isaFace() == true) && (i->getFace() != std::string("A"))){
			i->changeVal(10);
		}

		if (i->getFace() == std::string("A")){
			i->changeVal(11);
		}

	}
	mPlayer.updatePoints();
	for (std::list<Card>::iterator i = mPlayer.getHand().begin(); i != mPlayer.getHand().end(); i++){
		if ((i->getFace() == std::string("A")) && (mPlayer.getPoints() > 21)){
			i->changeVal(1);
			mPlayer.updatePoints();
		}
	}



	for (std::list<Card>::iterator i = mDealer.getHand().begin(); i != mDealer.getHand().end(); i++){
		if ((i->isaFace() == true) && (i->getFace() != std::string("A"))){
			i->changeVal(10);
		}

		if (i->getFace() == std::string("A")){
			i->changeVal(11);
		}
	}
	mDealer.updatePoints();
	for (std::list<Card>::iterator i = mDealer.getHand().begin(); i != mDealer.getHand().end(); i++){
		if ((i->getFace() == std::string("A")) && (mDealer.getPoints() > 21)){
			i->changeVal(1);
			mDealer.updatePoints();
		}
	}
	mDealer.updatePoints();
	mPlayer.updatePoints();
	
}



void Game::reset(){
	mDealer.unDeal(mPlayer);
	mDealer.resetPot();
	if (mPlayer.getMoney() > 0){
		std::cout << "Re-dealing Cards...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

}
