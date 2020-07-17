// 1987_알파벳.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 21

int n, m; // 행, 열
char map[MAX][MAX];
// 한번 지나간 알파벳은 다시 지나갈 수 없기 때문에 visited 배열이 따로 필요가 없음
// "방문 위치"보다 "방문한 알파벳"이 더 중요함
int direction[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // 상하좌우
int answer; // 말이 움직인 최대 칸 수
bool alphabet[26];

// 처음에는 문자로 비교해서 방문 여부를 표시했었는데 시간초과 오류가 발생함
// 문자로 비교하는 것이 숫자로 비교하는 것보다 오래걸리기 때문...
// 따라서 문자를 숫자로 바꿔서 비교해야 시간이 절약됨
void dfs(int x, int y, int count) {
	answer = max(answer, count);
	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m) { // 좌표 범위 내이고
			int check = map[nx][ny] - 'A'; // char 타입의 알파벳을 숫자로 변환(아스키코드)
			if (alphabet[check] == false) { // 아직 방문 안했으면
				alphabet[check] = true;
				dfs(nx, ny, count + 1); // 탐색
				alphabet[check] = false; // 백트래킹 (최적의 경로를 찾기 위함)
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}

	answer = 0;
	alphabet[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	printf("%d\n", answer);

	return 0;
}
