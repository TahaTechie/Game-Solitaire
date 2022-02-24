//Muhammad Taha Amir BITF19A519
#pragma once
#include"ConsoleFunctions.h"

class PlayingCard
{
private:
	int rank; // integer 1-13
	int suit; // integer 0-3
	char color; // red and black 'r' for red and 'b' for black
	bool faceUp;
	bool top;
public:
	static const int Daimond;

	static const int Heart;

	static const int Spade;

	static const int Club;

	PlayingCard(int rank = 0, int suit = 0);

	void Display(int x = 0, int y = 0);

	int getRank();

	int getSuit();

	bool isFaceUp();

	void setFaceUp(bool value);

	bool isTop();

	void setTop(bool value);

	char getColor();
};
