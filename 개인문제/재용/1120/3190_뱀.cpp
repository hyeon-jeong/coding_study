// 3190_뱀.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#define MAX 101

int n, k, l;
int board[MAX][MAX] = { 0, };
int direction[4][2] = { { 0, 1 }, { 1, 0 }, {0, -1}, {-1, 0} }; // right, down, left, up
int cur_dir = 0; // right
int time = 0;
deque<pair<int, int>> snake;

void change_dir(char ndir) { // 방향 전환
	switch (ndir) {
		case 'L': // 왼쪽 90도 회전
			if (cur_dir == 0) {
				cur_dir = 3;
			}
			else {
				cur_dir -= 1;
			}
			break;
		case 'D': // 오른쪽 90도 회전
			cur_dir = (cur_dir + 1) % 4;
			break;
	}
}

bool is_move() { // 움직일 수 있으면 true
	pair<int, int> cur_head = snake.front();
	int nx = cur_head.first + direction[cur_dir][0];
	int ny = cur_head.second + direction[cur_dir][1];

	if (nx > n || ny > n || nx < 1 || ny < 1) return false; // 벽에 부딛히는 경우
	if (board[nx][ny] == -1) return false; // 몸에 부딛히는 경우

	snake.push_front({ nx, ny }); // 뱀 머리 이동
	if (board[nx][ny] != 1) { // 사과가 없으면
		board[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	board[nx][ny] = -1;
	return true;
}

int main() {
	scanf("%d", &n); // 보드 크기
	scanf("%d", &k); // 사과 개수
	for (int i = 0; i < k; i++) { // 사과 위치 저장
		int a, b;
		scanf("%d %d", &a, &b);
		board[a][b] = 1; // 사과 있으면 1로 표시
	}

	snake.push_back({ 1, 1 }); // 뱀 머리
	board[1][1] = -1; // 뱀의 몸이 있는 부분은 -1로 표시

	scanf("%d", &l); // 방향 전환 횟수
	queue<pair<int, char>> q;
	for (int i = 0; i < l; i++) {
		int X;
		char C;
		scanf("%d %c", &X, &C);
		q.push({ X, C });
	}

	while (true) {
		if (time == q.front().first) { // 방향 전환
			char ndir = q.front().second;
			q.pop();
			change_dir(ndir);
		}
		if (!is_move()) { // 이동 불가할 때
			printf("%d\n", time + 1); // 시간 출력
			break;
		}
		time++;
	}

	return 0;
}
