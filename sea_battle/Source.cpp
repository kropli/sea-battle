﻿#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

std::map<int, int> shipsLeftToPlace;

struct Ship {
	int y;
	int x;
	int length;
	string position = "";
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
			sea[i][j] = '0';
		}
	}
}
void Show(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << sea[i][j] << " ";
		}
		cout << endl;
	}
}

bool CanPlaceShip(int y, int x, char sea[10][10]) {
	for (int yi = -1; yi <= 1; yi++)
		for (int xi = -1; xi <= 1; xi++)
			if (sea[y + yi][x + xi] == '1')
				return false;
	return true;
}
bool ShipPlacementCheck(char sea[10][10],Ship ship) { 
	
	for (int i = 0; i < ship.length; i++) {
		if (ship.position == "horizontal") {
			if (!CanPlaceShip(ship.y, ship.x + i - 1, sea)) { cout << "you can't place ship here" << endl; return false; }
		}
		else if (ship.position == "vertical") {
			if (!CanPlaceShip(ship.y + i, ship.x - 1, sea)) { cout << "you can't place ship here" << endl; return false; }
		}
		else {  // пока еще думаю как можно сократить эту строчу(либо чтобы ее вообще не писать)
			if (!CanPlaceShip(ship.y, ship.x - 1, sea)) { cout << "you can't place ship here" << endl; return false; }
		}
	}
	return true;
} 
void ShipPlace(char sea[10][10], Ship ship) {
	for (int i = 0; i < ship.length; i++) {
		if (ship.position == "horizontal") { sea[ship.y][(ship.x + i) - 1] = '1';}
		else if (ship.position == "vertical") { sea[ship.y + i][ship.x - 1] = '1';}
		else sea[ship.y][ship.x - 1] = '1';
	}

	shipsLeftToPlace[ship.length]--;
}
void CheckAndPlaceShip(char sea[10][10], Ship ship, int* placementCount) {
	if (ShipPlacementCheck(sea, ship)) { ShipPlace(sea, ship); placementCount++; }
}

Ship GetShipInfo() {
	Ship ship;
	int shipLength;
	cout << "choose ship length (1/2/3/4): "; cin >> shipLength;

	if (shipsLeftToPlace[shipLength] == 0) {
		cout << "cannot place ship of this length - max count of such ships already placed";
		return ship;
	}
	ship.length = shipLength;
	string full_cord;
	cout << "enter left corner cordinats, for example 9A: "; cin >> full_cord;
	ship.x = ConvertNumToNum(full_cord[0]);
	ship.y = ConvertLetToNum(full_cord[1]);
	ship.position = "horizontal";
	if (shipLength != '1') { 
		cout << "position: ";
		cin >> ship.position;
	}
	return ship;
}

void ShipPlacement(char sea[10][10]) {
	Ship ships[10]; // use list? 
	// https://appdividend.com/2019/06/12/cpp-list-tutorial-with-example-list-in-c-standard-template-library-stl/

	int ShipPlacementCount = 0;
	shipsLeftToPlace[1] = 4;
	shipsLeftToPlace[2] = 3;
	shipsLeftToPlace[3] = 2;
	shipsLeftToPlace[4] = 1;

	while (ShipPlacementCount < 10) {
		Show(sea);
		Ship ship = GetShipInfo();
		if (ship.position == "") continue;
		CheckAndPlaceShip(sea, ship, &ShipPlacementCount);
	} 
}

// extract to Bot file
bool IsAnyShipAlive(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (sea[i][j] == '1') return true;
		}
	}
	return false;
}
int GetShipPosition(char sea[10][10], int ShipsPosition[10][3]) {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (sea[y][x] == '1') {
				for (int k = 0; k < 10; k++){
					if (ShipsPosition[k][1] != sea[y][x] && ShipsPosition[k][2] != sea[y][x]) {
						 
					}
				}
				
			}
		}
	}
	return 0;
}
void HardBotTurn(char sea[10][10]) {
	int ShipsPosition[10][3];

	int ShotChanse = rand() % 10;
	if (ShotChanse == 4 || ShotChanse == 7) {

	}

}
// end of extract to Bot file

int main() {
	srand(time(NULL));
	char sea[10][10];    // игровое поле
	MapReset(sea);
	ShipPlacement(sea);

	while (IsAnyShipAlive(sea)) {
		HardBotTurn(sea);
	}
}