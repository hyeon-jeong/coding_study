// 14500_테트로미노.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#define MAX 500

int n, m; // 세로, 가로
int paper[MAX][MAX] = { 0, };

int tetromino[19][4][2] = {
	// 직사각형
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},

	// 정사각형
	{{0, 0}, {1, 0}, {0, 1}, {1, 1}},

	// ㄹ형
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
	{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},

	// ㅗ형
	{{0, 0}, {1, 0}, {2, 0}, {1, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},

	// ㄴ형
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {0, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 0}}
};

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	int result = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int i = 0; i < 19; i++) {
				int x2 = x + tetromino[i][1][0];
				int y2 = y + tetromino[i][1][1];

				int x3 = x + tetromino[i][2][0];
				int y3 = y + tetromino[i][2][1];

				int x4 = x + tetromino[i][3][0];
				int y4 = y + tetromino[i][3][1];

				// 범위 밖이면 continue
				if (x2 >= n || x3 >= n || x4 >= n || y2 >= m || y3 >= m || y4 >= m
					|| x2 < 0 || x3 < 0 || x4 < 0 || y2 < 0 || y3 < 0 || y4 < 0) continue;
				
				int sum = paper[x][y] + paper[x2][y2] + paper[x3][y3] + paper[x4][y4];
				if (sum > result) result = sum;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
