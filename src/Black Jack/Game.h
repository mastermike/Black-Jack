#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class Game{
private:
	Player mPlayer;
	Dealer mDealer;
	Deck mDeck;
	int mPot = 0;
	bool mInputClosed = false;
public:
	Game();
	~Game();
	Game(Player&, Dealer&);
	void start();
	bool bet();
	void deal();
	bool decision();
	void stand();
	void reset();
	void whoWon();
};
