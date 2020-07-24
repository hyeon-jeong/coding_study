// 7576_토마토.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

int m, n; // 상자 크기
int box[MAX][MAX] = { 0, }; // 상자 
int visited[MAX][MAX] = { 0, }; // 방문 표시
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // 방향 (상하좌우)
int day; // 토마토 익는 최소 일수
queue<pair<int, int>> q; // BFS를 위한 queue

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (box[nx][ny] == 1 || box[nx][ny] == -1) continue;
			else if (visited[nx][ny] == 0 && box[nx][ny] == 0) { // 방문 안했고, 아직 안익었으면
				visited[nx][ny] = 1; // 방문표시
				box[nx][ny] = box[x][y] + 1; // 전날 익은 숫자에 +1
				q.emplace(nx, ny);
			}
		}
	}
}



int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) { // 이미 익은 토마토이면
				q.push(make_pair(i, j)); // 큐에 삽입
			}
		}
	}

	day = 0;
	bfs(); // bfs 수행

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) { // 안익은 토마토가 존재하면
				printf("-1\n"); // -1 출력하고 종료
				return 0;
			}
			if (day < box[i][j]) day = box[i][j]; // box의 최대값 = day - 1
		}
	}

	printf("%d\n", day - 1); // box의 day는 1부터 시작하지만, 실제 day는 0부터 시작해야 하기 때문
	return 0;
}

