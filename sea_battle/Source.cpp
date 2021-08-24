#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <random>
#include <map>
#include "ShipFunctions.h"
#include "BotFunctions.h"

using namespace std;

int main() {
	char TestSea[10][10] = {
	 {'1','0','0','1','1','0','0','0','1','0'},
	 {'0','0','0','0','0','0','0','0','0','0'},
	 {'0','1','1','1','1','0','1','0','0','0'},
	 {'0','0','0','0','0','0','1','0','0','0'},
	 {'0','0','0','0','0','0','0','0','0','0'},
	 {'0','0','0','1','0','0','0','0','0','0'},
	 {'0','1','0','1','0','0','0','1','1','0'},
	 {'0','0','0','1','0','0','0','0','0','0'},
	 {'0','1','0','0','0','0','0','0','0','0'},
	 {'0','0','0','0','0','0','0','1','0','0'}
	};
	srand(time(NULL));
	//char sea[10][10];    // игровое поле
	//MapReset(sea);
	//ShipPlacement(sea);
	while (IsAnyShipAlive) {
		string test;
		cin >> test;
		BotTurn;
		Show(TestSea);
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