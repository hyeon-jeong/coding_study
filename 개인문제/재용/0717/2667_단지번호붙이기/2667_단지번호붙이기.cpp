// 2667_단지번호붙이기.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdio>
#define MAX 26

int n; // 지도 크기
int map[MAX][MAX] = { 0, }; // 지도
int visit[MAX][MAX] = { 0, }; // 방문 표시
int direction[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // 연결 방향
priority_queue<int, vector<int>, greater<int>> houses; // 각 단지 내의 집 개수
int cnt; // 한 단지 내에 있는 집의 개수

/*
void dfs(int x, int y) {
	cnt++;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];

		if (nx < n && nx >= 0 && ny < n && ny >= 0) {
			if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
				dfs(nx, ny);
			}
		}
	}
}
*/

// cnt를 함수 내에서 리턴하면 백준이 틀렸다고 하는데 그냥 cnt를 전역변수로 설정하고 계산하면 백준이 맞았다고 함
// 이유를 모르겠음 그냥 빡침
// 매우매우 빡침
// 앞으로 bfs, dfs는 모두 void로 해버리자...
void bfs(int a, int b) { 
	queue<pair<int, int>> q;
	cnt++;
	visit[a][b] = 1;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];

			if (nx < n && nx >= 0 && ny < n && ny >= 0) {
				if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					cnt++;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				cnt = 0;
				bfs(i, j);
				houses.push(cnt);
			}
		}
	}
	int size = houses.size();
	printf("%d\n", size);
	while (!houses.empty()) {
		printf("%d\n", houses.top());
		houses.pop();
	}

	return 0;
}
