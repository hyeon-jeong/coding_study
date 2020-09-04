// 11048_이동하기.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 1001 // 1부터 시작하므로 +1 해주기.. (안하면 틀림)

int n, m;
int maze[MAX][MAX] = { 0, };
int dp[MAX][MAX] = { 0, };

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &maze[i][j]);
		}
	}

	dp[1][1] = maze[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + maze[i][j];
		}
	}

	printf("%d\n", dp[n][m]);

	return 0;
}

