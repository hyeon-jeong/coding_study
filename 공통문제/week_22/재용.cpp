// 10282_해킹.cpp
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#define INF 987654321
#define MAX 10001

int infect; // 감염 컴퓨터 수
int infect_sec; // 마지막 컴퓨터가 감염되기까지 걸린 시간

void dijkstra(vector<vector<pair<int, int>>> graph, int start, int n) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, INF);

	pq.emplace(0, start); // 시작점 push
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_dist = -pq.top().first; // 방문할 점의 dist (감염시간) (오름차순)
		int cur = pq.top().second; // 방문할 정점

		pq.pop();

		for (auto &p : graph[cur]) {
			int next = p.first; // 다음 정점
			int next_dist = p.second + cur_dist; // 다음 정점의 감염시간

			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.emplace(-dist[next], next);
			}
		}
	}

	// 감염된 컴퓨터 수 & 감염 시간 계산
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) { // dist가 INF가 아니면 방문한 것이므로 감염된 것
			infect += 1;
			if (dist[i] > infect_sec) infect_sec = dist[i];
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		int n, d, c;
		scanf("%d %d %d", &n, &d, &c);

		vector<vector<pair<int, int>>> hack(n + 1);
		for (int i = 0; i < d; i++) {
			int a, b, s;
			scanf("%d %d %d", &a, &b, &s);
			hack[b].emplace_back(a, s);
		}

		infect = 0;
		infect_sec = 0;
		dijkstra(hack, c, n);

		printf("%d %d\n", infect, infect_sec);
	}

	return 0;
}
