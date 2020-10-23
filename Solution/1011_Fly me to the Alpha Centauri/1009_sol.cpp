#include <stdio.h>

double jumpAble(int s) {
	return (((double)s+1)*(double)s)/2;
}

int main() {
	int test;
	int start, end;
	
	scanf("%d", &test);
	
	for (int n = 0; n < test; n++) {
		int jump = 0;
		scanf("%d",&start);
		scanf("%d", &end);

		double length = end - start;
		int speed = 0;

		while (length > 0) {
			if (length - jumpAble(speed + 1) >= 0)
				speed++;
			else if (length - jumpAble(speed) >= 0)
				speed += 0;
			else speed--;
			length -= speed;
			jump++;
		}
		printf("%d\n",jump);
	}
	return 0;
}

