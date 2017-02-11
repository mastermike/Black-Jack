#pragma once
#include <list>
class Card
{
private:
	std::string suite; //contains the face of suite (eg. hearts, spades, etc.)
	std::string face; //contains the face value of the card (eg. '10', king, etc.)
	int faceVal; //a numerical representation of the face of the card (eg jack = 11, queen = 12, etc.)

public:
	Card(std::string, std::string, int);
	Card();
	~Card();
	void changeVal(int);
	void display();
	int getfaceVal();
	std::string getFace();

};

