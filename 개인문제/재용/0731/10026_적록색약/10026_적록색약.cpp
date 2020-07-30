// 10026_적록색약.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101 // NULL 문자때문에 +1 해줘야함

int n; // 좌표 크기
char graph[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // 8방향 ㄴㄴ 4방향 ㅇㅇ

void dfs(int a, int b) { // 적록색맹 X
	for (int i = 0; i < 4; i++) {
		int na = a + direction[i][0];
		int nb = b + direction[i][1];

		if (na < 0 || nb < 0 || na >= n || nb >= n) continue;
		if (visited[na][nb] == 0 && graph[a][b] == graph[na][nb]) {
			visited[na][nb] = 1;
			dfs(na, nb);
		}
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &graph[i][j]);
		}
	}

	int area_no = 0, area_yes = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				area_no++;
			}
		}
	}

	memset(visited, 0, sizeof(visited)); // visited 배열 초기화

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 'G') graph[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				area_yes++;
			}
		}
	}

	printf("%d %d\n", area_no, area_yes);
}
