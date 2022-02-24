//Muhammad Taha Amir BITF19A519
#pragma once
#include"PlayingCard.h"


class Deck {
private:
	PlayingCard* deck[52];
	int size;
public:

	Deck();

	int getSize();

	bool IsEmpty();

	PlayingCard Remove(int value);

	~Deck();

};

