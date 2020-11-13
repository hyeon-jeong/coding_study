// 1504_특정한_최단경로.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#define MAX 801
#define INF 800001

int n, e;
vector<pair<int, int>> graph[MAX];
int dist[MAX] = { INF, };

void dijkstra(int start) {
	memset(dist, INF, sizeof(dist));

	priority_queue<pair<int, int>> pq; // first: cost, second: next point
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (auto& p : graph[cur]) {
			int next = p.first;
			int next_cost = p.second;
			
			if (dist[next] > cur_dist + next_cost) {
				dist[next] = cur_dist + next_cost;
				pq.emplace(-dist[next], next);
			}
		}
	}
}

int main()
{
	int answer;

	scanf("%d %d", &n, &e);
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	int v1, v2;
	scanf("%d %d", &v1, &v2);

	bool flag_v1 = true;
	bool flag_v2 = true;

	/* 1 -> v1 or 1 -> v2 */
	dijkstra(1);
	int path_v1 = dist[v1]; // 1 -> v1 -> v2 -> n
	int path_v2 = dist[v2]; // 1 -> v2 -> v1 -> n
	if (path_v1 == INF) flag_v1 = false;
	if (path_v2 == INF) flag_v2 = false;

	/* 1- > v1 -> v2 or 1 -> v2 -> v1 */
	/* v2 -> v1이나 v1 -> v2의 거리는 같다 */
	dijkstra(v1);
	if (flag_v1) path_v1 += dist[v2];
	if (flag_v2) path_v2 += dist[v2];

	/* v1 -> v2 -> n */
	dijkstra(v2);
	if (flag_v1) path_v1 += dist[n];

	/* v2 -> v1 -> n */
	dijkstra(v1);
	if (flag_v2) path_v2 += dist[n];

	if (flag_v1 == false && flag_v2 == false) answer = -1;
	else {
		answer = min(path_v1, path_v2);
	}
	if (answer >= INF) answer = -1;

	printf("%d\n", answer);
}
