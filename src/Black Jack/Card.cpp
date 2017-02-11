#include "Card.h"
#include <iostream>
#include <list>
#include <string>


Card::Card(std::string Suite, std::string Face, int faceval)
{
	suite = Suite;
	face = Face;
	faceVal = faceval;

}

Card::Card()
{
	suite = "none";
	face = "none";
	faceVal = 0;

	
}

void Card::changeVal(int value)
{
	faceVal = value;
}

void Card::display()
{
	std::cout << face << " of " << suite << std::endl;
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

