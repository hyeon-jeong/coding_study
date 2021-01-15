// 16234_인구이동.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 51	

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int n, l, r;
int contry = 0; // 연합국 수
int people = 0; // 연합 인구 수
int area[MAX][MAX];
bool visited[MAX][MAX] = { false, };
vector<pair<int, int>> unions;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];


			if (nx > n || ny > n || nx <= 0 || ny <= 0) continue;
			int diff = abs(area[nx][ny] - area[x][y]);
			if (diff >= l && diff <= r && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				unions.push_back({ nx, ny });
				contry++;
				people += area[nx][ny];
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &area[i][j]);
		}
	}

	int result = 0;
	while (true) {
		memset(visited, false, sizeof(visited));
		bool moved = false; // 인구이동

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i][j]) continue;

				visited[i][j] = true;
				people = area[i][j];
				contry = 1;

				unions.clear();
				unions.push_back({ i, j });

				bfs(i, j);

				/* 연합국이 2개 이상이면 인구이동 */
				if (contry > 1) {
					moved = true;
					for (int i = 0; i < unions.size(); i++) {
						area[unions[i].first][unions[i].second] = people / contry;
					}
				}
			}
		}
		if (moved) result++;
		else break;
	}

	printf("%d\n", result);
}
