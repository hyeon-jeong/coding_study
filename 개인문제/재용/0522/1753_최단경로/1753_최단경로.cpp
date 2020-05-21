// 1753_최단경로.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000
#define MAX 20000 + 1

int v; // 정점의 개수
int e; // 간선의 개수
vector<pair<int, int>> W[MAX]; // first: 도착점, second: 가중치

void dijkstra(int start) {
	vector<bool> visited(v + 1, false); // 방문 여부 저장
	vector<int> dist(v + 1, INF); // 시작점에서 특정 정점까지의 최단 거리 저장

	dist[start] = 0; // 시작점 자기 자신의 가중치 = 0
	priority_queue<pair<int, int>> pq; // first: 음수 가중치, second: 도착점
	pq.emplace(0, start); // 시작점 우선순위 큐에 삽입

	while (!pq.empty()) {
		/* 가중치가 가장 작은 간선의 도착점 pop */
		int vnear = pq.top().second;
		pq.pop();

		if (visited[vnear]) continue; // 우선순위 큐에서 꺼낸 정점이 이미 방문한 점이면 continue
		visited[vnear] = true; // 우선순위 큐에서 꺼낸 정점 방문 표시

		for (int i = 0; i < W[vnear].size(); i++) { // 현재 정점(current)과 연결된 간선들 중에서
			pair<int, int> edge = W[vnear][i]; // first: 도착점, second: 가중치
			int next = edge.first;
			int weight = edge.second;

			if (dist[next] > dist[vnear] + weight) { // 시작점에서 next 정점까지 가는 비용보다 vnear을 거쳐서 가는 비용이 더 작을 때
				dist[next] = dist[vnear] + weight; // dist[next] 갱신
				pq.emplace(-dist[next], next); // 시작점과 next 사이의 간선을 우선순위 큐에 삽입
			}
		}
	}

	/* 최단경로값 출력 */
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e; // 정점 개수, 간선 개수 입력받음

	int start; // 시작점
	cin >> start;

	for (int i = 1; i <= e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		W[from].emplace_back(to, cost);
	}

	dijkstra(start);
}