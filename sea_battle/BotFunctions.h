#pragma once
#include <string>
#ifndef FunctionsForBot
#define FunctionsForBot

bool IsAnyShipAlive(char sea[10][10]);
void BotTurn(char sea[10][10]);
bool IsAnyShipPartHere(int y, int x, char sea[10][10], int PossiblePositions[2][2]);

#endif 
