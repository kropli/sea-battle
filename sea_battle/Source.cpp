﻿#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <random>
#include <map>
#include "ShipFunctions.h"
#include "BotFunctions.h"

using namespace std;

char sea[10][10] = {
 {'1',' ',' ','1','1',' ',' ',' ','1',' '},
 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
 {' ','1','1','1','1',' ','1',' ',' ',' '},
 {' ',' ',' ',' ',' ',' ','1',' ',' ',' '},
 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
 {' ',' ',' ','1',' ',' ',' ',' ',' ',' '},
 {' ','1',' ','1',' ',' ',' ','1','1',' '},
 {' ',' ',' ','1',' ',' ',' ',' ',' ',' '},
 {' ','1',' ',' ',' ',' ',' ','1',' ',' '},
 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};

int main() {
	cout << endl << endl;
	srand(time(NULL));
	//char sea[10][10];    // игровое поле
	//MapReset(sea);
	//ShipPlacement(sea);
	while (IsAnyShipAlive(sea)) {
		
		//string test;
		//cin >> test;
		BotTurn(sea);
		Show(sea);
		cout << endl;
		getchar();
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