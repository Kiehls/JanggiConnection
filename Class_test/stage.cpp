#include "stage.h"

Stage::Stage() {
	host = 0;
	position = (int*)calloc(0, sizeof(int) * 2);
	strcpy(unit, "n");
	checkMate = 0;
	kill = 0;

}
Stage::Stage(int hostNum, int pos[], char *unitState, int check, int killed) {
	host = hostNum;
	memcpy(position, pos, sizeof(pos));
	strcpy(unit, unitState);
	checkMate = check;
	kill = killed;
}
int Stage::getHost() {
	return host;
}
int* Stage::getPosition() {
	return position;
}
char* Stage::getUnit() {
	return unit;
 }
int Stage::getCheckMate() {
	return checkMate;
}
int Stage::getKill() {
	return kill;
}
void Stage::initailzeBoard(int *speciality) {
	if (speciality[0] == 0 && speciality[1] == 0) {//마상마상

	}
	else if (speciality[0] == 1 && speciality[1] == 0) {//상마마상

	}
	else if (speciality[0] == 0 && speciality[1] == 1) {//마상상마

	}
	else if (speciality[0] == 1 && speciality[1] == 1) {//상마상마

	}
}
char Stage::arr[HEIGHT_SIZE][WIDTH_SIZE] = {
	{ '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' },
	{ '*', },
	{ '*', },
	{ '*', },
	{ '*', },
	{ '*', 'J', 'o', 'J', 'o', 'J', 'o', 'J', 'o', 'J'},
	{ '*', },
	{ '*', },
	{ '*', '*', '*', '*', '*', 'K', '*', '*', '*', '*'},
	{ 'o', 'C', 'P', 'X', 'S', 'o', 'S', 'X', 'P', 'C'},
	{ '*', }
}
