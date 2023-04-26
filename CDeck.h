#include "CCard.h"
#include <iostream>

#ifndef DECK_H
#define DECK_H

class CDeck{
public:
	CDeck();

	CCard& getCard(int position);
	int getNumberOfDecks();
	void setNumberOfDecks(int number);

private:
	CCard* cards;
	int number_of_decks;
};

#endif // !DECK_H