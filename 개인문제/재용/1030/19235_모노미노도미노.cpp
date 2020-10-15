// 19235_모노미노도미노.cpp
using namespace std;
#include <iostream>
#define GREEN 0
#define BLUE 1

int board[2][10][4] = { 0, }; // green, blue board
int score = 0; // 점수

void move1(int y, int x, int color) { // 1x1
	int label = board[color][y][x];
	board[color][y][x] = 0;
	while (y < 10) {
		if (board[color][y][x] != 0) break;
		y += 1;
	}
	y -= 1;
	board[color][y][x] = label;
}

void move2(int y, int x, int color) { // 1x2 세로
	int label = board[color][y][x];
	board[color][y][x] = 0;
	board[color][y - 1][x] = 0;

	while (y < 10) {
		if (board[color][y][x] != 0) break;
		y += 1;
	}
	y -= 1;
	board[color][y][x] = label;
	board[color][y - 1][x] = label;
}

void move3(int y, int x, int color) { // 2x1 가로
	int label = board[color][y][x];
	board[color][y][x] = 0;
	board[color][y][x + 1] = 0;

	while (y < 10) {
		if (board[color][y][x] != 0 || board[color][y][x + 1] != 0) break;
		y += 1;
	}
	y -= 1;
	board[color][y][x] = label;
	board[color][y][x + 1] = label;
}

void remove(int y, int color) { // 행 제거
	for (int x = 0; x < 4; x++) {
		board[color][y][x] = 0;
	}
}

void move_after_remove(int start_y, int color) {
	int dir[2][2] = { {-1, 0}, { 0, 1 } };
	for (int y = start_y; y >= 4; y--) {
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] == 0) continue;
			int type = 1;
			for (int i = 0; i < 2; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];
				if (nx >= 4 || ny < 4) continue;
				if (board[color][ny][nx] == board[color][y][x]) {
					if (i == 0) type = 2; // 세로
					else type = 3; // 가로
				}
			}

			/* type에 따라 이동시킴 */
			if (type == 1) move1(y, x, color);
			else if (type == 2) move2(y, x, color);
			else if (type == 3) move3(y, x, color);
		}
	}
}

void remove_filled_block(int color) { // 한 행이 꽉 차면 제거
	bool is_remove = false;
	for (int y = 6; y < 10; y++) {
		int count = 0;
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] != 0) count++;
			if (count == 4) {
				is_remove = true;
				score += 1;
				remove(y, color);
				move_after_remove(y - 1, color);
			}
		}
	}

	if (is_remove) { // 옮긴 뒤에 또 찼을 경우 재귀
		remove_filled_block(color); 
	}
}

void remove_overflowed_block(int color) { // 연한 행에 블록이 있을 때
	int count = 0; // 블록이 있는 연한 행 개수
	for (int y = 4; y <= 5; y++) {
		bool overflowed = false;
		for (int x = 0; x < 4; x++) {
			if (board[color][y][x] != 0) {
				overflowed = true;
				break;
			}
		}
		if (overflowed) count += 1;
	}

	if (count > 0) { // 연한 행에 블록이 있으면
		for (int y = 9; y >= 6; y--) { // 뒤로 밀고
			for (int x = 0; x < 4; x++) {
				board[color][y][x] = board[color][y - count][x];
			}
		}
		for (int y = 4; y <= 5; y++) { // 연한 행 비우기
			remove(y, color);
		}
	}
}

void simulate(int type, int x, int color, int label) {
	if (type == 1) {
		board[color][0][x] = label;
		move1(0, x, color);
	}
	else if ((type == 3 && color == GREEN) || (type == 2 && color == BLUE)) { // 세로
		board[color][0][x] = label;
		board[color][1][x] = label;
		move2(1, x, color);
	}
	else if ((type == 2 && color == GREEN) || (type == 3 && color == BLUE)) { // 가로
		board[color][0][x] = label;
		board[color][0][x + 1] = label;
		move3(0, x, color);
	}
	remove_filled_block(color); // 꽉 찬 곳 먼저 삭제 후
	remove_overflowed_block(color); // 연한 행 제거
}

int main() {
	int n; // 블록 놓은 횟수
	int count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t, x, y;
		scanf("%d %d %d", &t, &y, &x);
		simulate(t, x, GREEN, i + 1);
		simulate(t, y, BLUE, i + 1);
	}

	for (int color = 0; color < 2; color++) {
		for (int y = 6; y < 10; y++) {
			for (int x = 0; x < 4; x++) {
				if (board[color][y][x] != 0) count++;
			}
		}
	}

	printf("%d\n%d\n", score, count);

	return 0;
}
