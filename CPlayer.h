#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "CDeck.h";

#ifndef PLAYER_H
#define PLAYER_H

using std::vector;
using std::string;

class CPlayer{
public:
	void drawRandomCard(CDeck& deck);
	void printCards();
	void calculateScore();
	void calculateAcesScore();
	int getScore();
	void setScore(int score);
	int getCardNumber(int);
	void printCurrentScore();

private:
	vector<CCard> player_cards;
	vector<CCard> split_player_card;
	int score = 0;
	int number_of_aces = 0;
	string name;
};

int minim(int number1, int number2);

#endif // !PLAYER_H