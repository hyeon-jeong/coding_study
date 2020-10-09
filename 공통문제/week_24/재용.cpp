// 19952_인성문제있어.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#define MAX 101

int T; // test case
int maze[MAX][MAX];
int visited[MAX][MAX];
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool bfs(int h, int w, int f, int xs, int ys, int xe, int ye) {
	bool result = false;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(f, make_pair(xs, ys)));
	visited[xs][ys] = 1;

	while (!q.empty()) {
		int force = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == xe && y == ye) { // 도착하면 true
			result = true;
			break;
		}
		if (force == 0) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];

			if (nx > h || ny > w || nx < 1 || ny < 1) continue;
			if (visited[nx][ny]) continue;

			if (force >= (maze[nx][ny] - maze[x][y])) {
				visited[nx][ny] = 1;
				q.push(make_pair(force - 1, make_pair(nx, ny)));
			}
		}
	}

	return result;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		int h, w, o, f, xs, ys, xe, ye;
		scanf("%d %d %d %d %d %d %d %d",
			&h, &w, &o, &f, &xs, &ys, &xe, &ye);

		memset(visited, 0, sizeof(visited));
		memset(maze, 0, sizeof(maze));
		for (int i = 0; i < o; i++) { // 장애물 정보 입력
			int x, y, l;
			scanf("%d %d %d", &x, &y, &l); // x: 행, y: 열
			maze[x][y] = l;
		}

		if (bfs(h, w, f, xs, ys, xe, ye)) printf("잘했어!!\n");
		else printf("인성 문제있어??\n");
	}

	return 0;
}
