#include "Card.h"
#include <iostream>
#include <list>
#include <string>


Card::Card(std::string Suite, std::string Face, int faceval, bool isface)
{
	suite = Suite;
	face = Face;
	faceVal = faceval;
	isFace = isface;
}


Card::Card()
{
	suite = "none";
	face = "none";
	faceVal = 0;
	isFace = false;
}

void Card::changeVal(int value)
{
	faceVal = value;
}

void Card::display()
{
	std::cout << '\t' << face << " of " << suite << std::endl;
}

Card::~Card()
{
}

int Card::getfaceVal()
{
	return faceVal;
}

std::string Card::getFace()
{
	return face;
}

bool Card::isaFace()
{
	return isFace;
}