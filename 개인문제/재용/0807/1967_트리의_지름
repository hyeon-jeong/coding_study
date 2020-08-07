using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 10001

int n;
vector<pair<int, int>> graph[MAX]; // first: 자식, second: 가중치
int visited[MAX] = { 0, };
int result = 0; // 트리의 지름 길이
int end_point; // 트리의 지름 끝점

void dfs(int start, int distance) {
	if (visited[start] == 1) return;
	visited[start] = 1;

	if (result < distance) {
		result = distance;
		end_point = start;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i].first;
		int weight = graph[start][i].second;
		if (visited[next] == 0) {
			dfs(next, distance + weight);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		graph[x].emplace_back(y, w);
		graph[y].emplace_back(x, w);
	}

	dfs(1, 0); // 루트에서부터 가장 거리가 먼 끝점 구함

	// 초기화
	memset(visited, 0, sizeof(visited));
	result = 0;

	dfs(end_point, 0); // 끝점에서부터 가장 거리가 먼 곳까지의 거리 구함
	printf("%d\n", result);
}
