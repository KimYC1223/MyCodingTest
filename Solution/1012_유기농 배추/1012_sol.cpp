#include <stdio.h>

int beachu[52][52] = { 0 };
typedef enum _startDirection { UP, DOWN, LEFT, RIGHT } startDirection;

void checkBeachu(int garo, int sero, startDirection dir);

int main() {
	int test = 0;
	scanf("%d", &test);

	for (int tryCount = 0; tryCount < test; tryCount++) {

		int field_GARO = 0;
		int field_SERO = 0;
		int beachuCount = 0;
		int count = 0;

		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++)
				beachu[i][j] = 2;

		for (int i = 1; i < 51; i++)
			for (int j = 1; j < 51; j++)
				beachu[i][j] = 0;

		scanf("%d %d %d", &field_GARO, &field_SERO, &beachuCount);

		for (int i = 0; i < beachuCount; i++) {
			int garo, sero;
			scanf("%d %d", &garo, &sero);
			beachu[sero + 1][garo + 1] = 1;
		}

		for (int i = 1; i < 51; i++) {
			for (int j = 1; j < 51; j++) {
				if (beachu[i][j] == 1) {
					startDirection dir = LEFT;
					checkBeachu(j, i, dir);
					count++;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

void checkBeachu(int garo, int sero, startDirection dir) {
	beachu[sero][garo] = 0;

	startDirection dir_next;

	if (dir != UP)
		if (beachu[sero - 1][garo] == 1) {
			dir_next = DOWN;
			checkBeachu(garo, sero - 1, dir_next);
		}

	if (dir != DOWN)
		if (beachu[sero + 1][garo] == 1) {
			dir_next = UP;
			checkBeachu(garo, sero + 1, dir_next);
		}

	if (dir != LEFT)
		if (beachu[sero][garo - 1] == 1) {
			dir_next = RIGHT;
			checkBeachu(garo - 1, sero, dir_next);
		}

	if (dir != RIGHT)
		if (beachu[sero][garo + 1] == 1) {
			dir_next = LEFT;
			checkBeachu(garo + 1, sero, dir_next);
		}
}