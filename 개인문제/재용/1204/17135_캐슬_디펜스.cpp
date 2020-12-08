// 17135_캐슬_디펜스.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 15

struct Archer { // 궁수의 위치
	int x, y;
};

struct Enemy {
	int num; // 적의 수 == 1;
	bool flag; // 중복을 고려한 flag
};

Archer arc[3];
Enemy map[MAX + 1][MAX];

int n, m; // 좌표 크기
int d; // 사정거리

int answer; // 죽일 수 있는 적의 최대값
int kill; // 한 경우에 대해 죽일 수 있는 적의 수

void advance() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].num == 0) continue;

			/* 적이 존재할 때 */
			map[i][j].num = 0; // 0으로 비우고

			int nx = i + 1;
			if (nx >= n) continue;
			map[nx][j].num = 1; // 다음 행으로 이동
		}
	}
}

int dist(int sx, int sy, int ex, int ey) { // 거리 구하기
	int d = abs(sx - ex) + abs(sy - ey);

	return d;
}

int countEnemy() { // 남은 적의 수 count
	int rest = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].num == 1) rest++;
		}
	}

	return rest;
}

void findEnemy(int ax, int ay, int d) { // 공격 가능한 적의 위치 찾기
	int ex = -1;
	int ey = -1;
	int min_dist = d + 1;

	for (int i = ax - 1; i >= ax - d; i--) {
		for (int j = ay - d; j <= ay + d; j++) {
			if (i < 0 || j < 0 || i >= n || j >= m) continue;
			if (dist(ax, ay, i, j) > d) continue;

			if (map[i][j].num == 1) {
				if (dist(ax, ay, i, j) < min_dist) {
					min_dist = dist(ax, ay, i, j);
					ex = i;
					ey = j;
				}
				else if (dist(ax, ay, i, j) == min_dist) {
					if (ey > j) {
						ex = i;
						ey = j;
					}
				}
			}
		}
	}

	if(min_dist <= d && map[ex][ey].num == 1) map[ex][ey].flag = true;
}

void killEnemy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].num == 1 && map[i][j].flag == true) {
				map[i][j].num = 0;
				map[i][j].num = false;
				kill++;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j].num);
			map[i][j].flag = false;
		}
	}

	arc[0].x = n;
	arc[1].x = n;
	arc[2].x = n;

	answer = 0;
	Enemy temp[MAX + 1][MAX];
	memcpy(temp, map, sizeof(map));

	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				arc[0].y = i;
				arc[1].y = j;
				arc[2].y = k;

				memcpy(map, temp, sizeof(temp));

				kill = 0;

				int flag = countEnemy();
				while (flag > 0) {
					for (int a = 0; a < 3; a++) {
						int x = arc[a].x;
						int y = arc[a].y;
						findEnemy(x, y, d);
					}
					killEnemy();
					advance();
					flag = countEnemy();
				}
				if (answer < kill) {
					answer = kill;
				}
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}
