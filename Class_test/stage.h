#ifndef __STAGE
#define __STAGE__

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#define HEIGHT_SIZE 11
#define WIDTH_SIZE 10

using namespace std;

class Stage {
private:
	int host;
	int position[2];
	char unit;
	/*char *unit;*/
	int checkMate;
	int kill;
	static char arr[HEIGHT_SIZE][WIDTH_SIZE];
public:
	Stage();
	/*Stage(int hostNum, int pos[], char *unit, int check, int killed);*/
	Stage(int hostNum, int pos[], char unit, int check, int killed);
	int getHost();
	int* getPosition();
	/*char* getUnit();*/
	char getUnit();
	int getCheckMate();
	int getKill();
	void initailzeBoard(int *speciality);
	void changeBoard();
	void printBoard();
};

#endif