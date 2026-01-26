//Levi Metzger
//CIS-2207 N02
//01-23-26
//Implement an ADT for a number guessing game

#include <iostream>
#include <cctype>
#include <stdexcept>
#include <vector>
#include "Game.h"

int getNumToGuess();
int getMaxNum();
void runGuessing(const Game& game);
std::vector<int> getGuesses(const Game& game);
bool playAgain();

int main() {
	std::cout << "Welcome to the number guessing game.\n";

	int numToGuess{};
	const int rangeMin{ 1 };
	int rangeMax{};
	bool play{ true };
	Game game{};

	while (play) {
		numToGuess = getNumToGuess();
		rangeMax = getMaxNum();

		try {
			game.setGame(numToGuess, rangeMin, rangeMax);
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what();
			continue;
		}

		runGuessing(game);
		play = playAgain();
	}

	return 0;
}

int getNumToGuess() {
	std::cout << "\nEnter the number of integers you want to guess (max 10): ";

	int num{};
	while (!(std::cin >> num) || !(num >= 1 && num <= 10)) {
		std::cout << "Invalid input. Enter an integer between 1 and 10: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	return num;
}

int getMaxNum() {
	std::cout << "The range of numbers from which you will guess will be from 1 to x. "
		<< "Enter your desired value for x (max 100): ";

	int max{};
	while (!(std::cin >> max) || !(max > 1 && max <= 100)) {
		std::cout << "Invalid input. Enter an integer from 2 to 100: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	return max;
}

void runGuessing(const Game& game) {
	std::cout << "A random list of " << game.getSize() << " integer(s) in the range from "
		<< game.getMin() << " to " << game.getMax() << " has been generated.\n";

	int correctGuesses{};
	while (true) {
		try {
			correctGuesses = game.checkGuesses(getGuesses(game));
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what();
			continue;
		}

		if (correctGuesses == game.getSize()) {
			std::cout << "All guesses are correct!\n";
			break;
		}

		std::cout << correctGuesses << " of your guesses are correct.\n";
	}
}


std::vector<int> getGuesses(const Game& game) {
	const int numToGuess{ game.getSize() };
	const int min{ game.getMin() };
	const int max{ game.getMax() };

	std::cout << "Enter your guess of " << numToGuess << " integer(s) from "
		<< min << " to " << max << ", separated by spaces: ";

	std::vector<int> guesses{};

	for (int i = 0; i < game.getSize(); i++) {
		int guess{};
		while (!(std::cin >> guess) || !(guess >= min && guess <= max)) {
			std::cout << "Invalid input. You must enter " << numToGuess
				<< " integer(s) from " << min << " to " << max
				<< ", separated by spaces. Try again: ";

			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		guesses.push_back(guess);
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	return guesses;
}

bool playAgain() {
	std::cout << "Do you want to play again? (Y/N) ";
	char c{};
	while (!(std::cin >> c) || !(std::tolower(c) == 'y' || std::tolower(c) == 'n')) {
		std::cout << "Invalid input. Enter Y or N: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	return std::tolower(c) == 'y';
}