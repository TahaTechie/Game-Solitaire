#pragma once
#include "Deck.h"
#include "PileofCards.h"


class Solitaire
{
private:
	Deck DeckofCards;
	PileofCards stock;
	PileofCards waste;
	PileofCards home[4];
	PileofCards PlayingPile[7];
	ConsoleFunctions cf;
public:
	Solitaire();

	void Shuffle();

	void dealToPlayingPiles();

	point getClickedPoint();

	void moveFromStock();

	PileofCards* getClickedPile(point p, int& a, int &c);

	void moveFromWasteToHome(int a);

	void moveFromWasteToPlayingPile(int a,int c);

	void moveFromPlayingPileToHome(int a, int b,int c);

	void moveFromHomeToPlyingPile(int a, int b, int c);

	void moveFromPlayingPileToPlayingPile(int a,int b,int c1,int c2);

	void Play();

	void DisplayGame();
};


