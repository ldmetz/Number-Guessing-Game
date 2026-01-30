//Levi Metzger
//CIS-2207 N02
//01-23-26
//Implement an ADT for a number guessing game

#include <random>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <stdexcept>
#include "Game.h"

Game::Game(int num, int min, int max) {
	setGame(num, min, max);
}

int Game::checkGuesses(const std::vector<int>& guesses) const {
	if (guesses.size() != numInts) {
		throw std::invalid_argument("Incorrect number of guesses. Expected: "
			+ std::to_string(numInts));
	}

	std::vector<int> guessesCopy{ guesses };
	int correctGuesses{};

	for (int i = 0; i < guessesCopy.size(); i++) {
		int guess = guessesCopy.at(i);

		//The number of times this number was guessed
		int timesGuessed{ static_cast<int>(
			std::count(guessesCopy.begin(), guessesCopy.end(), guess)) };

		//The number of times this number appears in the generated list
		int numInList{ static_cast<int>(
			std::count(randomInts.begin(), randomInts.end(), guess)) };

		correctGuesses += std::min(timesGuessed, numInList);

		//Remove all other occurences of this guess to avoid double-counting
		if (timesGuessed > 1) {
			guessesCopy.erase(
				std::remove(guessesCopy.begin() + i + 1, guessesCopy.end(), guess),
				guessesCopy.end());
		}
	}

	return correctGuesses;
}

void Game::setGame(int num, int min, int max) {
	if (num <= 0) {
		throw std::invalid_argument("num must be greater than zero");
	}
	if (min > max) {
		throw std::invalid_argument("min must be less than max");
	}

	numInts = num;
	rangeMin = min;
	rangeMax = max;

	//Define the range of numbers
	std::uniform_int_distribution range{ rangeMin, rangeMax };

	//Create the list of random numbers
	randomInts.clear();
	for (int i = 0; i < numInts; i++) {
		randomInts.push_back(range(randGen));
	}
}