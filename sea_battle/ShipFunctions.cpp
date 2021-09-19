#include <iostream>
#include <string>
#include <map>
using namespace std;

const char ShipCell = '1';
const char EmptyCell = ' ';

map<int, int> shipsLeftToPlace;
struct Ship {
	int y;
	int x;
	int length;
	std::string position = "";
};

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
			sea[i][j] = EmptyCell;
		}
	}
}
void Show(char sea[10][10]) {
	char letter;
	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 0; i < 10; i++) {
		letter = 65 + i;
		cout << letter << " ";
		for (int j = 0; j < 10; j++) {
			cout << sea[i][j] << " ";
		}
		cout << endl;
	}
}

bool CanShipPartBePlacedHere(int y, int x, char sea[10][10]) {
	for (int yi = -1; yi <= 1; yi++)
		for (int xi = -1; xi <= 1; xi++)
			if (sea[y + yi][x + xi] == ShipCell)
				return false;
	return true;
}
bool CanPlaceShip(char sea[10][10], Ship ship) {
	bool canPlace;
	for (int i = 0; i < ship.length; i++) {
		if (ship.position == "horizontal")
			canPlace = CanShipPartBePlacedHere(ship.y, ship.x + i - 1, sea);
		else
			canPlace = CanShipPartBePlacedHere(ship.y + i, ship.x - 1, sea);

		if (!canPlace) {
			cout << "you can't place ship here" << endl;
			return false;
		}
	}
	return true;
}
void PlaceShip(char sea[10][10], Ship ship) {
	for (int i = 0; i < ship.length; i++) {
		if (ship.position == "horizontal")
			sea[ship.y][(ship.x + i) - 1] = ShipCell;
		else
			sea[ship.y + i][ship.x - 1] = ShipCell;
	}
	shipsLeftToPlace[ship.length]--;
}

Ship GetShipInfo() {
	Ship ship;
	int shipLength;
	cout << "choose ship length (";
	if (shipsLeftToPlace[1] > 0) cout << "1";
	if (shipsLeftToPlace[2] > 0) cout << "/2";
	if (shipsLeftToPlace[3] > 0) cout << "/3";
	if (shipsLeftToPlace[4] > 0) cout << "/4";
	cout << "):";
	cin >> shipLength;
	/*while (shipsLeftToPlace[shipLength] != 0) {	
		if (shipsLeftToPlace[shipLength] == 0) {
			cout << "cannot place ship of this length - max count of such ships already placed" << endl;
		}
		else cout << "-";
	}*/
	
	ship.length = shipLength;
	string full_cord;
	bool CorrectCordinats = false;
	do {
		cout << "enter left corner cordinats, for example 9A: "; cin >> full_cord;
		ship.x = ConvertNumToNum(full_cord[0]);
		ship.y = ConvertLetToNum(full_cord[1]);
		int CordNum = full_cord[0],CordLetter = full_cord[1];
		if (CordNum > 48 && CordNum < 58 && CordLetter > 64 && CordLetter < 91) CorrectCordinats = true;
	} while (!CorrectCordinats);
	
	ship.position = "horizontal";
	if (shipLength != 1) {
		cout << "position: ";
		cin >> ship.position;
	}
	return ship;
}

bool ShouldPlaceShips() {
	for (int shipLength = 1; shipLength <= 4; shipLength++)
	{
		if (shipsLeftToPlace[shipLength] > 0) return true;
	}
	return false;
}
void ShipPlacement(char sea[10][10]) {

	shipsLeftToPlace[1] = 4;
	shipsLeftToPlace[2] = 3;
	shipsLeftToPlace[3] = 2;
	shipsLeftToPlace[4] = 1;

	while (ShouldPlaceShips()) {
		Show(sea);
		Ship ship = GetShipInfo();
		if (CanPlaceShip(sea, ship)) PlaceShip(sea, ship);
	}
}