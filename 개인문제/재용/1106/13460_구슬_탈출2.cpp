// 13460_구슬_탈출2.cpp
using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
#define MAX 11

int n, m;
char map[MAX][MAX];
int visited[MAX][MAX][MAX][MAX] = { 0, };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // 오른쪽, 왼쪽, 아래, 위
int ox, oy;

int bfs(int rx, int ry, int bx, int by) {
	int answer = 0;
	queue<tuple<int, int, int, int, int>> q;
	visited[rx][ry][bx][by] = 1;
	q.emplace(rx, ry, bx, by, answer);

	while (!q.empty()) {
		int rx1 = get<0>(q.front());
		int ry1 = get<1>(q.front());
		int bx1 = get<2>(q.front());
		int by1 = get<3>(q.front());
		int cur = get<4>(q.front());

		q.pop();

		if (cur > 10) {
			answer = -1;
			break;
		}

		if (rx1 == ox && ry1 == oy) {
			answer = cur;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nrx = rx1;
			int nry = ry1;
			int nbx = bx1;
			int nby = by1;

			while (true) { // 빨간 구슬 이동
				nrx += dir[i][0];
				nry += dir[i][1];
				if (map[nrx][nry] == '#') {
					nrx -= dir[i][0];
					nry -= dir[i][1];
					break;
				}
				if (map[nrx][nry] == 'O') break;
			}

			while (true) { // 파란 구슬 이동
				nbx += dir[i][0];
				nby += dir[i][1];
				if (map[nbx][nby] == '#') {
					nbx -= dir[i][0];
					nby -= dir[i][1];
					break;
				}
				if (map[nbx][nby] == 'O') break;
			}

			// 파란 구슬이 구멍에 빠지면 continue
			if (nbx == ox && nby == oy) continue;
			
			// 파란 구슬과 빨간 구슬이 같은 위치일 때 위치 조정
			if (nrx == nbx && nry == nby) {
				switch (i) {
					case 0: // 오른쪽
						ry1 > by1 ? nby-- : nry--; break;
					case 1: // 왼쪽
						ry1 < by1 ? nby++ : nry++; break;
					case 2: // 아래
						rx1 > bx1 ? nbx-- : nrx--; break;
					case 3: // 위
						rx1 < bx1 ? nbx++ : nrx++; break;
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = 1;
			q.emplace(nrx, nry, nbx, nby, cur + 1);
		}
	}

	return answer;
}

int main() {
	int rx, ry, bx, by;
	scanf("%d %d", &n, &m);
	memset(map, '#', sizeof(map));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (map[i][j] == 'O') {
				ox = i;
				oy = j;
			}
		}
	}
	int result = bfs(rx, ry, bx, by);
	if (result == 0) result = -1;
	printf("%d\n", result);

	return 0;
}
