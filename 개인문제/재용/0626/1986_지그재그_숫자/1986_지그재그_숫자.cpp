// 1986_지그재그_숫자.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int n;
		scanf("%d", &n);

		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) sum -= i;
			else if (i % 2 != 0) sum += i;
		}
		printf("#%d", tc);
		printf(" %d\n", sum);
	}
	return 0;
}

