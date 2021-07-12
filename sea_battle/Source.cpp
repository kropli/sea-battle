﻿//      растваление кораблей
//      хард режим для бота


//                               mass   [y][x]
//                  система  0 - пустое поле     1 - часть корабля  * - подбитая часть корабля 
//                  визуал       " "                     #                       *
#include <iostream> 
#include <cstring>
#include <string>

using namespace std;
enum next_side {
	Left,Right,Up,Down
};
int convert_let_to_num(char letter) {
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

int convert_num_to_num(char num) {
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

bool _1thship(char sea [10][10], int y, int x) {
	if (sea[y - 1][x] == '0' &&
		sea[y + 1][x] == '0' &&
		sea[y][x - 1] == '0' &&
		sea[y][x + 1] == '0') 
	{                 
		sea[y][x] = '1';
		return true;
	}
	else cout << "you can't place ship here";
}
bool _2thship(char sea[10][10], int y, int x, next_side side) {
	int next_y, next_x;
	switch (side) {
	case Left:
		next_y = y; next_x = x - 1;
		if (sea[y - 1][x] == '0' &&
			sea[y + 1][x] == '0' &&
			sea[y][x - 1] == '0' &&
			sea[y][x + 1] == '0')
		{
			if (sea[next_y - 1][next_x] == '0' &&
				sea[next_y + 1][next_x] == '0' &&
				sea[next_y][next_x - 1] == '0')
			{
				sea[y][x] = '1';
				sea[next_y][next_x] = '1';
				return true;
			}
			else cout << "you can't place ship here";
		}
		else cout << "you can't place ship here";
	case Right:
		next_y = y; next_x = x + 1;
		if (sea[y - 1][x] == '0' &&
			sea[y + 1][x] == '0' &&
			sea[y][x - 1] == '0' &&
			sea[y][x + 1] == '0')
		{
			if (sea[next_y - 1][next_x] == '0' &&
				sea[next_y + 1][next_x] == '0' &&
				sea[next_y][next_x + 1] == '0')
			{
				sea[y][x] = '1';
				sea[next_y][next_x] = '1';
				return true;
			}
			else cout << "you can't place ship here";
		}
		else cout << "you can't place ship here";
	case Up:
		next_y = y + 1; next_x = x;
		if (sea[y - 1][x] == '0' &&
			sea[y + 1][x] == '0' &&
			sea[y][x - 1] == '0' &&
			sea[y][x + 1] == '0')
		{
			if (sea[next_y + 1][next_x] == '0' &&
				sea[next_y][next_x + 1] == '0' &&
				sea[next_y][next_x - 1] == '0')
			{
				sea[y][x] = '1';
				sea[next_y][next_x] = '1';
				return true;
			}
			else cout << "you can't place ship here";
		}
		else cout << "you can't place ship here";
	case Down:
		next_y = y - 1; next_x = x;
		if (sea[y - 1][x] == '0' &&
			sea[y + 1][x] == '0' &&
			sea[y][x - 1] == '0' &&
			sea[y][x + 1] == '0')
		{
			if (sea[next_y - 1][next_x] == '0' &&
				sea[next_y][next_x + 1] == '0' &&
				sea[next_y][next_x - 1] == '0')
			{
				sea[y][x] = '1';
				sea[next_y][next_x] = '1';
				return true;
			}
			else cout << "you can't place ship here";
		}
		else cout << "you can't place ship here";
	}
}
int main() {
	char sea1[10][10];
	
	int x, y;
	string pos, full_cord;         
	char letx, lety;

	int _4th = 1;
	int _3th = 2;
	int _2th = 3;
	int _1th = 4;
	char ship;
	int i = 1;
	while(i <= 10){
		cout << "choose ship(1/2/3/4): "; cin >> ship;

		if (ship == '1' && _1th != 0) {
			_1th--;
			cout << "enter full cordinats: "; cin >> full_cord;
			letx = full_cord[0];
			lety = full_cord[1];
			x = convert_num_to_num(letx);
			y = convert_let_to_num(lety);

			if (_1thship(sea1, y, x)) i++;
		}
		if (ship == '2' && _2th != 0) {
			_2th--;
			cout << "enter full cordinats: "; cin >> full_cord;
			letx = full_cord[0];
			lety = full_cord[1];
			x = convert_num_to_num(letx);
			y = convert_let_to_num(lety);
			cout << "side: "; cin >> pos;
			if (pos == "left"){
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