#pragma once
#include <list>
#include <string>
class Card{
private:
	std::string suite; //contains the face of suite (eg. hearts, spades, etc.)
	std::string face; //contains the face value of the card (eg. '10', king, etc.)
	int faceVal; //a numerical representation of the face of the card (eg jack = 11, queen = 12, etc.)
	bool isFace; //boolean expression to determine if the card is a face card (eg queen, king etc.)
public:
	Card::Card(std::string, std::string, int, bool);
	Card();
	~Card();
	void changeVal(int);
	void display();
	int getfaceVal();
	std::string getFace();
	bool isaFace();
	
};

