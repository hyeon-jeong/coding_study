// 17070_파이프_옮기기1.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#define MAX 16

int n; // 집의 크기
int house[MAX][MAX] = { 0, };

int dir[3][2] = { {0, 1}, {1, 0}, {1, 1} }; // 가로, 세로, 대각선
int answer = 0; // 경우의 수

// x, y는 파이프의 끝부분 좌표를 나타냄
void dfs(int x, int y, int pipe) { // pipe: 가로(0), 세로(1), 대각선(2)
	if (x == n - 1 && y == n - 1) { 
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		// 회전은 한번에 45도만 가능
		// 가로 -> 세로, 세로 -> 가로 불가능
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0)) continue;

		/* 대각선으로 미는 경우 벽이 있는지 확인 */
		if (i == 2 && (house[x + 1][y] == 1 || house[x][y + 1] == 1)) continue;

		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		/* 범위를 벗어나거나 벽이면 continue */
		if (nx > n - 1 || ny > n - 1) continue;
		if (house[nx][ny] == 1) continue;

		dfs(nx, ny, i);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &house[i][j]);
		}
	}

	dfs(0, 1, 0); // 초기 파이프의 끝점 (1, 2), 가로방향
	printf("%d\n", answer);

	return 0;
}

