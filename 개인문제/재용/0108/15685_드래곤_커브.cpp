// 15685_드래곤_커브.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 101

int n;
int map[MAX][MAX] = { 0, };
// 0(right), 1(up), 2(left), 3(down) 방향
int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

// 규칙
/*
	0세대: 0
	1세대: 0 1
	2세대: 0 1 / 2 1
	3세대: 0 1 2 1 / 2 3 2 1
	(이전 세대 역순으로 +1)
*/

// 정사각형 개수
int cntSquare() {
	int result = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
				result++;
			}
		}
	}

	return result;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		
		/* 커브 방향 지정 */
		vector<int> curve;
		curve.push_back(d);
		for (int j = 0; j < g; j++) {
			vector<int> temp = curve;
			for (int k = temp.size() - 1; k >= 0; k--) {
				curve.push_back((temp[k] + 1) % 4);
			}
		}

		/* 커브 방향을 토대로 map에 커브 표시 */
		map[y][x] = 1;
		for (int j = 0; j < curve.size(); j++) {
			y += dir[curve[j]][0];
			x += dir[curve[j]][1];

			if (x < 0 || y < 0 || x >= MAX || y >= MAX) continue;
			map[y][x] = 1;
		}
	}

	printf("%d\n", cntSquare());
}
