#include "CDeck.h"

CDeck::CDeck() {
	cards = new CCard[52];
	int contor_cards = 0;
	while (contor_cards < 52) {
		for (int i = 0; i < 4; i++) {
			for (int j = 2; j < 15; j++) {
				cards[contor_cards].setNumber(j);
				cards[contor_cards].setSuite(i);
				contor_cards++;
			}
		}
	}
	number_of_decks = 0;
}


CCard& CDeck::getCard(int position) {
	return cards[position];
}

void CDeck::setNumberOfDecks(int number) { 
	this->number_of_decks = number; 
}

int CDeck::getNumberOfDecks() { 
	return this->number_of_decks; 
}
