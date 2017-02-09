#pragma once
#include <list>
class Card
{
private:
	std::string suite;
	std::string type;
	bool isFace;
	int faceVal;
public:
	Card(std::string, std::string, bool, int);
	Card();
	~Card();
};

