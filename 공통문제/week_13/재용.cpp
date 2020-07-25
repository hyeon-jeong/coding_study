// 카카오_블록_이동하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <set>
#define MAX 102
using namespace std;

int board[MAX][MAX];
int visited[MAX][MAX][MAX][MAX] = { 0, };

vector<tuple<int, int, int, int>> able_path(int a, int b, int c, int d, vector<vector<int>> board) {
	int n = board.size();
	int non_rotate[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	vector<tuple<int, int, int, int>> available;

	for (int i = 0; i < 4; i++) { // 상하좌우 이동
		int na = a + non_rotate[i][0], nb = b + non_rotate[i][1];
		int nc = c + non_rotate[i][0], nd = d + non_rotate[i][1];

		if (na < 0 || nb < 0 || nc < 0 || nd < 0
			|| na >= n || nb >= n || nc >= n || nd >= n) continue;
		if (board[na][nb] == 0 && board[nc][nd] == 0) {
			available.push_back(make_tuple(na, nb, nc, nd));
		}
	}

	int rotate[2] = { 1, -1 };
	// 가로 상태에서 회전
	if (a == c) {
		for (int i = 0; i < 2; i++) {
			int na = a + rotate[i];
			int nc = c + rotate[i];
			if (na < 0 || na >= n || nc < 0 || nc >= n) continue;
			if (board[na][b] == 0 && board[nc][d] == 0) {
				available.push_back(make_tuple(a, b, na, b));
				available.push_back(make_tuple(c, d, nc, d));
			}
		}
	}

	// 세로 상태에서 회전
	else {
		for (int i = 0; i < 2; i++) {
			int nb = b + rotate[i];
			int nd = d + rotate[i];
			if (nb < 0 || nb >= n || nd < 0 || nd >= n) continue;
			if (board[a][nb] == 0 && board[c][nd] == 0) {
				available.push_back(make_tuple(a, b, a, nb));
				available.push_back(make_tuple(c, d, c, nd));
			}
		}
	}
	return available;
}


int solution(vector<vector<int>> board) {
	int answer = 0;
	int n = board.size();

	queue<tuple<int, int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 1, 0)); // 시작 지점 = (1, 1), (1, 2), 시간(초) = 0
	visited[0][0][0][1] = 1;

	while (!q.empty()) {
		int x1, y1, x2, y2, time;
		tie(x1, y1, x2, y2, time) = q.front();
		q.pop();

		if ((x1 == n - 1 && y1 == n - 1)
			|| (x2 == n - 1 && y2 == n - 1)) {
			answer = time;
			break;
		}

		vector<tuple<int, int, int, int>> direction = able_path(x1, y1, x2, y2, board);
		for (int i = 0; i < direction.size(); i++) {
			int nx1, ny1, nx2, ny2;
			tie(nx1, ny1, nx2, ny2) = direction[i];
			if (visited[nx1][ny1][nx2][ny2] == 0 && visited[nx2][ny2][nx1][ny1] == 0) { // 아직 방문 안했으면
				visited[nx1][ny1][nx2][ny2] = 1;
				q.emplace(nx1, ny1, nx2, ny2, time + 1);
			}
		}
	}

	return answer;
}
