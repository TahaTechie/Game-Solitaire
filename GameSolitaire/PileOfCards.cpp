//Muhammad Taha Amir BITF19A519
#include "PileofCards.h"


PileofCards::PileofCards(int size) {
	this->size = size;
	this->pile = new PlayingCard[this->size];

	/*
	for (int i = 0; i < this->size; i++) {
		this->pile[i] = PlayingCard();
	}
	*/
	this->top = -1;
	this->startPt.x = 0;
	this->startPt.y = 0;
	this->endPt.x = 0;
	this->endPt.y = 0;
}

void PileofCards::Add(PlayingCard Card) {
	if (!(this->IsFull())) {
		for (int i = 0; i < this->size; i++) {
			if (this->pile[i].getRank() == 0 && this->pile[i].getSuit() == 0) {
				if (this->getTop() != i) {
					this->pile[i] = Card;
					for (int i = 0; i < this->size; i++) {
						this->pile[i].setFaceUp(false);
						this->pile[i].setTop(false);
					}
					this->top = i;
					this->pile[top].setFaceUp(true);
					this->pile[top].setTop(true);
					break;
				}
			}
		}
	}
}

PlayingCard PileofCards::Remove() {
	if (!(this->IsEmpty())) {
		PlayingCard temp = this->pile[top];
		//int temp = top;
		//pile[top] = PlayingCard();
		pile[top] = NULL;
		this->top--;
		if (top != -1) {
			pile[top].setFaceUp(true);
			pile[top].setTop(true);
		}
		//return pile[temp];
		return temp;
	}
	return PlayingCard();
}

PlayingCard PileofCards::peek() {
	return this->pile[top];
}

bool PileofCards::IsEmpty() {
	if (this->top == -1) {
		//cout << "Pile is Empty...." << endl;
		return true;
	}
	return false;
}

bool PileofCards::IsFull() {
	if (this->top == this->size - 1) {
		cout << "The Pile is Full..." << endl;
		return true;
	}
	return false;
}

int PileofCards::getTop() {
	return this->top;
}

PlayingCard PileofCards::getTopCard() {
	if (this->getTop() != -1) {
		return this->pile[this->getTop()];
	}
	return PlayingCard();
}

void PileofCards::setTop() {
	this->pile[top].setTop(true);
	this->pile[top].setFaceUp(true);
}

point PileofCards::getstartPt() {
	return this->startPt;
}

point PileofCards::getEndPt() {
	return this->endPt;
}

void PileofCards::setStartPt(point P) {
	this->startPt = P;
}

void PileofCards::setEndPt(point P) {
	this->endPt = P;
}

PileofCards& PileofCards::operator=(const PileofCards& Obj) {
	if (this == &Obj) {
		return *this;
	}
	if (this != NULL) {
		delete this->pile;
	}
	this->size = Obj.size;
	this->pile = new PlayingCard[this->size];
	for (int i = 0; i < this->size; i++) {
		this->pile[i] = Obj.pile[i];
	}
	return *this;
}

PlayingCard PileofCards::viewCard(int i) {
	return this->pile[i];
}

void PileofCards::SimpleDisplay() {
	if (this->top != -1) {
		this->pile[top].Display(startPt.y, startPt.x);
	}
	else {
		PlayingCard temp;
		temp.Display(startPt.y, startPt.x);
	}
}

void PileofCards::CascadingDisplay() {
	if (this->top != -1) {
		//int row = 10;
		//this->pile[top].Display(startPt.y, startPt.x);
		startPt.x += 2;
		for (int i = 0; i < this->size; i++) {
			if (this->pile[i].getRank() != 0) {
				//this->pile[i].Display(10, row);
				this->pile[i].Display(startPt.y, startPt.x);
				//row += 2;
				startPt.x += 2;
			}
		}
	}
	else {
		PlayingCard temp;
		temp.Display(startPt.y, startPt.x);
	}
}

void PileofCards::setSize(int size) {
	this->size = size;
	this->pile = new PlayingCard[size];
}

PileofCards::~PileofCards() {
	if (this->pile != nullptr) {
		delete[] pile;
	}
}