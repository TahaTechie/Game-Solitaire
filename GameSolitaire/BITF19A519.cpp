/*
File Name   : Practice.CPP
Author      : Muhammad Taha Amir
Date        : 12-7-2020
Description : This program is written to understand the console class(wrapper class) for PlayingCard Game
*/
#include "Solitaire.h"

const int PlayingCard::Daimond = 0;
const int PlayingCard::Heart = 1;
const int PlayingCard::Spade = 2;
const int PlayingCard::Club = 3;

int main() {


	Solitaire S;
	S.Shuffle();
	S.dealToPlayingPiles();
	S.DisplayGame();
	S.Play();

	return 0;
}
