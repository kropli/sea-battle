#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

std::map<int, int> shipCount;

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
void MapView(char sea[10][10]) {
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

	shipCount[ship.length]--;
}
void CheckAndPlaceShip(char sea[10][10], Ship ship, int* placementCount) {
	if (ShipPlacementCheck(sea, ship)) { ShipPlace(sea, ship); placementCount++; }
}

void EnterInfo(Ship* shipInfo, int shipLength) {
	string full_cord;
	char letx, lety;
	int ShipCount = shipCount[shipLength];

	if (ShipCount > 0) {
		cout << "enter left corner cordinats: "; cin >> full_cord;
		letx = full_cord[0];
		lety = full_cord[1];
		shipInfo->x = ConvertNumToNum(letx);
		shipInfo->y = ConvertLetToNum(lety);
		shipInfo->length = shipLength;
		if (shipLength != '1') { cout << "position: "; cin >> shipInfo->position; }
	}
}

void ShipPlacement(char sea[10][10]) {
	Ship shipInfo[10];
	int ShipPlacementCount = 0;
	int ship;
	shipCount[1] = 4;
	shipCount[2] = 3;
	shipCount[3] = 2;
	shipCount[4] = 1;

	while (ShipPlacementCount < 10) {
		MapView(sea);
		cout << "choose ship(1/2/3/4): "; cin >> ship;

		EnterInfo(&shipInfo[ShipPlacementCount], ship);
		CheckAndPlaceShip(sea, shipInfo[ShipPlacementCount], &ShipPlacementCount);
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

int main() {
	srand(time(NULL));
	char sea[10][10];    // игровое поле
	MapReset(sea);
	ShipPlacement(sea);

	while (IsAnyShipAlive(sea)) {
		HardBotTurn(sea);
	}
	
}