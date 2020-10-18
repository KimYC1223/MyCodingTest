#include <stdio.h>
#include <math.h>

int main() {
	int test = 0;
	scanf("%d",&test);

	for (int tryCount = 0; tryCount < test; tryCount++) {
		int x1, y1, r1, x2, y2, r2;

		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		double length, min1, max1, min2, max2;
		
		length = sqrt((pow((double)(abs(x1-x2)),2) + pow((double)(abs(y1-y2)),2)));
		min1 = 0 - (double)r1;
		max1 = 0 + (double)r1;
		min2 = length - (double)r2;
		max2 = length + (double)r2;
		int count = 0;

		if (min1 == min2 && max1 == max2) {
			count = -1;
		}
		else if ( min1 < min2 && max1 == max2 ) {
			count = 1;
		}
		else if (min1 > min2 && max1 == max2) {
			count = 1;
		}
		else if (min1 == min2 && max1 < max2) {
			count = 1;
		}
		else if (min1 < min2 && max1 < max2) {
			if (r1 + r2 > length)
				count = 2;
			else if (r1 + r2 == length)
				count = 1;
			else count = 0;
		}
		else if (min1 > min2 && max1 < max2) {
			count = 0;
		}
		else if (min1 == min2 && max1 > max2) {
			count = 1;
		}
		else if (min1 < min2 && max1 > max2) {
			count = 0;
		}
		else if (min1 > min2 && max1 > max2) {
			if (r1 + r2 > length)
				count = 2;
			else if (r1 + r2 == length)
				count = 1;
			else count = 0;
		}

		printf("%d\n",count);
	}

	return 0;
}
