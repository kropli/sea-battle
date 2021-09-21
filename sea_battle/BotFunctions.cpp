#include <iostream>
#include <string>
#include <random>
#include <vector>
#include<time.h>
using namespace std;
bool UnfinishedShip = false;   // переменная для незаконченного корабля(если бот попадет не в одинарный и надо будет продолжить добивать этот корабль)
bool SecondPart = false;  //  переменная для обозначения можно ли пойти в две стороны чтобы его убить
const char ShipCell = '1';  // константа для клетки корабля
const char EmptyCell = '0';  //  константа для пустой клетки
const char DamagedShipCell = '2'; // константа для подбитой клетки корабля
int UnfinishedCordY;  // кордината для клетки корабля в которую попали в прошлый ход
int UnfinishedCordX;  //  кордината для клетки корабля в которую попали в прошлый ход
int Answers[100][2];    //массив для записей ходов 
int UsedCord[100][2]; // массив для уже использованых кординат

int AnswerCount = 0; // счет хода для аписи в массив
int PossiblePositions[2][2]; // массив для записи возможных кординат продолжения корабля 

bool CordInMass(int y, int x) {   
	// функция для проверки есть ли кордината в массиве
	for (auto i : UsedCord) {      
		if (i[0] == y && i[1] == x) {
			return false;
			/*cout << "cord" << y << " " << x << "are used" << endl;*/
		}
	}
	return true;
}

bool IsAnyShipAlive(char sea[10][10]) {  
	// функция для проверки есть ли еще живые корабли на поле
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (sea[i][j] == '1') return true;
		}
	}
	return false;
}

bool IsAnyShipPartHere(int y, int x, char sea[10][10], int PossiblePositions[2][2]) { 
	// функция для проверки есть ли возле уже подбитой клетки еще одна клетка корабля
	int GetShipPart = 0;
	SecondPart = false;
	for (int yi = -1; yi <= 1; yi++)
		for (int xi = -1; xi <= 1; xi++)
			if (sea[y + yi][x + xi] == ShipCell) {
				if (SecondPart == false) {
					PossiblePositions[0][0] = y + yi;
					PossiblePositions[0][1] = x + xi;
					GetShipPart = 1;
					SecondPart = true;
				}
				else {
					PossiblePositions[1][0] = y + yi;
					PossiblePositions[1][1] = x + xi;
					GetShipPart = 1;
				}
			}

	return GetShipPart;
}
void WriteAnswer(int y,int x, int RandomY = 0, int RandomX = 0) { 
	// функция для записи ходов
	Answers[AnswerCount][0] = y + RandomY;
	Answers[AnswerCount][1] = x + RandomX;
	cout << Answers[AnswerCount][0] + 1 << " = answer y " << Answers[AnswerCount][1] + 1 << " = answer x" << endl;
	UsedCord[AnswerCount + 1][0] = Answers[AnswerCount][0];
	UsedCord[AnswerCount + 1][1] = Answers[AnswerCount][1];
}
void TryingToHitShipRandom(char sea[10][10]) {
	// функция для возможного попадания по кораблю
		/*cout << "dont get random chance" << endl;*/
		int RandomCellX = 0;
		int RandomCellY = 0;
		do {
			retry:
			RandomCellX = rand() % 3 - 1;
			RandomCellY = rand() % 3 - 1;
			if (RandomCellX == 0 && RandomCellY == 0) goto retry;
		} while (RandomCellX + UnfinishedCordX != PossiblePositions[0][1] &&
			RandomCellY + UnfinishedCordY != PossiblePositions[0][0]);
		WriteAnswer(UnfinishedCordY, UnfinishedCordX, RandomCellY, RandomCellX);
}
void HitShip(char sea[10][10], int ShipPart) {
	// функция с гарантированым попаданием по кораблю
	/*cout << "get random chance" << endl;*/
	sea[PossiblePositions[0][0]][PossiblePositions[0][1]] = DamagedShipCell;
	if (ShipPart == 1 ) WriteAnswer(PossiblePositions[0][0], PossiblePositions[0][1]);
	else if (ShipPart == 2)  WriteAnswer(PossiblePositions[1][0], PossiblePositions[1][1]);
}


void BotTurn(char sea[10][10]) {
	// основная функци яхода бота
	if (AnswerCount == 0) { UsedCord[0][0] = 15; UsedCord[0][1] = 15; }
	srand(time(NULL));
	int x, y;
	if (UnfinishedShip) {
		// если корабль был подюит в прошлом ходу
		cout << UnfinishedCordY + 1<< " " << UnfinishedCordX+ 1 << endl;

		if (IsAnyShipPartHere(UnfinishedCordY, UnfinishedCordX, sea, PossiblePositions)) {
			// если соседней клеткой является клетка корабля
			int random = rand() % 10;
			if (UnfinishedCordY != PossiblePositions[0][0] || UnfinishedCordX != PossiblePositions[0][1]) {
				// если эта клетка не была крайней левой
				cout << "left(top) end" << endl;

				if (random > 5) { HitShip(sea, 1); }
				else { TryingToHitShipRandom(sea); }
			}
			else if (SecondPart == true) {
				// если бот дошел до крайней левой и есть возможность пойти в парво
				int random = rand() % 10;
				UnfinishedCordY = PossiblePositions[1][0];
				UnfinishedCordX = PossiblePositions[1][1];

				cout << "going right(down)" << endl;
				if (random > 5) { HitShip(sea, 2); }
				else { TryingToHitShipRandom(sea); }
			}
		}
		else {UnfinishedShip = false; }
	}
	else {
		//если в прошлом ходу небыл подбит корабль
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (!CordInMass(y, x));

		if (sea[y][x] == ShipCell) {
			// если бот рандомно попал по кораблю
			UnfinishedShip = true;
			UnfinishedCordY = y;
			UnfinishedCordX = x;
			sea[y][x] = DamagedShipCell;
			WriteAnswer(y, x);
		}
		else {
			WriteAnswer(y, x);
		}

	}
	AnswerCount++;
}
