#include "play.h"

#define TOKEN_SIZE 6

void CreatePlay(string line);
bool CheckLine(string line);
Stage *CreateStage(string line);
string *StringSplit(string target);

//Infromation Data
char* HorseSequence[4] = { "마상마상", "마상상마", "상마마상", "상마상마" };
char* Korean_character[8] = { "졸", "병", "마", "포","차", "상", "사","장" };
char to_English[7] = { 'J', 'H','P', 'C', 'X', 'S', 'K' };

//초이 선공(소문자) 한이 후공(대문자)

int main() {

	ifstream inStream("testFile.txt");
	if (inStream.fail()) {
		cout << "Stream File Failed" << endl;
		exit(1);
	}
	string line;
	Play *game[100];
	int reportNumber, spciality[2] = { 0, }, victory;
	int index = 0;
	while (!inStream.eof()) {
		inStream >> line;
		//기보 시작인지 내용인지 검사
		if (CheckLine(line)) {
			reportNumber = atoi(line.c_str());
			inStream >> spciality[0] >> spciality[1] >> victory;
			Play *gameReport = new Play(reportNumber, spciality, victory);
			Stage *state = new Stage();
			state->initailzeBoard(spciality);
			gameReport->insertStage(state);
			game[index] = gameReport;
		}
		else {
			game[index]->insertStage(CreateStage(line));
		}
	}
	return 0;
}
void CreatePlay(string line) {

}
Stage *CreateStage(string line) {
	int position[2]; char *unit;
	int host, kill, checkMate;
	string* splitLine = StringSplit(line);

	host = atoi(splitLine[0].c_str());
	position[0] = atoi(splitLine[1].c_str());
	position[1] = atoi(splitLine[2].c_str());
	strcpy(unit, splitLine[3].c_str());
	kill = atoi(splitLine[4].c_str());
	checkMate = atoi(splitLine[5].c_str());

	Stage *stage = new Stage(host, position, unit, checkMate, kill);
	stage->changeBoard();

	return stage;
}

bool CheckLine(string line) {
	if (line.find('.') != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

string *StringSplit(string target) {
	int     nCutPos;
	int     nIndex = 0;
	string* strResult = new string[TOKEN_SIZE];

	while ((nCutPos = target.find_first_of(' ')) != target.npos)
	{
		if (nCutPos > 0)
		{
			strResult[nIndex++] = target.substr(0, nCutPos);
		}
		target = target.substr(nCutPos + 1);
	}

	if (target.length() > 0)
	{
		strResult[nIndex++] = target.substr(0, nCutPos);
	}

	return strResult;
}