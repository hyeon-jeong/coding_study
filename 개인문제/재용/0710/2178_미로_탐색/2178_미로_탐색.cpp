// 2178_미로_탐색.cpp
// BFS
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <utility>

int n, m; 
int maze[101][101] = { 0, };
int visited[101][101] = { 0, };
int path[101][101];
int direction[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // 위, 아래, 오른쪽, 왼쪽

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	int count = 0;

	visited[a][b] = 1;
	path[a][b] = 1; // 해당 좌표까지 가기까지 거친 칸의 수 저장
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) break;

		for (int i = 0; i < 4; i++) {
			int next_x = x + direction[i][0];
			int next_y = y + direction[i][1];

			if (next_x < n && next_x >= 0 && next_y < m && next_y >= 0) {
				if (maze[next_x][next_y] == 1 && visited[next_x][next_y] == 0) { // 미로에 해당 경로가 존재하고, 방문 안했으면
					visited[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y));
					path[next_x][next_y] = path[x][y] + 1;
				}
			}
			else continue;
		}
	}

	count = path[n - 1][m - 1];
	return count;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int u = 0; u < n; u++) { // 미로 초기화
		for (int v = 0; v < m; v++) {
			scanf("%1d", &maze[u][v]);
		}
	}

	int count = bfs(0, 0);
	printf("%d\n", count);
}
