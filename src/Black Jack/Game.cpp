#include "Game.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <limits>



Game::Game(){
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
	while (mPlayer.getMoney() > 0 && !mInputClosed){
		if (!bet()) {
			break;
		}
	}

	if (mInputClosed) {
		std::cout << "Input closed.\n";
		return;
	}

	std::cout << "You are out of money.\nGame over.\n";
}

bool Game::bet(){
	std::cout << "You have $" << mPlayer.getMoney() << "\nPlease place your bet: ";
	while (true) {
		int amount = 0;
		std::cin >> amount;
		if (std::cin.fail())
		{
			if (std::cin.eof()) {
				mInputClosed = true;
				return false;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That's not an integer. Please enter an integer only bet:\n";
			continue;
		}

		if (!mPlayer.placeBet(amount))
		{
			std::cout << "Error; Unable to process your bet.\nPlease enter your bet: ";
			continue;
		}

		mPot = mPlayer.getBet();
		std::cout << "You bet $" << mPlayer.getBet() << " you have $" << mPlayer.getMoney() << " left.\n";
		this->deal();
		return true;
	}
}

void Game::deal(){
	mDeck.shuffleDeck();
	mPlayer.receiveCard(mDeck.drawCard());
	mDealer.receiveCard(mDeck.drawCard());
	mPlayer.receiveCard(mDeck.drawCard());
	mDealer.receiveCard(mDeck.drawCard());

	mPlayer.showCards();
	mDealer.showCards(true);
	decision();
}

bool Game::decision(){

	if (mPlayer.getHand().size() == 2 && mPlayer.getPoints() == 21)
	{
		std::cout << "BlackJack!\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		stand();
		return true;
	}

	while (true)
	{
		int decide;
		std::cout << "Press '1' to hit or press '2' to stand.\n";
		std::cin >> decide;
		if (std::cin.fail())
		{
			if (std::cin.eof())
			{
				mInputClosed = true;
				mPlayer.recieveMoney(mPot);
				reset();
				return false;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid selection.\n";
			continue;
		}

		if (decide == 1)
		{
			mPlayer.receiveCard(mDeck.drawCard());
			mPlayer.showCards();

			if (mPlayer.getPoints() > 21)
			{
				std::cout << "Dealer won..." << " You now have $" << mPlayer.getMoney() << "\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				reset();
				return true;
			}

			continue;
		}

		if (decide == 2)
		{
			stand();
			return true;
		}

		std::cout << "Invalid selection.\n";
	}
	
}


void Game::stand(){
	//std::cout << "\033[2J\033[1;1H";

	std::cout << "The Dealer is drawing cards...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	mDealer.showCards();

	while (mDealer.shouldHit())
	{
		mDealer.receiveCard(mDeck.drawCard());
		mDealer.showCards();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			
	}
	whoWon();
}

void Game::whoWon(){
	if (mDealer.getPoints() > 21){
		mPlayer.recieveMoney(mPot * 2);
		std::cout << "You won." << " You now have $" << mPlayer.getMoney() << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mPlayer.getPoints() > 21) && (mDealer.getPoints() <= 21)){
		std::cout << "Dealer won..." << " You now have $" << mPlayer.getMoney() << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mDealer.getPoints() <= 21) && (mDealer.getPoints() > mPlayer.getPoints())){
		std::cout << "Dealer won..." << " You now have $" << mPlayer.getMoney() << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mPlayer.getPoints() <= 21) && (mDealer.getPoints() > 21)){

		mPlayer.recieveMoney(mPot * 2);
		std::cout << "You won." << " You now have $" << mPlayer.getMoney() << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if (mPlayer.getPoints() == mDealer.getPoints()){
		std::cout << "Push...\n";
		mPlayer.recieveMoney(mPot);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

	if ((mPlayer.getPoints() <= 21) && (mDealer.getPoints() < mPlayer.getPoints())){

		mPlayer.recieveMoney(mPot * 2);
		std::cout << "You won." << " You now have $" << mPlayer.getMoney() << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		reset();
		return;
	}

}



void Game::reset(){
	mPlayer.clearHand();
	mPlayer.clearBet();
	mDealer.clearHand();
	mDeck = Deck();
	mPot = 0;
	if (mPlayer.getMoney() > 0){
		std::cout << "Re-dealing Cards...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

}
