#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <string>
using namespace std;

int main() {
	Card c1, c2;
	Player Mike("Mike", 1000, c1, c2 );
	cout << Mike.getName() << endl;
	Mike.changeName();
	cout << Mike.getName() << endl;
	return 0;

}