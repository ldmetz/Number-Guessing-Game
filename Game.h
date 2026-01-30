//Levi Metzger
//CIS-2207 N02
//01-23-26
//Implement an ADT for a number guessing game

#pragma once

#include <vector>
#include <random>

class Game {
private:
	int rangeMin{};
	int rangeMax{};
	int numInts{};
	std::mt19937 randGen{ std::random_device{}() };
	std::vector<int> randomInts{};

public:
	/**
	* Constructs a game and generates its list of random numbers
	* @param num the number of integers to be guessed
	* @param min the lower bound of the range from which the integers will be guessed
	* @param max the upper bound of the range from which the integers will be guessed
	*/
	Game(int num = 1, int min = 1, int max = 10);

	/**
	* Checks the input guesses against the random list
	* @param guesses a vector containing the user's guesses
	* @return the number of correct guesses
	*/
	int checkGuesses(const std::vector<int>& guesses) const;

	/**
	* Sets the Game's attributes and generates the list of random numbers for guessing
	* @param num the number of integers to be guessed
	* @param min the lower bound of the range from which the integers will be guessed
	* @param max the upper bound of the range from which the integers will be guessed
	*/
	void setGame(int num, int min, int max);
};