// 지형이동.cpp
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <tuple>
#include <stdlib.h> 
using namespace std;
#define MAX 300

struct edge { // 간선 구조체
	pair<int, int> next; // 연결된 노드의 좌표
	int h; // 두 노드 사이의 높이차
};

struct compare { // 높이차 오름차순
	bool operator()(edge a, edge b) {
		return a.h > b.h;
	}
};

int visited[MAX][MAX] = { 0, };
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int solution(vector<vector<int>> land, int height) {
	int answer = 0;
	int n = land.size();
	
	priority_queue<edge, vector<edge>, compare> pq; // 높이차 오름차순으로 노드 정렬
	int x = 0, y = 0; // 시작점: (0, 0)
	for (int i = 0; i < 4; i++) { // 시작점과 연결된 모든 노드들을 우선순위 큐에 삽입
		int nx, ny;
		nx = x + direction[i][0];
		ny = y + direction[i][1];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		edge e;
		e.next = make_pair(nx, ny);
		e.h = abs(land[nx][ny] - land[x][y]);
		pq.push(e);
	}
	
	visited[0][0] = 1; // 시작점 방문표시

	while (!pq.empty()) {
		pair<int, int> next = pq.top().next;
		int h = pq.top().h;
		pq.pop(); // 높이차가 최소인 노드 꺼냄

		int x = next.first;
		int y = next.second;

		if (visited[x][y] == 0) { // 큐에서 꺼낸 점 아직 방문 안했고
			if (h > height) { // 높이차가 허용 높이보다 크면
				answer = answer + h; // 비용 증가
			}
			visited[x][y] = 1;
			for (int i = 0; i < 4; i++) { // 해당 노드와 연결된 모든 노드 큐에 추가
				int nx, ny;
				nx = x + direction[i][0];
				ny = y + direction[i][1];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (visited[nx][ny] == 0) {
					edge e;
					e.next = make_pair(nx, ny);
					e.h = abs(land[nx][ny] - land[x][y]);
					pq.push(e);
				}
			}
		}
	}

	return answer;
}
