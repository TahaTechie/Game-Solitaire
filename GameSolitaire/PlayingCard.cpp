//Muhammad Taha Amir BITF19A519
#include "PlayingCard.h"
#include "ConsoleFunctions.h"
#include<io.h>
#include<fcntl.h>

PlayingCard::PlayingCard(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
	if (this->suit == 0 || this->suit == 1) {
		this->color = 'r';
	}
	else {
		this->color = 'b';
	}
	this->faceUp = true;
	this->top = true;
}

void PlayingCard::Display(int x, int y) {
	ConsoleFunctions cf;

	if (this->color == 'r') {
		cf.SetColor(red, white);
	}
	else {
		cf.SetColor(black, white);
	}
	cf.SetCursorAt(x, y);

	if (this->rank != 0) {
		if (this->faceUp == true && this->top == true) {
			for (int col = 0; col < 6; col++) {
				for (int row = 0; row < 8; row++) {
					if (col == 0 && row == 0) {
						if (this->rank / 10 == 0) {
							cout << this->rank;
						}
						else {
							cout << this->rank / 10;
						}
					}
					else if (col == 0 && row == 1) {
						if (this->rank / 10 == 0) {
							if (this->suit == 0) {
								//cout << 'D';
								wstring symbol = L"\u2666";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 1) {
								//cout << 'H';
								wstring symbol = L"\u2665";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 2) {
								//cout << 'S';
								wstring symbol = L"\u2660";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else {
								//cout << 'C';
								wstring symbol = L"\u2663";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
						}
						else {
							cout << this->rank % 10;
						}
					}
					else if (col == 0 && row == 2) {
						if (this->rank / 10 == 0) {
							cout << " ";
						}
						else {
							if (this->suit == 0) {
								//cout << 'D';
								wstring symbol = L"\u2666";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 1) {
								//cout << 'H';
								wstring symbol = L"\u2665";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 2) {
								//cout << 'S';
								wstring symbol = L"\u2660";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else {
								//cout << 'C';
								wstring symbol = L"\u2663";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
						}
					}
					else if (col == 5 && row == 5) {
						if (this->rank / 10 == 0) {
							cout << " ";
						}
						else {
							if (this->suit == 0) {
								//cout << 'D';
								wstring symbol = L"\u2666";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 1) {
								//cout << 'H';
								wstring symbol = L"\u2665";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 2) {
								//cout << 'S';
								wstring symbol = L"\u2660";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else {
								//cout << 'C';
								wstring symbol = L"\u2663";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
						}
					}
					else if (col == 5 && row == 6) {
						if (this->rank / 10 == 0) {
							if (this->suit == 0) {
								//cout << 'D';
								wstring symbol = L"\u2666";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 1) {
								//cout << 'H';
								wstring symbol = L"\u2665";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 2) {
								//cout << 'S';
								wstring symbol = L"\u2660";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else {
								//cout << 'C';
								wstring symbol = L"\u2663";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
						}
						else {
							cout << this->rank / 10;
						}
					}
					else if (col == 5 && row == 7) {
						if (this->rank / 10 == 0) {
							cout << this->rank;
						}
						else {
							cout << this->rank % 10;
						}
					}
					else {
						cout << " ";
					}
				}
				cout << endl;
				y += 1;
				cf.SetCursorAt(x, y);
			}
		}

		else if (this->faceUp == false && this->top == true) {
			cf.SetColor(red, red);
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					cout << " ";
				}
				cout << endl;
				y += 1;
				cf.SetCursorAt(x, y);
			}
		}

		else if (this->faceUp == true && this->top == false) {

			for (int col = 0; col < 2; col++) {
				for (int row = 0; row < 8; row++) {
					if (col == 0 && row == 0) {
						if (this->rank / 10 == 0) {
							cout << this->rank;
						}
						else {
							cout << this->rank / 10;
						}
					}
					else if (col == 0 && row == 1) {
						if (this->rank / 10 == 0) {
							if (this->suit == 0) {
								//cout << 'D';
								wstring symbol = L"\u2666";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 1) {
								//cout << 'H';
								wstring symbol = L"\u2665";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 2) {
								//cout << 'S';
								wstring symbol = L"\u2660";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else {
								//cout << 'C';
								wstring symbol = L"\u2663";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
						}
						else {
							cout << this->rank % 10;
						}
					}
					else if (col == 0 && row == 2) {
						if (this->rank / 10 == 0) {
							cout << " ";
						}
						else {
							if (this->suit == 0) {
								//cout << 'D';
								wstring symbol = L"\u2666";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 1) {
								//cout << 'H';
								wstring symbol = L"\u2665";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else if (this->suit == 2) {
								//cout << 'S';
								wstring symbol = L"\u2660";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
							else {
								//cout << 'C';
								wstring symbol = L"\u2663";
								_setmode(_fileno(stdout), _O_U8TEXT);
								wcout << symbol;
								_setmode(_fileno(stdout), _O_TEXT);
							}
						}
					}
					else if (col == 1) {
						cf.SetColor(blue, white);
						cout << "_";
					}
					else {
						cout << " ";
					}
				}
				cout << endl;
				y += 1;
				cf.SetCursorAt(x, y);
			}
		}

		else if (this->faceUp == false && this->top == false) {
			cf.SetColor(red, red);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 8; j++) {
					if (i == 0) {
						cout << " ";
					}
					else if (i == 1) {
						cf.SetColor(white, red);
						cout << "_";
					}
				}
				cout << endl;
				y += 1;
				cf.SetCursorAt(x, y);
			}
		}
	}
	else {
		cf.SetColor(dark_green, dark_green);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 8; j++) {
				cout << " ";
			}
			cout << endl;
			y += 1;
			cf.SetCursorAt(x, y);
		}
	}
}

int PlayingCard::getRank() {
	return this->rank;
}

int PlayingCard::getSuit() {
	return this->suit;
}

bool PlayingCard::isFaceUp() {
	return this->faceUp;
}

void PlayingCard::setFaceUp(bool value) {
	this->faceUp = value;
}

bool PlayingCard::isTop() {
	return this->top;
}

void PlayingCard::setTop(bool value) {
	this->top = value;
}

char PlayingCard::getColor() {
	return this->color;
}