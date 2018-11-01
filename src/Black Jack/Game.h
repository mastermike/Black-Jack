#pragma once
#include "Player.h"
#include "Dealer.h"

class Game{
private:
	Player mPlayer;
	Dealer mDealer;
public:
	Game();
	~Game();
	Game(Player&, Dealer&);
	void start();
	void bet();
	void deal();
	void decision();
	void evaluate();
	void stand();
	void reset();
	void whoWon();
};