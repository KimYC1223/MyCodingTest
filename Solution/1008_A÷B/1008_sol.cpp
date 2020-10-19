#include <stdio.h>

int main() {
	int a;
	int b;


	scanf("%d", &a);
	scanf("%d", &b);
	double result = (double)(a) / (double)(b);

	printf("%.32f", result);
	return 0;
}