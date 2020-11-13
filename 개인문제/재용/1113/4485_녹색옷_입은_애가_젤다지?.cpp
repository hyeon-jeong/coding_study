// 4485_녹색옷_입은_애가_젤다지?.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#define MAX 125
#define INF 150000

int n;
int cave[MAX][MAX];
int dist[MAX][MAX];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void dijkstra(int sx, int sy) {
	/* memset이 INF에 대해서 제대로 동작하지 못함 */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) dist[i][j] = INF;
	}

	priority_queue<pair<int, pair<int, int>>> pq; // first: cost, second: next point
	dist[sx][sy] = cave[sx][sy];
	pq.push({ -dist[sx][sy], {sx, sy} });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_x = pq.top().second.first;
		int cur_y = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dir[i][0];
			int ny = cur_y + dir[i][1];
			
			if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
			if (dist[nx][ny] > cur_dist + cave[nx][ny]) {
				dist[nx][ny] = cur_dist + cave[nx][ny];
				pq.push({ -dist[nx][ny], {nx, ny} });
			}
		}
	}
}

int main()
{
	int tc = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &cave[i][j]);
			}
		}
		dijkstra(0, 0);

		printf("Problem %d: %d\n", tc, dist[n - 1][n - 1]);
		tc++;
	}

	return 0;
}
