// 3085_사탕게임.cpp
/* dfs로 풀면 완전탐색 불가능!! */
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 50

int n;
char board[MAX][MAX];

int checkMax() {
	int answer = 1;
	/* 가로(행) 체크 */
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (board[i][j - 1] == board[i][j]) cnt++;
			else {
				if (answer < cnt) answer = cnt;
				cnt = 1; // 초기화
			}
		}
		if (answer < cnt) answer = cnt;
	}

	/* 세로(열) 체크 */
	for (int j = 0; j < n; j++) {
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (board[i - 1][j] == board[i][j]) cnt++;
			else {
				if (answer < cnt) answer = cnt;
				cnt = 1; // 초기화
			}
		}
		if (answer < cnt) answer = cnt;
	}

	return answer;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}

	int result = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			/* 양옆 swap */
			swap(board[i][j], board[i][j + 1]);
			result = max(result, checkMax());
			swap(board[i][j], board[i][j + 1]);

			/* 위아래 swap */
			swap(board[j][i], board[j + 1][i]);
			result = max(result, checkMax());
			swap(board[j][i], board[j + 1][i]);
		}
		if (result == n) break;
	}

	printf("%d\n", result);
}
