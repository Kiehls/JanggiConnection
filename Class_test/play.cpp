#include "play.h"

Play::Play() {
	reportNumber = 0;
	victory = 0;
	memset(specialty, 0, sizeof(int) * 2);
	for (int i = 0; i < MIN; i++) {
		stages[i] = NULL;
	}
}
Play::Play(int reportNum, int spe[], int vic)
:reportNumber(reportNum), victory(vic)
{
	memcpy(specialty, spe, sizeof(int) * 2);
	for (int i = 0; i < MIN; i++) {
		stages[i] = NULL;
	}
}
void Play::insertStage(Stage *stage) {
	int size = getStagesLength();
	if (size == 201) {
		cout << "Stage size overflow" << endl;
	}
	else {
		stages[size] = stage;
	}
}
void Play::recordPlay(int report, int spe[], int vic) {
	reportNumber = report;
	memcpy(specialty, spe, sizeof(spe));
	victory = vic;
}
int Play::getStagesLength() {
	for (int i = 0; i < MIN; i++) {
		if (stages[i] == NULL) {
			return i;
		}
	}
	return 201;
}