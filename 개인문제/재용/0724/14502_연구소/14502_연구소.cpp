// 14502_연구소.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 8

int n, m; // 연구소 크기
int map[MAX][MAX];
int copy_map[MAX][MAX];
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<pair<int, int>> non_wall;
queue<pair<int, int>> q;
queue<pair<int, int>> q2; // 복사한 큐를 저장

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0) {
				map[nx][ny] = 2;
				q.emplace(nx, ny);
			}
		}
	}
}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) { // 바이러스 있는 부분은
				q.emplace(i, j); // 큐에 넣고
			}
			else if (map[i][j] == 0) { // 벽이나 바이러스 없는 부분은
				non_wall.emplace_back(i, j); // 벡터에 넣기
			}
		}
	}


	memcpy(copy_map, map, sizeof(map));
	q2 = q;

	int size = non_wall.size();
	int secure_area = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			for (int k = 0; k < size; k++) {
				if (j == k || i == k) continue;
				int x1 = non_wall[i].first, y1 = non_wall[i].second;
				int x2 = non_wall[j].first, y2 = non_wall[j].second;
				int x3 = non_wall[k].first, y3 = non_wall[k].second;
				map[x1][y1] = 3, map[x2][y2] = 3, map[x3][y3] = 3;

				bfs();
				int count = 0;
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < m; b++) {
						if (map[a][b] == 0) count++;
					}
				}
				secure_area = max(count, secure_area);
				memcpy(map, copy_map, sizeof(copy_map));
				q = q2;
			}
		}
	}
	printf("%d\n", secure_area);
	return 0;
}


