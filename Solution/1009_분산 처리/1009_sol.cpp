#include <stdio.h>

int main() {

	int tryCount;
	scanf("%d", &tryCount);

	for (int i = 0; i < tryCount; i++) {
		int upper, under;
		scanf("%d %d", &under, &upper);

		under = under % 10;
		upper--;
		int result2[4] = { 2,4,8,6 };
		int result3[4] = { 3,9,7,1 };
		int result7[4] = { 7,9,3,1 };
		int result8[4] = { 8,4,2,6 };
		int result4[2] = { 4,6 };
		int result9[2] = { 9,1 };


		switch (under) {
		case 0: printf("10\n"); break;
		case 1: printf("1\n"); break;
		case 5: printf("5\n"); break;
		case 6: printf("6\n"); break;
		case 2: printf("%d\n", result2[upper % 4]); break;
		case 3: printf("%d\n", result3[upper % 4]); break;
		case 7: printf("%d\n", result7[upper % 4]); break;
		case 8: printf("%d\n", result8[upper % 4]); break;
		case 4: printf("%d\n", result4[upper % 2]); break;
		case 9: printf("%d\n", result9[upper % 2]); break;
		}
	}
	return 0;
}