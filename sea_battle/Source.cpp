#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <random>
#include <map>
#include "ShipFunctions.h"
#include "BotFunctions.h"

using namespace std;

char TestSea[10][10] = {
 {'1','0','0','1','1','0','0','0','1','0'},
 {'0','0','0','0','0','0','0','0','0','0'},
 {'0','1','1','1','1','0','1','0','0','0'},
 {'0','0','0','0','0','0','1','0','0','0'},
 {'0','0','0','0','0','0','0','0','0','0'},
 {'0','0','0','1','0','0','0','0','0','0'},
 {'0','1','0','1','0','0','0','1','1','0'},
 {'0','0','0','1','0','0','0','0','0','0'},
 {'0','1','0','0','0','0','0','1','0','0'},
 {'0','0','0','1','1','1','0','0','0','0'}
};

int main() {
	Show(TestSea);
	cout << endl << endl;
	srand(time(NULL));
	char Sea[10][10];    // игровое поле
	MapReset(Sea);
	ShipPlacement(Sea);
	while (IsAnyShipAlive(Sea)) {
		string test;
		BotTurn(Sea);
		Show(Sea);
		cout << endl;
		cout << "enter some letter and enter to continue:";
		cin >> test;
	}
	cout << "Bot defeat you at" << AnswerCount << "moves";
	for (int i = 0; i < AnswerCount; i++) {
		cout << Answers[i][0] + 1 << " " << Answers[i][1] + 1 << endl;
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