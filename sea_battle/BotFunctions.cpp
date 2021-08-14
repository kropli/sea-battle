#include <iostream>
#include <string>
using namespace std;

bool IsAnyShipAlive(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (sea[i][j] == '1') return true;
		} 
	}
	return false;
}
void BotTurn(char sea[10][10]) {}