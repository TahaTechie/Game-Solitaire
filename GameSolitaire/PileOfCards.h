//Muhammad Taha Amir BITF19A519
#pragma once
#include "PlayingCard.h";
#include<iostream>
using namespace std;

class PileofCards
{
private:
	PlayingCard* pile;
	int top;
	int  size;
	point startPt;
	point endPt;
public:
	PileofCards(int size = 0);

	PlayingCard peek();

	void Add(PlayingCard);

	PlayingCard Remove();

	bool IsEmpty();

	bool IsFull();

	int getTop();

	PlayingCard getTopCard();

	void setTop();

	point getstartPt();

	point getEndPt();

	void setStartPt(point P);

	void setEndPt(point P);

	PileofCards& operator=(const PileofCards& Obj);

	PlayingCard operator[](int index) {
		return this->pile[index];
	}

	PlayingCard viewCard(int i);

	void SimpleDisplay();

	void CascadingDisplay();

	void setSize(int size);

	~PileofCards();
};



