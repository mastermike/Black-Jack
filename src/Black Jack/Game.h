#pragma once
#include "Player.h"
#include "Dealer.h"

class Game
{
private:
	Player player;
	Dealer dealer;
public:
	Game();
	~Game();
	Game(Player&, Dealer&);
	void start(Player&, Dealer&);
	void bet(Player&, Dealer&);
	void deal(Player&, Dealer&);
	void decision(Player&, Dealer&);
	void evaluate(Player&, Dealer&);
	void stand(Player&, Dealer&);
	void reset(Player&, Dealer&);
	void whoWon(Player&, Dealer&);
};

