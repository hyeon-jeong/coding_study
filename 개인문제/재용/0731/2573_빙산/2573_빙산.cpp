#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAX 301

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void dfs(int a, int b) { // 빙하 덩어리 개수를 세기 위한 dfs
	for (int i = 0; i < 4; i++) {
		int na = a + direction[i][0];
		int nb = b + direction[i][1];

		if (na < 0 || nb < 0 || na >= n || nb >= m) continue;
		if (visited[na][nb] == 0 && map[na][nb] > 0) {
			visited[na][nb] = 1;
			dfs(na, nb);
		}
	}
}

void melt(int a, int b) { // 빙하를 녹이기 위한 dfs
	for (int i = 0; i < 4; i++) {
		int na = a + direction[i][0];
		int nb = b + direction[i][1];

		if (na < 0 || nb < 0 || na >= n || nb >= m) continue;
		if (visited[na][nb] == 0 && map[na][nb] == 0) { // 주변이 바다이면
			map[a][b] = max(map[a][b] - 1, 0); // 빙하 높이 감소
			// 방문표시는 따로 하지 X
		}
		else if (visited[na][nb] == 0 && map[na][nb] > 0) {
			visited[na][nb] = 1;
			melt(na, nb);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int year = 0;
	while (true) {
		year++;
		for (int i = 0; i < n; i++) { // 빙하 녹이기
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && map[i][j] > 0) {
					visited[i][j] = 1;
					melt(i, j);
				}
			}
		}

		memset(visited, 0, sizeof(visited)); // 방문표시 초기화
		int count = 0; // 빙하 덩어리 개수
		for (int i = 0; i < n; i++) { // 빙하 덩어리 개수 세기
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && map[i][j] > 0) {
					visited[i][j] = 1;
					dfs(i, j);
					count++;
				}
			}
		}

		if (count > 1) break; // 빙하 덩어리가 2개 이상이면 break
		else if (count == 0) { // 빙하가 다 녹을 때까지도 덩어리가 나눠지지 않으면
			year = 0; // 0 반환
			break;
		}
		memset(visited, 0, sizeof(visited)); // 방문표시 초기화
	}
	printf("%d\n", year);
}