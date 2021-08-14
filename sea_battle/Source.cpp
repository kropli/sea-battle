#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include "ShipFunctions.h"

using namespace std;

int main() {
	srand(time(0));
	char sea[10][10];    // игровое поле
	MapReset(sea);
	ShipPlacement(sea);

	//while (IsAnyShipAlive(sea)) {
	//	HardBotTurn(sea);
	//}
}




//
//do {
//	PlaceShip()
//}while(ShouldPlaceShips())
// 
//PlaceShip() {
//	Ship ship = RequestShipInfo();
//	string errors = CanPlace(ship);
//	if (errors == "")
//		Place(sea, ship) // Sea; sea.Place(ship)
//	else
//		cout << errors
//}


// extract to Bot file
//bool IsAnyShipAlive(char sea[10][10]) {
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (sea[i][j] == '1') return true;
//		} 
//	}
//	return false;
//}
//int GetShipPosition(char sea[10][10], int ShipsPosition[10][3]) {}
//void HardBotTurn(char sea[10][10]) {
//	int ShipsPosition[10][3];
//
//	int ShotChanse = rand() % 10;
//	if (ShotChanse == 4 || ShotChanse == 7) {
//
//	}
//
//}
// end of extract to Bot file