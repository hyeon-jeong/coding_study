// 14503_로봇청소기.cpp
#include <iostream>
using namespace std;
#define MAX 50

int N, M;
int X, Y, D; // 로봇청소기 좌표, 방향
int area[MAX][MAX];
int clean = 0;
int nextDir[4][2] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } }; // 북(0), 동(1), 남(2), 서(3) 방향으로 전진
int backDir[4][2] = { { 1, 0 },{ 0, -1 },{ -1, 0 },{ 0, 1 } }; // 북, 동, 남, 서 방향으로 후진

															   /* 방향 회전하기 */
int rotate(int d) {
	switch (d) { // 현재 방향의 왼쪽으로 회전
	case 0: // 북
		d = 3;
		break;
	case 1: // 동
		d = 0;
		break;
	case 2: // 남
		d = 1;
		break;
	case 3: // 서
		d = 2;
		break;
	}

	return d;
}

void cleaning(int x, int y, int d) {
	if (area[x][y] == 0) {
		area[x][y] = 2; // 1. 현재 위치 청소
		clean++;
	}

	for (int i = 0; i < 4; i++) {
		int nd = rotate(d);

		int nx = x + nextDir[nd][0];
		int ny = y + nextDir[nd][1];

		/* 좌표 범위 내이고 */
		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			/* 청소 안했으면 */
			if (area[nx][ny] == 0) {
				cleaning(nx, ny, nd);
				return; // 이거 안쓰면 답 잘못나옴
			}
			/* 이미 청소했거나 벽이 있으면 */
			else d = nd; // 방향만 바꿔줌
		}
	}

	/* 후진 */
	int bx = x + backDir[d][0];
	int by = y + backDir[d][1];
	if (area[bx][by] == 1) return; // 후진 불가능할 경우
	else cleaning(bx, by, d); // 후진 가능할 경우
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &X, &Y, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &area[i][j]);
		}
	}
	cleaning(X, Y, D);

	printf("%d\n", clean);

	return 0;
}
