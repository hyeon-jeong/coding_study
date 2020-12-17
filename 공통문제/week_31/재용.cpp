// 18500_미네랄.cpp
using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 101
#define INF 987654321

int r, c; // 동굴 크기. r이 높이고, c가 너비라 보면 됨.
int n; // 막대 던진 횟수
char cave[MAX][MAX];
bool clusterLoc[MAX][MAX] = { false, }; // 공중에 떠있는 클러스터 위치 표시. dropLength에서 사용.
vector<pair<int, int>> clusters; // 공중에 떠있는 클러스터 위치 저장
/*
	r = 8, c = 8, h가 3이면
	h가 가리키는 행 번호는 (r - h + 1)이다.
	(높이 h는 행렬의 맨 아래가 1일 때 한줄씩 위로 갈 때마다 +1이 되는 것)
*/

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
bool visited[MAX][MAX] = { false, };

/* 바닥에 있는 클러스터 표시 */
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx < 1 || ny < 1 || nx > r || ny > c) continue;
		if (!visited[nx][ny] && cave[nx][ny] == 'x') {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}


/* 공중에 클러스터 있는지 확인 -> 있으면 true */
bool clusters_on_the_air() {
	bool exist = false;

	/* 동굴 바닥부터 클러스터 탐색 */
	memset(visited, false, sizeof(visited));
	for (int j = 1; j <= c; j++) {
		if (cave[r][j] == 'x' && !visited[r][j]) {
			visited[r][j] = true;
			dfs(r, j);
		}
	}

	clusters.clear();
	memset(clusterLoc, false, sizeof(clusterLoc));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			// 방문 안한 곳에 미네랄이 있다면 공중에 있는 클러스터
			if (!visited[i][j] && cave[i][j] == 'x') {
				clusterLoc[i][j] = true;
				clusters.push_back({ i, j }); // 해당 클러스터 위치 저장
				exist = true;
			}
		}
	}

	return exist;
}


/* 막대기 던져서 미네랄 깨부수기 */
void throwStick(int height, bool left) {
	int h = r - height + 1;

	if (left) {
		for (int j = 1; j <= c; j++) {
			if (cave[h][j] == 'x') {
				cave[h][j] = '.';
				break;
			}
		}
	}
	else {
		for (int j = c; j >= 1; j--) {
			if (cave[h][j] == 'x') {
				cave[h][j] = '.';
				break;
			}
		}
	}
}


/* 몇 칸 내려갈지 계산 */
int dropHeight(int x, int y) {
	int height = 0;
	for (int i = x + 1; i <= r; i++) {
		if (cave[i][y] == 'x') {
			if (clusterLoc[i][y]) return INF;
			else return height;
		}
		else if (cave[i][y] == '.') height++;
	}

	return height;
}


/* 
	공중에 떠있는 클러스터 떨어뜨리기 
	**주의: 클러스터를 이루는 모든 미네랄은 같은 칸 수만큼 떨어져야함
*/
void dropCluster() {
	int height = INF - 1;
	for (int i = 0; i < clusters.size(); i++) {
		int x = clusters[i].first;
		int y = clusters[i].second;

		int tempH = dropHeight(x, y);
		/* 공중에 있는 미네랄 바로 위로 떨어질 경우*/
		if (tempH == INF) continue;
		else height = min(height, tempH);
	}

	/* 밑에서부터 위로 탐색하면서 미네랄 떨어뜨림 */
	sort(clusters.begin(), clusters.end());
	for (int i = clusters.size() - 1; i >= 0; i--) {
		int x = clusters[i].first;
		int y = clusters[i].second;

		cave[x][y] = '.';
		cave[x + height][y] = 'x';
	}
}


int main() {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &cave[i][j]);
		}
	}

	scanf("%d", &n);
	bool left = true; // true면 왼->오, false면 오->왼
	for(int i = 0; i < n; i++) {
		int height; 
		scanf("%d", &height); // 높이
		
		/* 막대 던져서 미네랄 깨부수기 */
		throwStick(height, left);
		left = !left; // 던지는 방향 바꿔주기

		/* 공중에 떠있는 클러스터 찾기 */
		if (clusters_on_the_air()) { // 공중에 뜬 클러스터 있으면
			dropCluster();
		}
		else continue;
	}


	/* 최종 미네랄 모양 출력 */
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			printf("%c", cave[i][j]);
		}
		printf("\n");
	}
}
