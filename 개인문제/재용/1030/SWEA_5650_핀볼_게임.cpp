// SWEA_5650_핀볼_게임.cpp
using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100

int n, answer;
int board[MAX][MAX];
vector<pair<int, int>> v;
pair<pair<int, int>, pair<int, int>> wormhole[5];
bool already_pushed[5];
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // 오른쪽, 왼쪽, 위, 아래

void init() {
	answer = 0;
	memset(board, 0, sizeof(board));
	for (int i = 0; i < 5; i++) {
		wormhole[i].first.first = -1;
		wormhole[i].first.second = -1;
		wormhole[i].second.first = -1;
		wormhole[i].second.second = -1;
		already_pushed[i] = false;
	}
	v.clear();
}

int change_dir(int cur_d, int shape) {
	int nd;
	if (cur_d == 0) {
		if (shape == 1 || shape == 2 || shape == 5) nd = 1;
		else if (shape == 3) nd = 3;
		else if (shape == 4) nd = 2;
	}
	else if (cur_d == 1) {
		if (shape == 3 || shape == 4 || shape == 5) nd = 0;
		else if (shape == 1) nd = 2;
		else if (shape == 2) nd = 3;
	}
	else if (cur_d == 2) {
		if (shape == 1 || shape == 4 || shape == 5) nd = 3;
		else if (shape == 2) nd = 0;
		else if (shape == 3) nd = 1;
	}
	else if (cur_d == 3) {
		if (shape == 2 || shape == 3 || shape == 5) nd = 2;
		else if (shape == 1) nd = 0;
		else if (shape == 4) nd = 1;
	}

	return nd;
}

int move(int x, int y, int d) {
	int sx = x;
	int sy = y;
	int score = 0;

	while (true) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		int nd = d;

		if (nx < n && ny < n && nx >= 0 && ny >= 0) {
			if (board[nx][ny] == -1 || (nx == sx && ny == sy)) break;
			else if (board[nx][ny] >= 1 && board[nx][ny] <= 5) { // block일 경우
				nd = change_dir(d, board[nx][ny]);
				score++;
			}
			else if (board[nx][ny] >= 6 && board[nx][ny] <= 10) { // wormhole일 경우
				if (nx == wormhole[board[nx][ny] - 6].first.first && ny == wormhole[board[nx][ny] - 6].first.second) {
					int tx = wormhole[board[nx][ny] - 6].second.first;
					int ty = wormhole[board[nx][ny] - 6].second.second;
					nx = tx;
					ny = ty;
				}
				else {
					int tx = wormhole[board[nx][ny] - 6].first.first;
					int ty = wormhole[board[nx][ny] - 6].first.second;
					nx = tx;
					ny = ty;
				}
			}
		}
		else { // 범위 벗어나면 방향을 바꿔서 다시 수행
			if (d == 0) nd = 1;
			else if (d == 1) nd = 0;
			else if (d == 2) nd = 3;
			else if (d == 3) nd = 2;
			score++;
		}
		x = nx;
		y = ny;
		d = nd;
	}

	return score;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		
		init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
				if (board[i][j] == 0) v.emplace_back(i, j);
				else if (board[i][j] >= 6 && board[i][j] <= 10) {
					if (!already_pushed[board[i][j] - 6]) {
						wormhole[board[i][j] - 6].first.first = i;
						wormhole[board[i][j] - 6].first.second = j;
						already_pushed[board[i][j] - 6] = true;
					}
					else {
						wormhole[board[i][j] - 6].second.first = i;
						wormhole[board[i][j] - 6].second.second = j;
					}
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			int sx = v[i].first;
			int sy = v[i].second;

			for (int d = 0; d < 4; d++) {
				int temp = move(sx, sy, d);
				answer = max(answer, temp);
			}
		}

		printf("#%d %d\n", tc, answer);
	}
	return 0;
}
