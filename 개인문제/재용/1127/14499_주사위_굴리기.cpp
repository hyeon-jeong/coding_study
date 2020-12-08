// 14499_주사위_굴리기.
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#define MAX 400

int map[MAX][MAX] = { 0, };
int n, m, x, y, K;
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // east, west, north, south
int dice[7] = { 0, };
int command[1000];

int move(int k) {
	int nx = x + dir[k - 1][0];
	int ny = y + dir[k - 1][1];

	/* 범위 벗어나면 넘어감 */
	int error = -1;
	if (nx >= n || ny >= m || nx < 0 || ny < 0) return error;

	/* 범위 안일 때 */
	int temp = dice[1];
	switch (k) {
		case 1: // east
			// 4 1 3 6
			// 1 3 6 4
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
			break;
		case 2: // west
			// 4 1 3 6
			// 6 4 1 3
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
			break;
		case 3: // north
			// 2 1 5 6
			// 1 5 6 2  
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
			break;
		case 4: // south
			// 2 1 5 6
			// 6 2 1 5
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
			break;
	}

	/* 지도 - 주사위 번호 변경 */
	if (map[nx][ny] == 0) map[nx][ny] = dice[1];
	else {
		dice[1] = map[nx][ny];
		map[nx][ny] = 0;
	}

	/* 주사위 위치 갱신 */
	x = nx;
	y = ny;

	return dice[6];
}


int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &K);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &command[i]);
	}

	for (int i = 0; i < K; i++) {
		int k = command[i];
		int result = move(k);
		if (result == -1) continue;
		else printf("%d\n", result);
	}
	return 0;
}
