//Muhammad Taha Amir BITF19A519
#include "Deck.h"
#include<iostream>
using namespace std;

Deck::Deck() {
	this->size = 52;
	int D = 1, H = 1, S = 1, C = 1;
	for (int i = 0; i < size; i++) {
		if (i >= 0 && i < 13) {
			this->deck[i] = new PlayingCard(D, PlayingCard::Daimond);
			D++;
		}
		else if (i >= 13 && i < 26) {
			this->deck[i] = new PlayingCard(H, PlayingCard::Heart);
			H++;
		}
		else if (i >= 26 && i < 39) {
			this->deck[i] = new PlayingCard(S, PlayingCard::Spade);
			S++;
		}
		else {
			this->deck[i] = new PlayingCard(C, PlayingCard::Club);
			C++;
		}
	}
}

int Deck::getSize() {
	return this->size;
}

PlayingCard Deck::Remove(int value) {
	PlayingCard* temp;
	int BreakPoint = 0;
	if (value >= 0 && value < 52) {
		for (int i = 0; i < 52; i++) {
			if (i == value) {
				BreakPoint = i;
			}
		}
		for (int j = BreakPoint; j < 52; j++) {
			if (j >= BreakPoint && j < 51) {
				swap(this->deck[j], this->deck[j + 1]);
			}
			if (j == 51) {
				temp = this->deck[j];
				this->deck[j] = NULL;
				if (temp != NULL) {
					return *temp;
				}
				else {
					return PlayingCard();
				}
			}
		}
	}
	cout << "invalid value\n";
	return PlayingCard();
}

bool Deck::IsEmpty() {
	int flag = 0;
	for (int i = 0; i < 52; i++) {
		if (this->deck[i] != NULL) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		return true;
	}
	else {
		return false;
	}
}

Deck::~Deck() {
	for (int i = 0; i < size; i++) {
		delete deck[i];
	}
}