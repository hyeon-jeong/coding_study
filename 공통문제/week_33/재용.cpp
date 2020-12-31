// 14466_소가_길을_건너간_이유6.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 101

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
bool visited[MAX][MAX];
vector<pair<int, int>> bridge[MAX][MAX];
int n, k, r;

/* 다리가 연결되어 있으면 true */
bool connect(int cx, int cy, int nx, int ny) {
	bool result = false;
	for (auto &p : bridge[cx][cy]) {
		if (p.first == nx && p.second == ny) {
			result = true;
			break;
		}
	}
	return result;
}

void bfs(int x, int y) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];

			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

			// 다음 정점을 방문하지 않았고, 다리도 연결되어있지 않으면
			if (!visited[nx][ny] && !connect(cx, cy, nx, ny)) {
				visited[nx][ny] = true; // 방문
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &r);
	for (int i = 0; i < r; i++) {
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		bridge[r1][c1].push_back({ r2, c2 });
		bridge[r2][c2].push_back({ r1, c1 });
	}
	 
	/* 소들의 위치 저장 */
	vector<pair<int, int>> cow;
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		cow.push_back({ x, y });
	}

	int answer = 0;
	for (int i = 0; i < k; i++) {
		/* 소가 방문할 수 있는 모든 칸 방문 */
		bfs(cow[i].first, cow[i].second);

		// 본인을 제외한 나머지 소가 방문되지 않았으면 count
		for (int j = i + 1; j < k; j++) { 
			if (!visited[cow[j].first][cow[j].second]) answer++;
		}
		/* 소의 '쌍'을 세는 것이기 때문에 이전에 count된 소는 다시 안세도 됨 */
	}

	printf("%d\n", answer);
}
