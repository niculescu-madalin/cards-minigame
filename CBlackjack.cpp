#include "CBlackjack.h"

CBlackjack::CBlackjack() {

	int number_of_players;
	std::cout << "How many player will play the game: ";
	std::cin >> number_of_players;


	while (number_of_players <= 1) {
		std::cout << "The number of player is too small, the minimum is 2: ";
		std::cin >> number_of_players;
	}

	this->number_of_players = number_of_players;
	players = new CPlayer[number_of_players];

	int number_of_decks;
	std::cout << "The number of deck the game will be played with: ";
	std::cin >> number_of_decks;

	while (number_of_decks < 1) {
		std::cout << "The number of deck is too small, the minimum is 2: ";
		std::cin >> number_of_decks;
	}

	deck.setNumberOfDecks(number_of_decks);
}


void CBlackjack::startGame() {
	srand(time(0));

	for (int i = 0; i < number_of_players; i++) {

		// draws the first two cards
		players[i].drawRandomCard(deck);
		players[i].drawRandomCard(deck);
		// print the cards drawed ...
		std::cout << "Player " << i + 1 << ": \n";
		players[i].printCards();
		// ... and the current score
		std::cout << " Score: ";
		players[i].printCurrentScore();

		int choice;
		std::cout << "Chose an option: 1.HIT, 2.STAND, 0.SURRENDER\nOptiunea: ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			players[i].setScore(0);
		case 1:
			while (choice == 1) {
				// draw an aditional card and print it
				players[i].drawRandomCard(deck);
				players[i].printCards();
				// print the new score
				std::cout << " Score: ";
				players[i].printCurrentScore();

				std::cout << "\nChose an option: 1.HIT, 2.STAND, 0.SURRENDER \nOptiunea: ";
				std::cin >> choice;
				std::cout << "\n";
			}
		default:
			break;
		}
	}

	int* potentialWinners = new int[number_of_players];
	for (int i = 0; i < number_of_players; i++) {
		potentialWinners[i] = 0;  // initialize 0 for each potential winner
	}
	int winning_score_found = 0;

	// search the biggest score and the winners
	for (int i = 21; i > 0; i--) {
		for (int j = 0; j < number_of_players; j++) {
			if (players[j].getScore() == i) {                                                                                                                                                                                                                                                                                                      
				potentialWinners[j] = 1;
				winning_score_found = 1;
			}
		}
		if (winning_score_found) break;
	}

	std::cout << "\nThe winners are: \n ";
	for (int i = 0; i < number_of_players; i++) {
		if (potentialWinners[i] == 1) {
			std::cout << "Player " << i + 1 << "\n";
		}
	}
}
