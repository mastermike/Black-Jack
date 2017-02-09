#pragma once
#include "Card.h"
#include <string>

class Player
{
private:
	int money;
	std::string name;
	Card card1;
	Card card2;
public:
	Player(std::string, int, Card, Card);
	Player();
	~Player();
	const int& getMoney();
	const std::string& getName();
	void changeName();


};