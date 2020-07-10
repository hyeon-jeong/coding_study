// 1868_파핑파핑_지뢰찾기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>

int n; // n x n 크기의 표
char init_map[302][302];
int real_map[302][302] = { 0, };
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} }; // 중심을 기준으로 8방향
int visited[302][302] = { 0, };

void mapping() { // 지도 초기화 함수
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = i;
			int y = j;

			int count = 0; // 주변 지뢰 개수
			if (init_map[x][y] == '*') { // 지뢰가 있는 곳은 -1 
				real_map[x][y] = -1;
				continue;
			}
			for (int k = 0; k < 8; k++) {
				int nx = x + dir[k][0];
				int ny = y + dir[k][1];

				if (init_map[nx][ny] == '*') count++;
				else continue;
			}
			real_map[x][y] = count; // 지뢰가 없는 곳은 숫자 표시
		}
	}
}

void bfs(int a, int b) { // 클릭한 부분의 숫자가 0일 때만 탐색
	queue<pair<int, int>> q;

	visited[a][b] = 1;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx <= n && nx >= 1 && ny >= 1 && ny <= n) { // 다음 좌표가 범위 내이고
				if (!visited[nx][ny]) { // 아직 방문 안했을 때
					visited[nx][ny] = 1; // 해당 좌표 방문 표시
					if (real_map[nx][ny] == 0) q.push(make_pair(nx, ny)); // 해당 좌표의 숫자가 0이면 큐에 push
				}
			}
			else continue;
		}
	}
}

int main()
{
	int T; // test case
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);

		for (int i = 0; i <= n + 1; i++) { // 표 입력받음. 이때, 표의 크기는 원래 표보다 행/열이 +2씩 증가
			for (int j = 0; j <= n + 1; j++) {
				if (i != 0 && i != n + 1 && j != 0 && j != n + 1) {
					char b;
					scanf(" %c", &b);
					if (b == '*') init_map[i][j] = '*';
					else init_map[i][j] = '.';
				}
				else init_map[i][j] = '.';
			}
		}

		mapping(); // 숫자가 표시된 지뢰찾기 표

		int click = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j] && real_map[i][j] == 0) { // 클릭한 부분이 0이면
					bfs(i, j); // bfs 탐색으로 0 주변을 방문 표시
					click++;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j] && real_map[i][j] > 0) { // 클릭한 부분이 0보다 크면
					click++; // 클릭 수 증가
				}
			}
		}
	
		printf("#%d ", tc);
		printf("%d\n", click);
		memset(visited, 0, sizeof(visited)); // 각 test case마다 초기화 안해주면 카운트 잘못됨
	}
}

