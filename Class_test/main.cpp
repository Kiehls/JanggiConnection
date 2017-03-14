#include "play.h"

#define TOKEN_SIZE 6

void CreatePlay(string line);
bool CheckLine(string line);
Stage *CreateStage(string line);
string *StringSplit(string target);
void convertString(string line, int i, int *data);

//Infromation Data
char* HorseSequence[4] = { "마상마상", "마상상마", "상마마상", "상마상마" };
char* Korean_character[8] = { "졸", "병", "마", "포","차", "상", "사","장" };
char to_English[7] = { 'J', 'H','P', 'C', 'X', 'S', 'K' };

//초이 선공(소문자) 한이 후공(대문자)

static int wow = 1;

int main() {

	ifstream inStream("testFile.txt");
	if (inStream.fail()) {
		cout << "Stream File Failed" << endl;
		exit(1);
	}
	string line;
	Play *game[100];
	int reportNumber, spciality[2] = { 0, }, victory;
	int data[3] = { 0, };
	int index = 0;
	while (!inStream.eof()) {
		/*inStream >> line;*/
		getline(inStream, line);
		//기보 시작인지 내용인지 검사
		if (CheckLine(line)) {
			cout << endl << "new file " << index << endl;
			reportNumber = atoi(line.c_str());
			for (int i = 0; i < 3; i++) {
				getline(inStream, line);
				convertString(line, i, data);
			}
			memcpy(spciality, data, sizeof(int) * 2);
			victory = data[2];
			Play *gameReport = new Play(reportNumber, spciality, victory);
			Stage *state = new Stage();
			state->initailzeBoard(spciality);
			gameReport->insertStage(state);
			game[index++] = gameReport;
		}
		else {
			int tempIndex = index - 1;
			game[tempIndex]->insertStage(CreateStage(line));
		}
	}
	return 0;
}
void CreatePlay(string line) {

}
Stage *CreateStage(string line) {
	int position[2]; char *unit = new char(2);
	int host, kill, checkMate;
	string* splitLine = StringSplit(line);

	host = atoi(splitLine[0].c_str());
	position[0] = atoi(splitLine[1].c_str());
	position[1] = atoi(splitLine[2].c_str());
	strcpy(unit, splitLine[3].c_str());
	kill = atoi(splitLine[4].c_str());
	checkMate = atoi(splitLine[5].c_str());

	Stage *stage = new Stage(host, position, unit[0], checkMate, kill);
	cout << wow << endl;
	wow++;
	stage->changeBoard();
	stage->printBoard();

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

void convertString(string line, int i, int *data) {
	data[i] = atoi(line.c_str());
}