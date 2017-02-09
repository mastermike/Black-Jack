#include "Card.h"
#include <list>


Card::Card(std::string Suite, std::string Type, bool isface, int faceval)
{
	suite = Suite;
	type = Type;
	isFace = isface;
	faceVal = faceval;
}

Card::Card()
{
	suite = "none";
	type = "none";
	isFace = false;
	faceVal = 0;
}

Card::~Card()
{
}
