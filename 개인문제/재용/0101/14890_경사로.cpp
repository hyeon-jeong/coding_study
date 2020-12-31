// 14890_경사로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 100

int map[MAX][MAX]; // 가로 길
int map2[MAX][MAX]; // 세로 길
int N, L;

int buildRoad(int maps[][MAX]) {
	int result = 0; // 가능한 도로 개수

	for (int i = 0; i < N; i++) {
		int cnt = 1; // 높이가 같은 칸의 개수
		bool makeRoad = true;
		for (int j = 1; j < N; j++) {
			/* 높이차가 2 이상이면 길이 될 수 없음 */
			if (abs(maps[i][j] - maps[i][j - 1]) > 1) {
				makeRoad = false;
				break;
			}
			else { // 높이차가 1 이하인 경우
				/* 높이차가 같은 경우 */
				if (maps[i][j] == maps[i][j - 1]) cnt++;

				/* 뒷부분이 더 높은 경우 */
				else if (maps[i][j] == maps[i][j - 1] + 1) {
					if (cnt >= L) { // 앞부분에 다리를 놓을 수 있으면
						cnt = 1; // cnt 초기화
					}
					else {
						makeRoad = false;
						break;
					}
				}

				/* 뒷부분이 더 낮은 경우 */
				else if (maps[i][j] + 1 == maps[i][j - 1]) {
					int base = maps[i][j];
					bool flag = true;
					for (int y = j; y < j + L; y++) {
						if (maps[i][y] != base) flag = false;
					}

					if (flag) {
						j = j + L - 1;
						cnt = 0;
					}
					else {
						makeRoad = false;
						break;
					}
				}
			}
		}
		if (makeRoad) result++;
	}

	return result;
}

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map2[j][i] = map[i][j];
		}
	}

	int width = buildRoad(map);
	int height = buildRoad(map2);

	int answer = width + height;
	printf("%d\n", answer);
}
