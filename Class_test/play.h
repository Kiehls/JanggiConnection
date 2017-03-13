#ifndef __PLAY__
#define __PLAY__

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "stage.h"

#define MIN 200

using namespace std;

class Play {
private:
	int reportNumber;
	int *specialty;//Â÷¸²
	int victory;
	Stage *stages[MIN];
public:
	Play();
	Play(int reportNum, int spe[], int vic);
	void insertStage(Stage *stage);
	void recordPlay(int report, int spe[], int vic);
	int getStagesLength();
};

#endif