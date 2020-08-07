using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
#define MAX 101

int n;
int map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void dfs(int x, int y, int num) { // 대륙 번호 매기기
	if (visited[x][y] == 1) return;
	visited[x][y] = 1;
	map[x][y] = num;

	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
			dfs(nx, ny, num);
		}
	}
}

int build(int num) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) { // 같은 대륙의 좌표를 모두 큐에 넣음
		for (int j = 0; j < n; j++) {
			if (map[i][j] == num) {
				visited[i][j] = 1;
				q.emplace(i, j);
			}
		}
	}

	int bridge = 0;
	while (!q.empty()) { // 한칸씩 간척 진행
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + direction[j][0];
				int ny = y + direction[j][1];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				// 도달한 칸이 육지이고 다른 대륙이면, 다리가 연결된 것이므로 return
				if (map[nx][ny] != 0 && map[nx][ny] != num) return bridge;
				else if (visited[nx][ny] == 0 && map[nx][ny] == 0) { // 아직 방문 안한 바다이면
					visited[nx][ny] = 1; // 방문표시하고
					q.emplace(nx, ny); // 큐에 넣음
				}
			}
		}
		bridge++; // 한 칸씩 간척할 때마다 다리 길이 증가
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int area = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && map[i][j] == 1) {
				dfs(i, j, area++);
			}
		}
	}

	int bridge = 100000;
	for (int i = 1; i < area; i++) {
		memset(visited, 0, sizeof(visited));
		bridge = min(bridge, build(i));
	}

	printf("%d\n", bridge);
	return 0;
}
