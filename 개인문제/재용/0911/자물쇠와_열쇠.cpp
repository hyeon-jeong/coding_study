// 2020_카카오_자물쇠와_열쇠.cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* key 회전 (시계방향) */
vector<vector<int>> rotate(vector<vector<int>> key) { 
	int s = key.size();
	vector<vector<int>> rotated_key(s, vector<int>(s, 0));

	for (int i = 0, x = 0; x < s; i++, x++) {
		for (int j = 0, y = s - 1; y >= 0; j++, y--) {
			rotated_key[i][j] = key[y][x];
		}
	}

	return rotated_key;
}

/* key 삽입 */
int insert(int sx, int sy, int n, int m, vector<vector<int>> board, vector<vector<int>> key) {
	for (int i = sx, x = 0; i < sx + m; i++, x++) {
		for (int j = sy, y = 0; j < sy + m; j++, y++) {
			board[i][j] = board[i][j] ^ key[x][y]; // XOR 연산
		}
	}

	// XOR 연산값이 1이면 key의 돌기와 board의 홈이 맞는 것
	// => 모든 좌표가 1이면 unlock
	int count = 0;
	for (int i = m - 1; i < m + n - 1; i++) {
		for (int j = m - 1; j < m + n - 1; j++) {
			// 1이 아닌 좌표의 개수 count
			if (!board[i][j]) count++;
		}
	}
	return count;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int m = key.size();
	int n = lock.size();
	vector<vector<int>> board(2 * (m - 1) + n, vector<int>(2 * (m - 1) + n, 0));

	/* lock을 board에 배치 */
	for (int nx = m - 1, x = 0; nx < m - 1 + n; nx++, x++) {
		for (int ny = m - 1, y = 0; ny < m - 1 + n; ny++, y++) {
			board[nx][ny] = lock[x][y];
		}
	}
	
	vector<vector<int>> next_key = key;
	for (int i = 0; i < m + n - 1; i++) {
		for (int j = 0; j < m + n - 1; j++) {
			for (int r = 0; r < 4; r++) { // 회전 (4번)
				int isUnlock = insert(i, j, n, m, board, next_key);
				if (isUnlock == 0) { // 1이 아닌 좌표가 없으면 true
					return true;
				}
				else next_key = rotate(next_key);
			}
		}
	}

	return false;
}
