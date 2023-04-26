#include "CPlayer.h"

int minim(int number1, int number2) {
	if (number1 < number2) {
		return number1;
	}
	else
		return number2;
}


void CPlayer::drawRandomCard(CDeck& deck) {

	int random_position = 1 + rand() % 52;
	CCard drawed_card = deck.getCard(random_position);
	player_cards.push_back(drawed_card);

	while (drawed_card.getStatus() >= deck.getNumberOfDecks()) {
		player_cards.pop_back();
		random_position = 1 + rand() % 52;
		drawed_card = deck.getCard(random_position);
		player_cards.push_back(drawed_card);
	}

	deck.getCard(random_position).iterateStatus();
}

void CPlayer::printCards() {
	for (int i = 0; i < player_cards.size(); i++) {
		std::cout << player_cards.at(i).getNumber();
		switch (player_cards.at(i).getSuite()) {
		case 0:
			std::cout << " de Pica ";
			break;
		case 1:
			std::cout << " de Inima ";
			break;

		case 2:
			std::cout << " de Trefla ";
			break;
		case 3:
			std::cout << " de Romb ";
			break;
		default:
			std::cout << "Nu sa putut gasi suita";
		}
		std::cout << ", ";
	}
}

// calculate the score without aces
void CPlayer::calculateScore() {
	for (int i = 0; i < player_cards.size(); i++) {
		if (player_cards[i].getNumber() < 11) {
			score += player_cards[i].getNumber();
		}
		else if (player_cards[i].getNumber() > 11) {
			score += 10;
		}
		else {
			number_of_aces++;
		}
	}
}


// calculate the best possible score from aces with dynamic progamming
void CPlayer::calculateAcesScore() {

	if (number_of_aces > 0) {
		int aces[2] = { 1,11 };
		int maxim_value = 21 - score;
		int* possible_values;
		possible_values = new int[maxim_value + 1];


		for (int i = 0; i <= maxim_value; i++) {
			possible_values[i] = INT_MAX;
		}

		possible_values[0] = 0;

		for (int i = 0; i <= maxim_value; i++) {
			for (int j = 0; j < 2; j++) {
				if (aces[j] <= i) {
					possible_values[i] = minim(possible_values[i], possible_values[i - aces[j]] + 1);
				}
			}
		}

		for (int i = maxim_value; i >= 0; i--) {
			if (number_of_aces == possible_values[i]) {
				score = score + i;
				break;
			}
		}
	}
}

int CPlayer::getScore() {
	return this->score;
}

void CPlayer::setScore(int score) {
	this->score = score;
}

int::CPlayer::getCardNumber(int position) {
	return this->player_cards.at(position).getNumber();
}

void CPlayer::printCurrentScore()
{
	score = 0; // Resets the previous score 
	calculateScore();
	calculateAcesScore();
	std::cout << score << "\n";
}
