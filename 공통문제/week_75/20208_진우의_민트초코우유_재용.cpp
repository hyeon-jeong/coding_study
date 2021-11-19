// 20208_진우의_민트초코우유.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10

typedef struct state {
	int y;
	int x;
	bool visited;
};

int n, m, h;
int village[MAX][MAX];
pair<int, int> home;
vector<state> mintchoco;
int answer = 0;

void dfs(int y, int x, int hp, int cnt) {	
	// 최대값 갱신
	if (cnt > answer) {
		int homeD = abs(y - home.first) + abs(x - home.second);
		if (homeD <= hp) {
			answer = cnt;
		}
	}

	// 집에 도착하기 전 체력이 고갈되었을 때
	if (hp <= 0) return;

	// 다음 민트초코 먹기
	// 인덱스가 아닌 auto로 접근하면 메모리 초과 오류남;;
	for (int i = 0; i < mintchoco.size(); i++) {
		// 다음 민트초코까지의 거리
		int dist = abs(mintchoco[i].y - y) + abs(mintchoco[i].x - x);

		// 다음 민초를 아직 안먹었고 + 이동 가능한 거리면
		if (!mintchoco[i].visited && dist <= hp) {
			mintchoco[i].visited = true;
			dfs(mintchoco[i].y, mintchoco[i].x, hp - dist + h, cnt + 1);
			mintchoco[i].visited = false;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &village[i][j]);
			if (village[i][j] == 1) home = make_pair(i, j);
			else if (village[i][j] == 2) { // 민트초코 위치 표시
				mintchoco.push_back({ i, j, false });
			}
		}
	}

	dfs(home.first, home.second, m, 0);

	printf("%d\n", answer);
	return 0;
}
