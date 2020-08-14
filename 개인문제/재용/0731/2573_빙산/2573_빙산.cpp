#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAX 301

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void dfs(int a, int b) { // ���� ��� ������ ���� ���� dfs
	for (int i = 0; i < 4; i++) {
		int na = a + direction[i][0];
		int nb = b + direction[i][1];

		if (na < 0 || nb < 0 || na >= n || nb >= m) continue;
		if (visited[na][nb] == 0 && map[na][nb] > 0) {
			visited[na][nb] = 1;
			dfs(na, nb);
		}
	}
}

void melt(int a, int b) { // ���ϸ� ���̱� ���� dfs
	for (int i = 0; i < 4; i++) {
		int na = a + direction[i][0];
		int nb = b + direction[i][1];

		if (na < 0 || nb < 0 || na >= n || nb >= m) continue;
		if (visited[na][nb] == 0 && map[na][nb] == 0) { // �ֺ��� �ٴ��̸�
			map[a][b] = max(map[a][b] - 1, 0); // ���� ���� ����
			// �湮ǥ�ô� ���� ���� X
		}
		else if (visited[na][nb] == 0 && map[na][nb] > 0) {
			visited[na][nb] = 1;
			melt(na, nb);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int year = 0;
	while (true) {
		year++;
		for (int i = 0; i < n; i++) { // ���� ���̱�
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && map[i][j] > 0) {
					visited[i][j] = 1;
					melt(i, j);
				}
			}
		}

		memset(visited, 0, sizeof(visited)); // �湮ǥ�� �ʱ�ȭ
		int count = 0; // ���� ��� ����
		for (int i = 0; i < n; i++) { // ���� ��� ���� ����
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && map[i][j] > 0) {
					visited[i][j] = 1;
					dfs(i, j);
					count++;
				}
			}
		}

		if (count > 1) break; // ���� ����� 2�� �̻��̸� break
		else if (count == 0) { // ���ϰ� �� ���� �������� ����� �������� ������
			year = 0; // 0 ��ȯ
			break;
		}
		memset(visited, 0, sizeof(visited)); // �湮ǥ�� �ʱ�ȭ
	}
	printf("%d\n", year);
}