// 11057_오르막_수.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <cstdio>
#define MAX 10007

int n; // 길이
long long dp[1001][10] = { 0, };

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < 10; i++) { 
		dp[1][i] = 1; // 자리수가 1인 경우
	}

	for (int i = 2; i <= n; i++) { // i = 자리수
		for (int j = 0; j < 10; j++) { // j로 끝나는 오르막 수의 개수
			for (int x = 0; x <= j; x++) {
				dp[i][j] += dp[i - 1][x];
			}
			dp[i][j] %= MAX;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}

	ans %= MAX;
	printf("%d\n", ans);

	return 0;
}
