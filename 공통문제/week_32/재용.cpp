// 1800_인터넷_설치.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 987654321

int N, P, K; // 연결할 pc, 케이블선 개수, 공짜 케이블선 개수
vector<pair<int, int>> network[MAX];
int dist[MAX];

bool dijkstra(int mid) {
	for (int i = 0; i <= N; i++) dist[i] = INF;

	priority_queue<pair<int, int>> pq; // first: cost, second: next point
	dist[1] = 0;
	pq.emplace(0, 1);

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		if (dist[cur] < cur_dist) continue;
		for (auto p : network[cur]) {
			int next = p.first;
			int next_cost = cur_dist + (p.second > mid); // mid보다 가중치가 크면 1, 작으면 0

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.emplace(-next_cost, next);
			}
		}
	}

	return dist[N] <= K; // 가중치가 mid보다 크거나 같은 케이블의 개수가 K개 이하이면 true
}

int main() {
	scanf("%d %d %d", &N, &P, &K);
	int maxV;
	for (int i = 0; i < P; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		network[a].push_back({ b, cost });
		network[b].push_back({ a, cost });
		maxV = max(maxV, cost);
	}

	int answer = -1;

	int minV = 0;

	while (minV <= maxV) {
		int mid = (maxV + minV) / 2;
		if (dijkstra(mid)) { // N번까지 연결된 케이블들 중 가중치가 mid보다 크거나 같은 케이블의 개수가 K개 이하일 경우
			answer = mid;
			maxV = mid - 1; // mid를 낮추기
		}
		else {
			minV = mid + 1; // mid를 올리기
		}
	}

	printf("%d\n", answer);

	return 0;
}
