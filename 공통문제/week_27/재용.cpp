// 20058_마법사_상어와_파이어스톰
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 65

int n, q;
int A[MAX][MAX] = { 0, };
int temp[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // right, left, up, down

void rotate_part(int x, int y, int len) { // (x, y) : 기준점, len : 정사각형 한 변의 길이	
	memset(temp, 0, sizeof(temp));

	/* 회전된 부분 정사각형을 temp에 저장 */
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			temp[j][len - 1 - i] = A[x + i][y + j];
		}
	}

	/* 저장한 temp를 A에 옮김 */
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			A[x + i][y + j] = temp[i][j];
		}
	}
}

void rotate_whole(int level) {
	int len = 1 << level;
	for (int x = 0; x < n; x += len) {
		for (int y = 0; y < n; y += len) {
			/* (x, y) : 회전 기준 좌표 */
			rotate_part(x, y, len);
		}
	}
}

void melting() {
	/* 얼음 녹일 위치를 따로 저장하는 배열 */
	int locate[MAX][MAX] = { 0, };

	/* 얼음 녹일 위치 찾기 */
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			int count = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (A[nx][ny] <= 0) continue;
				count += 1;
			}
			/* 인접한 얼음이 3개 미만인 경우 */
			if (count < 3) locate[x][y] = 1;
		}
	}

	/* 얼음 녹이기 */
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (locate[x][y] == 1) A[x][y] -= 1;
		}
	}
}

/* 전체 얼음 수 */
int total_ice() {
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] <= 0) continue;
			total += A[i][j];
		}
	}

	return total;
}

/* 얼음 덩어리의 크기를 계산하는 BFS */
int bfs(int x, int y) {
	int ice = 1;
	queue<pair<int, int>> q;
	
	visited[x][y] = 1;
	q.emplace(x, y);

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dir[i][0];
			int ny = cur_y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] == 1 || A[nx][ny] <= 0) continue;

			ice += 1;
			visited[nx][ny] = 1;
			q.emplace(nx, ny);
		}
	}

	return ice;
}

int max_ice() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
      			/* A[i][j] == 0으로 조건 설정하면 개수를 잘못 셈 (이유는 모르겠음) */
			if (visited[i][j] == 1 || A[i][j] <= 0) continue;
			answer = max(answer, bfs(i, j));
		}
	}

	return answer;
}

int main() {
	int N;
	scanf("%d %d", &N, &q);

	/* ^는 제곱이 아니라 XOR... */
	/* 제곱 쓸거면 <cmath> include해서 pow 사용하기 */
	/* 2의 제곱은 shift 연산 사용 */
	n = 1 << N;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < q; i++) {
		int level;
		scanf("%d", &level);
		
		rotate_whole(level);
		melting();
	}

	int sum = total_ice();
	int large_ice = max_ice();
	printf("%d\n", sum);
	printf("%d\n", large_ice);

	return 0;
}
