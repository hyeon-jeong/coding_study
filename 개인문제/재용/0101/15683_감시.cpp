// 15683_감시.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 8
#define INF 100

int office[MAX][MAX]; 
int temp[MAX][MAX];
int n, m;
int answer = INF;

/* 
cctv 정보:
	first.first: x, first.second: y,
	second.first: cctv 번호, second.second: 방향
*/
vector<pair<pair<int, int>, pair<int, int>>> cctv;

/* 각 방향에서의 감시 영역 표시 */
void left(int x, int y) {
	for (int j = y - 1; j >= 0; j--) {
		if (temp[x][j] == 6) break; // 벽을 만나면 종료
		if (temp[x][j] >= 1 && temp[x][j] <= 5) continue; // cctv 만나면 그대로 통과
		temp[x][j] = -1; // 방문표시
	}
}

void right(int x, int y) {
	for (int j = y + 1; j < m; j++) {
		if (temp[x][j] == 6) break; // 벽을 만나면 종료
		if (temp[x][j] >= 1 && temp[x][j] <= 5) continue; // cctv 만나면 그대로 통과
		temp[x][j] = -1; // 방문표시
	}
}

void up(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (temp[i][y] == 6) break; // 벽을 만나면 종료
		if (temp[i][y] >= 1 && temp[i][y] <= 5) continue; // cctv 만나면 그대로 통과
		temp[i][y] = -1; // 방문표시
	}
}

void down(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (temp[i][y] == 6) break; // 벽을 만나면 종료
		if (temp[i][y] >= 1 && temp[i][y] <= 5) continue; // cctv 만나면 그대로 통과
		temp[i][y] = -1; // 방문표시
	}
}

void checkCCTV() {
	memcpy(temp, office, sizeof(office));

	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].first.first;
		int y = cctv[i].first.second;
		int cctvNum = cctv[i].second.first;
		int dir = cctv[i].second.second;

		if (cctvNum == 1) { // 한 방향
			if (dir == 0) left(x, y);
			else if (dir == 1) right(x, y);
			else if (dir == 2) up(x, y);
			else if (dir == 3) down(x, y);
		}
		else if (cctvNum == 2) { // 양 옆
			if (dir == 0 || dir == 1) {
				left(x, y);
				right(x, y);
			}
			else if (dir == 2 || dir == 3) {
				up(x, y);
				down(x, y);
			}
		}
		else if (cctvNum == 3) { // 직각
			if (dir == 0) {
				up(x, y);
				left(x, y);
			}
			else if (dir == 1) {
				up(x, y);
				right(x, y);
			}
			else if (dir == 2) {
				down(x, y);
				left(x, y);
			}
			else if (dir == 3) {
				down(x, y);
				right(x, y);
			}
		}
		else if (cctvNum == 4) { // ㅗ방향
			if (dir == 0) {
				up(x, y);
				left(x, y);
				right(x, y);
			}
			else if (dir == 1) {
				up(x, y);
				right(x, y);
				down(x, y);
			}
			else if (dir == 2) {
				down(x, y);
				left(x, y);
				up(x, y);
			}
			else if (dir == 3) {
				down(x, y);
				right(x, y);
				left(x, y);
			}
		}
		else if (cctvNum == 5) { // 4방향
			left(x, y);
			right(x, y);
			up(x, y);
			down(x, y);
		}
	}
}

int blind() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) sum++;
		}
	}

	return sum;
}

void setDir(int cnt) {
	if (cnt == cctv.size()) { // 모든 cctv의 방향이 설정되면
		checkCCTV();
		answer = min(answer, blind());
		return;
	}

	/* 모든 cctv에 대해서 동서남북 방향을 모두 탐색 */
	/* 일종의 중복순열! */
	cctv[cnt].second.second = 0;
	setDir(cnt + 1);

	cctv[cnt].second.second = 1;
	setDir(cnt + 1);

	cctv[cnt].second.second = 2;
	setDir(cnt + 1);

	cctv[cnt].second.second = 3;
	setDir(cnt + 1);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &office[i][j]);
			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cctv.push_back({ {i, j}, {office[i][j], -1} });
			}
		}
	}

	setDir(0);
	printf("%d\n", answer);
}
