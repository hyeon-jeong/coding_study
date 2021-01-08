// 15684_사다리_조작.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 987654321

int n, m, h;
int ladders[11][31] = { 0, };
int answer = INF;

/* i번 세로선의 결과가 i번이면 true */
bool gameResult() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			if (ladders[cur][j]) cur++;
			else if (ladders[cur - 1][j]) cur--;
		}
		if (cur != i) return false;
	}
	return true;
}

void drawLine(int row, int cnt) {
	if (cnt > 3) return; // 3보다 크면 종료
	if (gameResult()) { // 조건 만족하면 종료
		if (answer > cnt) answer = cnt;
		return;
	}

	for (int j = row; j <= h; j++) {
		for (int i = 1; i < n; i++) {
			// 이미 해당 위치에 사다리가 존재하면 continue
			if (ladders[i][j] == 1 || ladders[i - 1][j] == 1 || ladders[i + 1][j] == 1) continue;
			ladders[i][j] = 1;
			drawLine(j, cnt + 1);
			ladders[i][j] = 0;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ladders[b][a] = 1;
	}

	drawLine(1, 0);
	if (answer == INF) answer = -1;
	printf("%d\n", answer);
}
