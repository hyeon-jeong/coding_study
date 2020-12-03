// 14888_연산자_끼워넣기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int oper[4]; // + : 0, - : 1, x : 2, / : 3
int num[11];

int maximum = -1000000000;
int minimum = 1000000000;

/* 모든 경우의 수 구하기 */
// idx = num의 인덱스
// plus, minus, multiple, divide : 각 연산자에 대한 사용 개수
// total = 중간 계산 결과 저장
void dfs(int idx, int plus, int minus, int multiple, int divide, int total) {
	if (idx == n) {
		maximum = max(maximum, total);
		minimum = min(minimum, total);
		return;
	}

	if (plus < oper[0]) {
		dfs(idx + 1, plus + 1, minus, multiple, divide, total + num[idx]);
	}
	if (minus < oper[1]) {
		dfs(idx + 1, plus, minus + 1, multiple, divide, total - num[idx]);
	}
	if (multiple < oper[2]) {
		dfs(idx + 1, plus, minus, multiple + 1, divide, total * num[idx]);
	}
	if (divide < oper[3]) {
		dfs(idx + 1, plus, minus, multiple, divide + 1, total / num[idx]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}

	dfs(1, 0, 0, 0, 0, num[0]);

	printf("%d\n%d\n", maximum, minimum);
}
