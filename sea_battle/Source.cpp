//      расставление кораблей
//      хард режим для бота

//                                       |  -
//                               mass   [y][x]
//                  система  0 - пустое поле     1 - часть корабля  2 - подбитая часть корабля 
//                  визуал       " "                     #                       *
#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

int ConvertLetToNum(char letter) {    //   счет вертикального значения
	switch (letter) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	}
}

int ConvertNumToNum(char num) {    //  счет горизонтального значения
	return num - 48;
}
void MapReset(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			sea[i][j] = '0';
		}
	}
}
void MapView(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << sea[i][j];
		}
		cout << endl;
	}
}
bool CanPlaceShip(int y, int x, char sea[10][10]) {
	for (int yi = -1; yi <= 1; yi++)
		for (int xi = -1; xi <= 1; xi++)
			if (sea[y + yi][x + xi] != '0')
				return false;
	return true;
}

bool PlaceShip(char sea[10][10], int y, int x, int ShipType, string pos = "") {
	bool AllGood = true;
	if (ShipType == 1) {
		if (CanPlaceShip(y, x, sea)) sea[y][x] = '1';
		else {
			cout << "you can't place ship here" << endl;
			return false;
		}
	}
	else if (ShipType == 2) {
		if (pos == "horizontal") {
			for (int i = 0; i < 2; i++) {
				if (!CanPlaceShip(y, x + i, sea)) {
					AllGood = false;
					break;
				}
			}

			if (AllGood) {
				for (int i = 0; i < 2; i++) {
					sea[y][x + i] = '1';
				}
				return true;
			}
			else {
				cout << "you can't place ship here" << endl;
				return false;
			}
		}
		else if (pos == "vertical") {
			for (int i = 0; i < 2; i++) {
				if (!CanPlaceShip(y + i, x, sea)) {
					AllGood = false;
					break;
				}
			}

			if (AllGood) {
				for (int i = 0; i < 2; i++) {
					sea[y + i][x] = '1';
				}
				return true;
			}
			else {
				cout << "you can't place ship here" << endl;
				return false;
			}
		}
	}
	else if (ShipType == 3) {	
		if (pos == "horizontal") {
			for (int i = 0; i < 3; i++) {
				if (!CanPlaceShip(y, x + i, sea)) {
					AllGood = false;
					break;
				}
			}

			if (AllGood) {
				for (int i = 0; i < 3; i++) {
					sea[y][x + i] = '1';
				}
				return true;
			}
			else {
				cout << "you can't place ship here" << endl;
				return false;
			}
		}
		else if (pos == "vertical") {
			for (int i = 0; i < 3; i++) {
				if (!CanPlaceShip(y + i, x, sea)) {
					AllGood = false;
					break;
				}
			}

			if (AllGood) {
				for (int i = 0; i < 3; i++) {
					sea[y + i][x] = '1';
				}
				return true;
			}
			else {
				cout << "you can't place ship here" << endl;
				return false;
			}
		}
	}
	else if (ShipType == 4){
		if (pos == "horizontal") {
			for (int i = 0; i < 4; i++) {
				if (!CanPlaceShip(y, x + i, sea)) {
					AllGood = false;
					break;
				}
			}

			if (AllGood) {
				for (int i = 0; i < 4; i++) {
					sea[y][x + i] = '1';
				}
				return true;
			}
			else {
				cout << "you can't place ship here" << endl;
				return false;
			}
		}
		else if (pos == "vertical") {
			for (int i = 0; i < 4; i++) {
				if (!CanPlaceShip(y + i, x, sea)) {
					AllGood = false;
					break;
				}
			}

			if (AllGood) {
				for (int i = 0; i < 4; i++) {
					sea[y + i][x] = '1';
				}
				return true;
			}
			else {
				cout << "you can't place ship here" << endl;
				return false;
			}
		}
	}
	else {
		cout << "you can't place ship here" << endl;
		return false;
	}
}
void EnterInfo (int *y, int *x,string *pos) {
	string full_cord;
	char letx, lety;
	cout << "enter left corner cordinats: "; cin >> full_cord;
	letx = full_cord[0];
	lety = full_cord[1];
	*x = ConvertNumToNum(letx);
	*y = ConvertLetToNum(lety);
	cout << "position: "; cin >> *pos;
}

void ShipPlacement(char sea[10][10]) {
	int i = 1;
	char ship;
	int x, y;
	string pos, full_cord;
	char letx, lety;
	int _4th = 1;
	int _3th = 2;
	int _2th = 3;
	int _1th = 4;
	
	while (i <= 10) {
		MapView(sea);
		cout << "choose ship(1/2/3/4): "; cin >> ship;

		if (ship == '1' && _1th != 0) {
			cout << "enter cordinats: "; cin >> full_cord;
			letx = full_cord[0];
			lety = full_cord[1];
			x = ConvertNumToNum(letx);
			y = ConvertLetToNum(lety);

			if (PlaceShip(sea, y, x, 1)) {
				i++;
				_1th--;
			};
		}
		if (ship == '2' && _2th != 0) {			
			EnterInfo(&y, &x, &pos);
			if (PlaceShip(sea, y, x, 2, pos)) {
				i++;
				_2th--;
			}
			
		}
		if (ship == '3' && _2th != 0) {
			EnterInfo(&y, &x, &pos);
			if (PlaceShip(sea, y, x, 2, pos)) {
				i++;
				_3th--;
			}

		}
		if (ship == '4' && _2th != 0) {
			EnterInfo(&y, &x, &pos);
			if (PlaceShip(sea, y, x, 2, pos)) {
				i++;
				_4th--;
			}

		}
	}
}
bool IsAnyShipAlive(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (sea[i][j] == '1') return true;
		}
	}
	return false;
}
void HardBotTurn(char sea[10][10]) {
	int ShotChanse = rand() % 4;

}

int main() {
	srand(time(NULL));
	char sea[10][10];    // игровое поле
	MapReset(sea);
	ShipPlacement(sea);
	while (IsAnyShipAlive(sea)) {
		HardBotTurn(sea);
	}
}