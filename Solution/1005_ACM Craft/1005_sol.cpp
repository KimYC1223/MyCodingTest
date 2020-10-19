#include <stdio.h>
#include <math.h>

typedef struct _techtree {
	short need;
	short target;
} techtree;

int checkTechtree(int goal, int* times, int* minTimes, int techCount, techtree* techs);

int main() {
	int test = 0;
	scanf("%d", &test);

	for (int tryCount = 0; tryCount < test; tryCount++) {
		int buildCount = 0;
		int techCount = 0;
		scanf("%d %d", &buildCount, &techCount);

		int buildTime[1000] = { 0 };
		int minTime[1000] = { 0 };

		for (int i = 0; i < buildCount; i++) {
			scanf("%d", &buildTime[i]);
			minTime[i] = -1;
		}
		techtree tech[100000];

		for (int i = 0; i < techCount; i++) {
			int _need, _target;
			scanf("%d %d ", &_need, &_target);
			tech[i].need = _need - 1;
			tech[i].target = _target - 1;
		}

		int goal;
		scanf("%d", &goal);
		goal--;
		int timeCount = 0;

		timeCount = checkTechtree(goal, buildTime, minTime, techCount, tech);

		printf("%d\n", timeCount);
	}

	return 0;
}

int checkTechtree(int goal, int* times, int* minTimes, int techCount, techtree* techs) {
	int result = times[goal];
	int max = 0;
	char flag = 0;

	for (int i = 0; i < techCount; i++) {
		if (techs[i].target == goal) {
			flag = 1;
			int spendTime = 0;

			if (minTimes[techs[i].need] != -1)
				spendTime = minTimes[techs[i].need];
			else {
				spendTime = checkTechtree(techs[i].need, times, minTimes, techCount, techs);
				minTimes[techs[i].need] = spendTime;
			}

			max = (max > spendTime) ? max : spendTime;
		}
	}
	if (flag == 0) return result;
	else return result + max;
}
