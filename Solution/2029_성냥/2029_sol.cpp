#include <iostream>
#include <vector>

using namespace std;

vector<string> input;
vector<vector<bool>> stick;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	input.resize(10);
	for (int i = 0; i < 10; i++)
		cin >> input[i];

	stick.resize(7);
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0)
			stick[i].resize(3);
		else stick[i].resize(4);
	}

	int removed = 0;

	for (int i = 0; i < 10; i++) {
		if (i == 2 || i == 5 || i == 8) continue;
		if (i == 1 || i == 4 || i == 7)
			for (int j = 0; j < 4; j++)
				if (input[i][j * 3] == '|')
					stick[1 + 2 * ((i - 1) / 3)][j] = true;
				else removed++;
		else
			for (int j = 0; j < 3; j++)
				if (input[i][1 + j * 3] == '-')
					stick[2 * ((i) / 3)][j] = true;
				else removed++;
	}

	int sqCount = 0;
	if (stick[0][0] && stick[0][1] && stick[0][2] &&
		stick[1][0] && stick[3][0] && stick[5][0] &&
		stick[6][0] && stick[6][1] && stick[6][2] &&
		stick[1][3] && stick[3][3] && stick[5][3])
		sqCount++;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (stick[2 * i][j] && stick[2 * i][j + 1] &&
				stick[2 * i + 1][j] && stick[2 * i + 3][j] &&
				stick[2 * i + 4][j] && stick[2 * i + 4][j + 1] &&
				stick[2 * i + 1][j + 2] && stick[2 * i + 3][j + 2])
				sqCount++;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (stick[2 * i][j] && stick[2 * i + 1][j] &&
				stick[2 * i + 2][j] && stick[2 * i + 1][j + 1])
				sqCount++;
		}
	}

	cout << removed << " " << sqCount << "\n";
	return 0;
}