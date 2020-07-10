// 1260_DFS와_BFS.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

vector<int> *graph;
vector<bool> visited;

void dfs(int start) {
	// 이미 시작점 방문한 경우 빠져나옴
	if (visited[start] == true) return;

	visited[start] = true; // 방문
	printf("%d ", start);

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i]; // start와 연결된 다음 정점
		if (visited[next] == false) { // 아직 방문 안했으면 방문
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;

	if (visited[start] == true) return;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int temp = q.front(); // 큐의 맨 앞 정점 꺼냄
		q.pop();
		printf("%d ", temp);
		for (int i = 0; i < graph[temp].size(); i++) {
			int next = graph[temp][i]; // 큐에서 꺼낸 정점과 연결된 정점
			if (visited[next] == false) { // 아직 방문 안했다면
				visited[next] = true; // 방문 표시
				q.push(next); // 큐에 넣기
			}
		}
	}
}

int main()
{
	int n, m;
	int start;
	scanf("%d %d %d", &n, &m, &start);
	graph = new vector<int>[n + 1];
	visited.assign(n + 1, false);
	
	for (int i = 0; i < m; i++) { // 그래프 구현(양방향)
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) { // 정점을 순차적으로 방문하기 위해 정렬
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start);
	printf("\n");
	visited.assign(n + 1, false); // BFS 사용을 위해 다시 초기화
	bfs(start);

	return 0;
}
