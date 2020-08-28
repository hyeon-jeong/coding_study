// 16236_아기상어.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 20

/* 공간 관련 변수 초기화 */
int n; // 공간 크기
int map[20][20]; // 공간 정보
int visited[20][20]; // 방문 시간
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

/* 상어 관련 변수 */
int baby_size = 2; // 아기상어 현재 크기
int eat = 0; // 아기상어가 먹은 물고기 수
int min_dist; // 최단 경로 길이
pair<int, int> min_loc; // 최단 경로 좌표

void init() { // BFS를 위한 초기화
	memset(visited, -1, sizeof(visited));
	min_dist = 400;
	min_loc = { 20, 20 };
}

void bfs(pair<int, int> s) {
	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = 0; // 시작점 방문 시간 = 0

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];

			if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
			if (visited[nx][ny] != -1 || map[nx][ny] > baby_size) continue; // 이미 방문한 곳 or 아기상어보다 큰 물고기가 있는 곳은 못감

			visited[nx][ny] = visited[x][y] + 1; // 방문 시간 증가
			if (map[nx][ny] != 0 && map[nx][ny] < baby_size) { // 물고기를 먹을 수 있는 경우
				if (min_dist > visited[nx][ny]) { // 가장 가까운 곳에 있는 물고기 먹음
					min_dist = visited[nx][ny];
					min_loc = { nx, ny };
				}
				/* 가까운 곳에 있는 물고기가 여러 마리인 경우 */
				else if (min_dist == visited[nx][ny]) { // 위 -> 왼쪽 있는 물고기 먹음
					// 가장 위인 경우, 가장 왼쪽에 있는 물고기 먹음
					if (min_loc.first == nx) { 
						if (min_loc.second > ny) {
							min_loc = { nx, ny };
						}
					}
					// 가장 위에 있는 물고기 먹음
					else if (min_loc.first > nx) {
						min_loc = { nx, ny };
					}
				}
			}
			q.push({ nx, ny });
		}
	}
}

int main()
{
	scanf("%d", &n);

	pair<int, int> start; // 아기상어가 있는 지점

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) { // 아기상어 위치 저장
				start.first = i;
				start.second = j;
				map[i][j] = 0; // 아기상어 위치를 0으로 초기화
			}
		}
	}

	int result = 0;
	while (true) {
		init(); // BFS 초기화
		bfs(start);

		if (min_loc.first != 20 && min_loc.second != 20) { // 먹을 수 있는 물고기 찾으면
			result += visited[min_loc.first][min_loc.second]; // 시간 증가
			eat += 1;

			if (eat == baby_size) { // 아기상어 크기만큼 물고기를 먹었으면
				baby_size += 1; // 아기상어 크기 증가
				eat = 0; // 먹은 물고기 수 초기화
			}
			map[min_loc.first][min_loc.second] = 0; // 물고기가 있던 자리는 0으로 초기화
			start = min_loc;
		}
		else break; // 더 이상 먹을 물고기가 없으면 break
	}

	printf("%d\n", result);
	return 0;
}

