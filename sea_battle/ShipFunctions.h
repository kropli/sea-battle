#pragma once
#include <string>
#ifndef FunctionsForShip
#define FunctionsForShip

struct Ship {
	int y;
	int x;
	int length;
	std::string position = "";
};

int ConvertLetToNum(char letter);
int ConvertNumToNum(char num);
void MapReset(char sea[10][10]);
void Show(char sea[10][10]);
bool CanShipBePlacedHere(int y, int x, char sea[10][10]);
std::string CanPlaceShip(char sea[10][10], Ship ship);
void PlaceShip(char sea[10][10], Ship ship);
Ship GetShipInfo();
bool ShouldPlaceShips();
void ShipPlacement(char sea[10][10]);
#endif 

