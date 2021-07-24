//      расставление кораблей
//      хард режим для бота

//                                       |  -
//                               mass   [y][x]
//                  система  0 - пустое поле     1 - часть корабля  * - подбитая часть корабля 
//                  визуал       " "                     #                       *
#include <iostream> 
#include <cstring>
#include <string>

using namespace std;
enum next_side {
	Left, Right, Up, Down
};
int ConvertLetToNum(char letter) {    //   счет вертикального значения
	switch (letter) {
	case 'A':
		return 1;
	case 'B':
		return 2;
	case 'C':
		return 3;
	case 'D':
		return 4;
	case 'E':
		return 5;
	case 'F':
		return 6;
	case 'G':
		return 7;
	case 'H':
		return 8;
	case 'I':
		return 9;
	case 'J':
		return 10;
	}
}

int ConvertNumToNum(char num) {    //  счет горизонтального значения
	switch (num) {
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case '10':
		return 10;
	}
}
void MapReset(char sea[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			sea[i][j] = '0';
		}
	}
}
bool CanPlace(int y, int x, char sea[10][10]) {
	return (sea[y - 1][x] == '0' &&
		sea[y - 1][x - 1] == '0' &&
		sea[y][x - 1] == '0' &&
		sea[y + 1][x - 1] == '0' &&
		sea[y + 1][x] == '0' &&
		sea[y + 1][x + 1] == '0' &&
		sea[y][x + 1] == '0' &&
		sea[y - 1][x + 1] == '0' &&
		sea[y][x] == '0');
}

bool _1thship(char sea[10][10], int y, int x) {   // расстановка 1-палубного корабля
	if (CanPlace(y, x, sea)) sea[y][x] = '1';
	else {
		cout << "you can't place ship here";
		return false;
	}

}
bool _2thship(char sea[10][10], int y, int x, next_side side) {  // расстановка 2-палубногоо корабля
	switch (side) {
	case Left:
		if (CanPlace(y, x, sea)) {
			if (CanPlace(y, x - 1, sea)) {
				sea[y][x] = '1';
				sea[y][x - 1] = '1';
				return true;
			}
			else cout << "you can't place ship here";
			return false;
		}
		else cout << "you can't place ship here";
		return false;
	case Right:
		if (CanPlace(y, x, sea)) {
			if (CanPlace(y, x + 1, sea)) {
				sea[y][x] = '1';
				sea[y][x + 1] = '1';
				return true;
			}
			else cout << "you can't place ship here";
			return false;
		}
		else cout << "you can't place ship here";
		return false;
	case Up:
		if (CanPlace(y, x, sea)) {
			if (CanPlace(y + 1, x, sea)) {
				sea[y][x] = '1';
				sea[y + 1][x] = '1';
				return true;
			}
			else cout << "you can't place ship here";
			return false;
		}
		else cout << "you can't place ship here";
		return false;
	case Down:
		if (CanPlace(y, x, sea)) {
			if (CanPlace(y - 1, x, sea)) {
				sea[y][x] = '1';
				sea[y - 1][x] = '1';
				return true;
			}
			else cout << "you can't place ship here";
			return false;
		}
		else cout << "you can't place ship here";
		return false;
	}
}

void ShipPlacement(char sea1[10][10]) {
	int i = 1;
	char ship;
	int x, y;
	string pos, full_cord;
	char letx, lety;
	int _4th = 1;
	int _3th = 2;
	int _2th = 3;
	int _1th = 4;

	while (i <= 10) {
		cout << "choose ship(1/2/3/4): "; cin >> ship;

		if (ship == '1' && _1th != 0) {
			cout << "enter full cordinats: "; cin >> full_cord;
			letx = full_cord[0];
			cout << letx << " ";
			lety = full_cord[1];
			cout << lety << endl;
			x = ConvertNumToNum(letx);
			y = ConvertLetToNum(lety);

			if (_1thship(sea1, y, x)) {
				i++;
				_1th--;
			};
			cout << sea1[y][x] << endl;
			cout << "------" << endl;
		}
		if (ship == '2' && _2th != 0) {
			_2th--;
			cout << "enter full cordinats: "; cin >> full_cord;
			letx = full_cord[0];
			lety = full_cord[1];
			x = ConvertNumToNum(letx);
			y = ConvertLetToNum(lety);
			cout << "side: "; cin >> pos;
			if (pos == "left") {
				if (_2thship(sea1, y, x, Left)) i++;
			}
			if (pos == "right") {
				if (_2thship(sea1, y, x, Right)) i++;
			}
			if (pos == "up") {
				if (_2thship(sea1, y, x, Up)) i++;
			}
			if (pos == "down") {
				if (_2thship(sea1, y, x, Down)) i++;
			}
		}
	}
}

int main() {
	char sea1[10][10];    // игровое поле
	MapReset(sea1);
	ShipPlacement(sea1);
}