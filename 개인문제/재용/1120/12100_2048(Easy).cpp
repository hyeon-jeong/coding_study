// 12100_2048(Easy).cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 20

int n;
int board[MAX][MAX];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // right, left, down, up
int answer = 0;

void move(int dir) {
	queue<int> q;
	if (dir == 3) { // up
		/* 왼쪽 열부터 순서대로 */
		for (int col = 0; col < n; col++) {
			/* 위에서부터 순서대로 블록 큐에 삽입 */
			for (int row = 0; row < n; row++) { 
				if (board[row][col] != 0) q.push(board[row][col]);
				board[row][col] = 0;
			}

			int idx = 0;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (board[idx][col] == 0) { // 빈칸인 경우
					board[idx][col] = block; // block 채우기
				}
				else if (board[idx][col] == block) { // 윗칸과 block 숫자가 같으면
					board[idx][col] *= 2;
					idx++;
				}
				else { // 위에 이미 블록이 있으면
					board[++idx][col] = block; // 바로 아래칸에 블록 채움
				}
			}
		}
	}
	else if (dir == 1) { // left
		/* 위의 행부터 순서대로 */
		for (int row = 0; row < n; row++) {
			/* 왼쪽에서부터 순서대로 블록 큐에 삽입 */
			for (int col = 0; col < n; col++) {
				if (board[row][col] != 0) q.push(board[row][col]);
				board[row][col] = 0;
			}

			int idx = 0;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (board[row][idx] == 0) { // 빈칸인 경우
					board[row][idx] = block; // block 채우기
				}
				else if (board[row][idx] == block) { // 왼쪽 칸과 block 숫자가 같으면
					board[row][idx] *= 2;
					idx++;
				}
				else { // 왼쪽에 이미 블록이 있으면
					board[row][++idx] = block; // 바로 오른쪽칸에 블록 채움
				}
			}
		}
	}
	else if (dir == 2) { // down
		/* 왼쪽 열부터 순서대로 */
		for (int col = 0; col < n; col++) {
			/* 아래에서부터 순서대로 블록 큐에 삽입 */
			for (int row = n - 1; row >= 0; row--) {
				if (board[row][col] != 0) q.push(board[row][col]);
				board[row][col] = 0;
			}

			int idx = n - 1;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (board[idx][col] == 0) { // 빈칸인 경우
					board[idx][col] = block; // block 채우기
				}
				else if (board[idx][col] == block) { // 윗칸과 block 숫자가 같으면
					board[idx][col] *= 2;
					idx--;
				}
				else { // 아래에 이미 블록이 있으면
					board[--idx][col] = block; // 바로 윗칸에 블록 채움
				}
			}
		}
	}
	else if (dir == 0) { // right
		/* 위의 행부터 순서대로 */
		for (int row = 0; row < n; row++) {
			/* 오른쪽에서부터 순서대로 블록 큐에 삽입 */
			for (int col = n - 1; col >= 0; col--) {
				if (board[row][col] != 0) q.push(board[row][col]);
				board[row][col] = 0;
			}

			int idx = n - 1;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (board[row][idx] == 0) { // 빈칸인 경우
					board[row][idx] = block; // block 채우기
				}
				else if (board[row][idx] == block) { // 오른쪽 칸과 block 숫자가 같으면
					board[row][idx] *= 2;
					idx--;
				}
				else { // 오른쪽쪽에 이미 블록이 있으면
					board[row][--idx] = block; // 바로 왼쪽칸에 블록 채움
				}
			}
		}
	}
}

int find_max() {
	int maximum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maximum < board[i][j]) maximum = board[i][j];
		}
	}

	return maximum;
}

void dfs(int cnt) {
	if (cnt == 5) {
		answer = max(answer, find_max());
		return;
	}

	/* 원래 보드 상태 저장 */
	int temp[MAX][MAX];
	memcpy(temp, board, sizeof(board));

	/* 각 방향으로 움직여보기 */
	for (int d = 0; d < 4; d++) {
		move(d);
		dfs(cnt + 1);

		/* board를 원래 상태로 되돌리기 */
		memcpy(board, temp, sizeof(temp));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	dfs(0);

	printf("%d\n", answer);
	return 0;
}
