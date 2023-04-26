#include "CDeck.h"
#include "CPlayer.h"


#ifndef BLACKJACK_H
#define BLACKJACK_H

class CBlackjack {
public:
	CBlackjack();
	void startGame();

private:
	CDeck deck;
	CPlayer* players;
	int number_of_players;
};

#endif // !BLACKJACK_H