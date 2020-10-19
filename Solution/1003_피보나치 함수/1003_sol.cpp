#include <stdio.h>

typedef struct _fibo {
	int num;
	int zero;
	int one;
} fibo;

fibo fiboCheck[41];
bool fiboCheckBool[41] = { false };

fibo fibonacci(fibo _fibo) {
	if (_fibo.num == 0) {
		if (!fiboCheckBool[0]) {
			fibo newFibo;
			newFibo.num = 0;
			newFibo.zero = 1;
			newFibo.one = 0;
			fiboCheck[0] = newFibo;
			fiboCheckBool[0] = true;
			return newFibo;
		}
		else return fiboCheck[0];
	}
	else if (_fibo.num == 1) {
		if (!fiboCheckBool[1]) {
			fibo newFibo;
			newFibo.num = 1;
			newFibo.zero = 0;
			newFibo.one = 1;
			fiboCheck[1] = newFibo;
			fiboCheckBool[1] = true;
			return newFibo;
		}
		else return fiboCheck[1];
	}

	if (!fiboCheckBool[_fibo.num]) {
		fibo newFibo1; fibo newFibo2;
		newFibo1.num = _fibo.num - 1;
		newFibo2.num = _fibo.num - 2;

		newFibo1 = fibonacci(newFibo1);
		newFibo2 = fibonacci(newFibo2);

		_fibo.zero = newFibo1.zero + newFibo2.zero;
		_fibo.one = newFibo1.one + newFibo2.one;
		fiboCheckBool[_fibo.num] = true;
		fiboCheck[_fibo.num] = _fibo;
		return _fibo;
	}
	else return fiboCheck[_fibo.num];
}

int main() {
	int testCase = 0;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		int fibo_num;
		scanf("%d", &fibo_num);

		fibo target;
		target.num = fibo_num;
		target = fibonacci(target);

		printf("%d %d\n", target.zero, target.one);
	}
	return 0;
}
