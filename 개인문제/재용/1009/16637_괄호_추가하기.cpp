// 16637_괄호_추가하기.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 20

int n; // 수식 길이
int max_result = -987654321; // 최대값

char oper[MAX];
int num[MAX];

int cal(int a, int b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
}

void dfs(int idx, int result) { // idx: 연산자 인덱스, result: 현재까지의 연산 결과
	/* 연산자 개수 = n / 2 */
	if (idx >= n / 2) { // 끝까지 탐색하면 종료
		max_result = max(max_result, result);
		return;
	}

	// 현재 연산자 기준 괄호 추가
	char op = oper[idx];
	int cur_result = cal(result, num[idx + 1], op); // 다음으로 오는 수와 연산
	dfs(idx + 1, cur_result);

	// 다음 연산자 기준 괄호 추가
	if (idx + 1 < n / 2) {
		int next_result = cal(num[idx + 1], num[idx + 2], oper[idx + 1]); // 다음 연산자에 괄호 추가해 연산
		int cur_result = cal(result, next_result, op);
		dfs(idx + 2, cur_result);
	}
}

int main()
{
	scanf("%d", &n);

	string exp;
	cin >> exp;

	int o_idx = 0;
	int n_idx = 0;
	/* 연산자 배열, 피연산자 배열 따로 저장 */
	for (int i = 0; i < n; i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
			oper[o_idx++] = exp[i];
		}
		else num[n_idx++] = exp[i] - '0';
	}

	dfs(0, num[0]);

	printf("%d", max_result);

	return 0;
}
