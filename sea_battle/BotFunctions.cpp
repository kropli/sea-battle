#include <iostream>
#include <string>
#include <random>
using namespace std;
bool UnfinishedShip = false;   // переменная для незаконченного корабля(если бот попадет не в одинарный и надо будет продолжить добивать этот корабль)
bool SecondPart = false;
const char ShipCell = '1';
const char EmptyCell = '0';
const char DamagedShipCell = '2';
int UnfinishedCordY;
int UnfinishedCordX;
int Answers[100][2] = {};    //массив для записей ходов 
int AnswerCount = 0;
int PossiblePositions[2][2];
int CellsForGettingDirection = 2;

bool IsAnyShipAlive(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (sea[i][j] == '1') return true;
		} 
	}
	return false;
}

bool IsAnyShipPartHere(int y, int x, char sea[10][10], int PossiblePositions[2][2]) {
	int count = -1;
	for (int yi = -1; yi <= 1; yi++)
		for (int xi = -1; xi <= 1; xi++)
			if (sea[y + yi][x + xi] == ShipCell) {
				count++;
				PossiblePositions[count][0] = y + yi;
				PossiblePositions[count][1] = x + xi;				
			}
	if (count == 1) { SecondPart = true; }
	if (count == -1) { return false; }
	else return true;
}
void BotTurn(char sea[10][10]) {  // пока что просто логику накидаю  на функции буду потом разбивать
	int x, y;
	if (UnfinishedShip) {
		if (IsAnyShipPartHere(UnfinishedCordY, UnfinishedCordX, sea, PossiblePositions)) {
			if (UnfinishedCordY != PossiblePositions[0][0] && UnfinishedCordX != PossiblePositions[0][1]) {
				//  если не дошли до левого края корябля
				if (CellsForGettingDirection > 0) {
					int random = rand() % 10;
					if (random == 1 || random == 7) {
						Answers[AnswerCount][0] = PossiblePositions[0][0];
						Answers[AnswerCount][1] = PossiblePositions[0][1];
						CellsForGettingDirection--;
						AnswerCount++;    // убрать answercount  и вынести в конец
						cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
					}
					else {
						int RandomCellX = 0;
						int RandomCellY = 0;
						do {
							int RandomCellX = rand() % 2 - 1;
							int RandomCellY = rand() % 2 - 1;
						} while (RandomCellX + UnfinishedCordX != PossiblePositions[0][1] &&
							RandomCellY + UnfinishedCordY != PossiblePositions[0][0]);
						// нужно будет добавить логику с проверкой второй возможной кординатой если она есть

						Answers[AnswerCount][0] = UnfinishedCordY + RandomCellY;
						Answers[AnswerCount][1] = UnfinishedCordX + RandomCellX;
						CellsForGettingDirection--;
						AnswerCount++;
						cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
					}
				}
				else {
					Answers[AnswerCount][0] = PossiblePositions[0][0];
					Answers[AnswerCount][1] = PossiblePositions[0][1];
					CellsForGettingDirection--;
					AnswerCount++;
					cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
				}

			}
			else if (SecondPart == true) {  // если помимо левого края можно пойти в право
				if (CellsForGettingDirection > 0) {
					int random = rand() % 10;
					if (random == 1 || random == 7) {
						Answers[AnswerCount][0] = PossiblePositions[1][0];
						Answers[AnswerCount][1] = PossiblePositions[1][1];
						CellsForGettingDirection--;
						AnswerCount++;
						cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
					}
					else {
						int RandomCellX = 0;
						int RandomCellY = 0;
						do {
							int RandomCellX = rand() % 2 - 1;
							int RandomCellY = rand() % 2 - 1;
						} while (RandomCellX + UnfinishedCordX != PossiblePositions[1][1] &&
							RandomCellY + UnfinishedCordY != PossiblePositions[1][0]);
						// нужно будет добавить логику с проверкой второй возможной кординатой если она есть

						Answers[AnswerCount][0] = UnfinishedCordY + RandomCellY;
						Answers[AnswerCount][1] = UnfinishedCordX + RandomCellX;
						CellsForGettingDirection--;
						AnswerCount++;
						cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
					}
				}
				else {
					Answers[AnswerCount][0] = PossiblePositions[0][0];
					Answers[AnswerCount][1] = PossiblePositions[0][1];
					CellsForGettingDirection--;
					AnswerCount++;
					cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
				}
			}
		}
		else { UnfinishedShip = false; }
	}
	else {
		CellsForGettingDirection = 2;
		x = rand() % 10;
		y = rand() % 10;
		if (sea[y][x] == ShipCell) {
			UnfinishedShip = true;
			UnfinishedCordY = y;
			UnfinishedCordX = x;
			sea[y][x] = DamagedShipCell;
			Answers[AnswerCount][0] = y; 
			Answers[AnswerCount][1] = x;
			CellsForGettingDirection--;
			cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
		}
		else { 
			Answers[AnswerCount][0] = y; 
			Answers[AnswerCount][1] = x; 
			cout << Answers[AnswerCount][0] << " " << Answers[AnswerCount][1] << endl;
		}
	AnswerCount++;
	}
}