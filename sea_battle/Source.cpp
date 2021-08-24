#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include "ShipFunctions.h"
#include "BotFunctions.h"

using namespace std;

int main() {
	srand(time(0));
	char sea[10][10];    // игровое поле
	MapReset(sea);
	ShipPlacement(sea);
	while (IsAnyShipAlive) {
		BotTurn;
		Show(sea);
		cout << endl;
	}
	
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