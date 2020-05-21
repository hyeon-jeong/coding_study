// 1916_최소비용_구하기.cpp 
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define INF 1000000000

int n, m;
vector<vector<int>> W; // 두 정점 사이의 거리가 저장된 벡터 (그래프)

void dijkstra(int start, int end) {
	vector<bool> visited(n + 1, false); // 각 정점 방문 여부 저장
	vector<int> dist(n + 1, INF); // start에서 각 정점까지의 최단 거리

	for (int i = 1; i <= n; i++) { // 시작점에서 i번째 정점까지의 비용으로 dist 초기화
		dist[i] = W[start][i];
	}

	int vnear = start; // 현재 상태에서 가장 가까운 정점. 초기값은 시작점
	visited[start] = true; // 시작점 방문 표시

	for (int j = 1; j <= n; j++) {
		int min = INF;
		for (int i = 1; i <= n; i++) { // 방문하지 않은 정점 중, 가장 비용이 작은 정점을 선택
			if (!visited[i] && min > dist[i]) {
				min = dist[i];
				vnear = i;
			}
		}
		visited[vnear] = true; // vnear 방문 표시
		for (int i = 1; i <= n; i++) {
			// 방문하지 않은 정점 중, 해당 정점까지의 버스 노선이 존재하고
			// 시작점에서 i번째 정점까지 가는 비용보다 vnear를 거쳐서 가는 비용이 더 작을 때 dist[i] 갱신
			if (!visited[i] && W[vnear][i] != INF && dist[i] > dist[vnear] + W[vnear][i]) {
				dist[i] = dist[vnear] + W[vnear][i];
			}
		}
	}

	cout << dist[end] << endl;
}


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n; // 도시의 개수
	cin >> m; // 버스의 개수
	W.assign(n + 1, vector<int>(n+1, INF)); // (n+1)*(n+1) W 그래프 INF로 초기화

	for (int i = 1; i <= m; i++) { // 그래프 W에 버스 노선 저장
		int from, to, cost;
		cin >> from >> to >> cost;
		// 같은 노선의 버스가 여러 개 있을 경우, 최단 노선을 저장
		W[from][to] = min(cost, W[from][to]);
	}

	int start, end;
	cin >> start >> end;
	dijkstra(start, end);
}
