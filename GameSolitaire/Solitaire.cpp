//Muhammad Taha Amir BITF19A519
#include "Solitaire.h"
#include<ctime>
Solitaire::Solitaire() {
	this->stock.setSize(52);
	this->waste.setSize(52);
	for (int i = 0; i < 4; i++) {
		this->home[i].setSize(13);
	}

	for (int i = 0; i < 7; i++) {
		this->PlayingPile[i].setSize(13);
	}
}

void Solitaire::Shuffle() {
	//int i;
	//while (!DeckofCards.IsEmpty())
	//{
	//	i = rand() % DeckofCards.getSize();
	//	PlayingCard c = DeckofCards.Remove(i);
	//	c.setFaceUp(false);
	//	stock.Add(c);
	//	i++;
	//}
	for (int i = 0; i < 52; i++) {
		PlayingCard c = DeckofCards.Remove(0);
		c.setFaceUp(false);
		stock.Add(c);
	}
}

void Solitaire::dealToPlayingPiles() {
	srand(time(0));
	int max = 13;
	int min = 1;
	int breakpoint = 1;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < breakpoint; j++) {
			PlayingCard p(rand() % (max - min + 1) + min, rand() % 3 + 1);
			p.setFaceUp(false);
			p.setTop(false);
			this->PlayingPile[i].Add(p);
		}
		breakpoint += 1;
	}
	for (int i = 0; i < 7; i++) {
		this->PlayingPile[i].setTop();
	}
}

point Solitaire::getClickedPoint() {
	point p;
	while (true) {
		this->cf.DetectEvent();
		if (this->cf.IsMouseLeftClickEvent(p)){
			break;
		}
	}
	return p;
}

PileofCards* Solitaire::getClickedPile(point p, int& a, int& c) {
	PileofCards* temp;
	if (p.y >= 0 && p.y <=5 && p.x >= 20 && p.x<=27) {
		temp = &this->stock;
		return temp;
	}
	else if (p.y >= 0 && p.y <= 5 && p.x >= 30 && p.x <= 37) {
	    temp = &this->waste;
		return temp;
	}
	else if (p.y >= 0 && p.y <= 5 && p.x >= 50 && p.x <= 57) {
		temp = &this->home[0];
		return temp;
	}
	else if (p.y >= 0 && p.y <= 5 && p.x >= 60 && p.x <= 67) {
		temp = &this->home[1];
		return temp;
	}
	else if (p.y >= 0 && p.y <= 5 && p.x >= 70 && p.x <= 77) {
		temp = &this->home[2];
		return temp;
	}
	else if (p.y >= 0 && p.y <= 5 && p.x >= 80 && p.x <= 87) {
		temp = &this->home[3];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 20 && p.x <= 27) {
		temp = &this->PlayingPile[0];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 30 && p.x <= 37) {
		temp = &this->PlayingPile[1];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 40 && p.x <= 47) {
		temp = &this->PlayingPile[2];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 50 && p.x <= 57) {
		temp = &this->PlayingPile[3];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 60 && p.x <= 67) {
		temp = &this->PlayingPile[4];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 70 && p.x <= 77) {
		temp = &this->PlayingPile[5];
		return temp;
	}
	else if (p.y >= 8 && p.y <= 50 && p.x >= 80 && p.x <= 87) {
		temp = &this->PlayingPile[6];
		return temp;
	}
}

void Solitaire::moveFromWasteToHome(int a) {
	if (!this->waste.IsEmpty()) {
		PlayingCard temp;
		//temp = this->waste.getTopCard();
		temp = this->waste.Remove();
		this->home[a].Add(temp);
		//temp.setFaceUp(true);
		//for (int i = 0; i < 13; i++) {
		//	if (this->home[a][i].getSuit() == 0) {
		//		this->home[a][i] = temp;
		//		break;
		//	}
		//}
	}
}

void Solitaire::moveFromStock() {
	if (this->waste.IsEmpty()) {
		if (this->stock.getTop() != -1) {
			PlayingCard temp;
			//temp = this->stock.getTopCard();
			temp = this->stock.Remove();
			this->waste.Add(temp);
			//for (int i = 0; i < 52; i++) {
			//	if (this->waste[i].getSuit() == 0) {
			//		this->waste[i] = temp;
			//		break;
			//	}
			//}
		}
	}
	else if (this->stock.IsEmpty()) {
		//temp = this->waste.getTopCard();
		for (int i = 0; i < 52; i++) {
			PlayingCard temp;
			temp = this->waste.Remove();
			temp.setFaceUp(false);
			if (this->stock[i].getSuit() == 0) {
				this->stock[i] = temp;
			}
		}
	}
}

void Solitaire::moveFromWasteToPlayingPile(int a, int c) {
	if (c == this->PlayingPile[a].getTop()) {
		if (!this->waste.IsEmpty()) {
			PlayingCard temp;
			//temp = this->waste[this->waste.getTop()];
			temp = this->waste.Remove();
			this->PlayingPile[a].Add(temp);
			//for (int i = 0; i < 13; i++) {
			//	if (this->PlayingPile[a][i].getSuit() == 0) {
			//		this->PlayingPile[a].Add(temp);
			//		break;
			//	}
			//}
		}
	}
}

void Solitaire::moveFromPlayingPileToHome(int a, int b, int c) {
	if (c == this->PlayingPile[a].getTop()) {
		PlayingCard temp;
		temp = this->PlayingPile[a].Remove();
		this->home[b].Add(temp);
		//temp = this->PlayingPile[a].getTopCard();
		//this->PlayingPile[a][this->PlayingPile->getTop()] = NULL;
		//if (!this->home[b].IsEmpty()) {
		//	for (int i = 0; i < 13; i++) {
		//		if (this->home[b][i].getSuit() == 0) {
		//			this->home[b].Add(temp);
		//		}
		//	}
		//}
	}
}

void Solitaire::moveFromHomeToPlyingPile(int a, int b, int c) {
	if (c == this->PlayingPile[b].getTop()) {
		PlayingCard temp;
		temp = this->home[a].Remove();
		this->PlayingPile[b].Add(temp);
		//PlayingCard temp = this->home[a].getTopCard();
		//if (!this->PlayingPile[b].IsEmpty()) {
		//	for (int i = 0; i < 13; i++) {
		//		if (this->PlayingPile[b][i].getSuit() == 0) {
		//			this->PlayingPile[b].Add(temp);
		//		}
		//	}
		//}
	}
}

void Solitaire::moveFromPlayingPileToPlayingPile(int a, int b, int c1, int c2) {
	if (c2 == this->PlayingPile[b].getTop()) {
		if (c1 == this->PlayingPile[a].getTop()) {
			PlayingCard temp;
			temp = this->PlayingPile[a].Remove();
			this->PlayingPile[a].Add(temp);
		}
	}
}

void Solitaire::Play() {
	while (true) {
		srand(time(0));
		point p1 = getClickedPoint();
		int a = -1; int c = -1;
		PileofCards* firstPile = getClickedPile(p1, a, c);
		if (firstPile == &this->stock) {
			cf.SetCursorAt(0, 0);
	        moveFromStock();
	        system("cls");
			cout << "stock Clicked!";
	        DisplayGame();
		}
		else if (firstPile == &this->waste) {
			cf.SetCursorAt(0, 0);
			moveFromWasteToHome(rand()% 3+1);
			system("cls");
			cout << "Waste Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->home[0]) {
			int PlayingPile = rand() % 7;
			int PileTop = this->PlayingPile[PlayingPile].getTop();
			cf.SetCursorAt(0, 0);
			moveFromHomeToPlyingPile(0,PlayingPile, PileTop);
			system("cls");
			cout << "Home1 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->home[1]) {
			int PlayingPile = rand() % 7;
			int PileTop = this->PlayingPile[PlayingPile].getTop();
			cf.SetCursorAt(0, 0);
			moveFromHomeToPlyingPile(1,PlayingPile,PileTop);
			system("cls");
			cout << "Home2 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->home[2]) {
			int PlayingPile = rand() % 7;
			int PileTop = this->PlayingPile[PlayingPile].getTop();
			cf.SetCursorAt(0, 0);
			moveFromHomeToPlyingPile(2, PlayingPile, PileTop);
			system("cls");
			cout << "Home3 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->home[3]) {
			int PlayingPile = rand() % 7;
			int PileTop = this->PlayingPile[PlayingPile].getTop();
			cf.SetCursorAt(0, 0);
			moveFromHomeToPlyingPile(3, PlayingPile, PileTop);
			system("cls");
			cout << "Home4 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[0]) {
			int PileTop = this->PlayingPile[0].getTop();
			cf.SetCursorAt(0, 0);
			cout << PileTop;
			moveFromPlayingPileToHome(0, rand() % 4, PileTop);
			system("cls");
			cout << "Pile1 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[1]) {
			int PileTop = this->PlayingPile[1].getTop();
			cf.SetCursorAt(0, 0);
			moveFromPlayingPileToHome(1, rand() % 4, PileTop);
			system("cls");
			cout << "Pile2 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[2]) {
			int PileTop = this->PlayingPile[2].getTop();
			cf.SetCursorAt(0, 0);
			moveFromPlayingPileToHome(2, rand() % 4, PileTop);
			system("cls");
			cout << "Pile3 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[3]) {
			int PileTop = this->PlayingPile[3].getTop();
			cf.SetCursorAt(0, 0);
			moveFromPlayingPileToHome(3, rand() % 4, PileTop);
			system("cls");
			cout << "Pile4 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[4]) {
			int PileTop = this->PlayingPile[4].getTop();
			cf.SetCursorAt(0, 0);
			moveFromPlayingPileToHome(4, rand() % 4, PileTop);
			system("cls");
			cout << "Pile5 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[5]) {
			int PileTop = this->PlayingPile[5].getTop();
			cf.SetCursorAt(0, 0);
			moveFromPlayingPileToHome(5, rand() % 4, PileTop);
			system("cls");
			cout << "Pile6 Clicked!";
			DisplayGame();
		}
		else if (firstPile == &this->PlayingPile[6]) {
			int PileTop = this->PlayingPile[6].getTop();
			cf.SetCursorAt(0, 0);
			moveFromPlayingPileToHome(6, rand() % 4, PileTop);
			system("cls");
			cout << "Pile7 Clicked!";
			DisplayGame();
		}
		else {
		cf.SetCursorAt(0, 0);
		cout << "Invalid Move";
        }
	}
}

void Solitaire::DisplayGame() {
	point stock;
	stock.x = 0;
	stock.y = 20;
	this->stock.setStartPt(stock);

	point waste;
	waste.x = 0;
	waste.y = 30;
	this->waste.setStartPt(waste);

	point home;
	home.x = 0;
	home.y = 50;
	for (int i = 0; i < 4; i++) {
		this->home[i].setStartPt(home);
		home.y += 10;
	}

	point playingPilestart;
	playingPilestart.x = 8;
	playingPilestart.y = 20;

	for (int i = 0; i < 7; i++) {
		this->PlayingPile[i].setStartPt(playingPilestart);
		playingPilestart.y += 10;
	}
	this->stock.SimpleDisplay();

	this->waste.SimpleDisplay();

	for (int i = 0; i < 4; i++) {
		this->home[i].SimpleDisplay();
	}

	for (int i = 0; i < 7; i++) {
		this->PlayingPile[i].CascadingDisplay();
	}
}