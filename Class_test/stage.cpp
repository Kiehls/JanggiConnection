#include "stage.h"

Stage::Stage() {
	host = 0;
	memset(position, 0, sizeof(int) * 2);
	unit = 'n';
	checkMate = 0;
	kill = 0;
}
Stage::Stage(int hostNum, int pos[], char unitState, int check, int killed) {
	host = hostNum;
	memcpy(position, pos, sizeof(int) * 2);
	/*strcpy(unit, unitState);*/
	unit = unitState;
	checkMate = check;
	kill = killed;
}
int Stage::getHost() {
	return host;
}
int* Stage::getPosition() {
	return position;
}
char Stage::getUnit() {
	return unit;
 }
int Stage::getCheckMate() {
	return checkMate;
}
int Stage::getKill() {
	return kill;
}
void Stage::initailzeBoard(int *speciality) {
	switch (speciality[0]) { //초차림
	case 0: //마상마상 
		switch (speciality[1]) { //한차림
		case 0: //마상마상 && 마상마상
			arr[10][2] = 'h'; arr[10][3] = 'x'; 
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'X'; arr[1][3] = 'H'; 
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 1: //마상마상 && 마상상마
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 2: //마상마상 && 상마마상
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		case 3: //마상마상 && 상마상마
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		}
		break;
	case 1: //마상상마
		switch (speciality[1]) { //한차림
		case 0: //마상상마 && 마상마상
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 1: //마상상마 && 마상상마
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 2: //마상상마 && 상마마상
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		case 3: //마상상마 && 상마상마
			arr[10][2] = 'h'; arr[10][3] = 'x';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		}
		break;
	case 2: //상마마상
		switch (speciality[1]) { //한차림
		case 0: //상마마상 && 마상마상
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 1: //상마마상 && 마상상마
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 2: //상마마상 && 상마마상
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		case 3: //상마마상 && 상마상마
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'h'; arr[10][8] = 'x';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		}
		break;
	case 3: //상마상마
		switch (speciality[1]) { //한차림
		case 0: //상마상마 && 마상마상
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 1: //상마상마 && 마상상마
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'X'; arr[1][8] = 'H';
			break;
		case 2: //상마상마 && 상마마상
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'X'; arr[1][3] = 'H';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		case 3: //상마상마 && 상마상마
			arr[10][2] = 'x'; arr[10][3] = 'h';
			arr[10][7] = 'x'; arr[10][8] = 'h';
			arr[1][2] = 'H'; arr[1][3] = 'X';
			arr[1][7] = 'H'; arr[1][8] = 'X';
			break;
		}
		break;
	}
}
//char* to char
void Stage::changeBoard() {
	int oldPos1 = position[0] / 10;
	int oldPos2 = position[0] % 10;
	int newPos1 = position[1] / 10;
	int newPos2 = position[1] % 10;
	/*strcpy(arr[newPos1][newPos2], unit);*/
	if (oldPos1 == 0) {
		oldPos1 = 10;
	}
	if (newPos1 == 0) {
		newPos1 = 10;
	}
	arr[oldPos1][oldPos2] = '-';
	arr[newPos1][newPos2] = unit;
}
//제일 처음에는 마상마상 & 마상마상 으로 Initialize
char Stage::arr[HEIGHT_SIZE][WIDTH_SIZE] = {
	{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', 'C', 'X', 'H', 'S', '-', 'S', 'X', 'H', 'C' },
	{ '-', '-', '-', '-', '-', 'K', '-', '-', '-', '-' },
	{ '-', '-', 'P', '-', '-', '-', '-', '-', 'P', '-' },
	{ '-', 'J', '-', 'J', '-', 'J', '-', 'J', '-', 'J' },
	{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', 'j', '-', 'j', '-', 'j', '-', 'j', '-', 'j' },
	{ '-', '-', 'p', '-', '-', '-', '-', '-', 'p', '-' },
	{ '-', '-', '-', '-', '-', 'k', '-', '-', '-', '-' },
	{ '-', 'c', 'h', 'x', 's', '-', 's', 'h', 'x', 'c' }
};
void Stage::printBoard() {
	for (int i = 1; i < HEIGHT_SIZE; i++) {
		for (int j = 1; j < WIDTH_SIZE; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
