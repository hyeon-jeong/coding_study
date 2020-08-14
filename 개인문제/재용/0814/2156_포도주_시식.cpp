// 2156_포도주_시식
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int n; // 포도주 잔 개수
int amount[10000] = { 0, };
int dp[10000] = { 0, };

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &amount[i]);
	}

	dp[0] = amount[0];
	dp[1] = amount[0] + amount[1];
	for (int i = 2; i < n; i++) {
		// n - 1번 안마신 경우 -> n - 2번, n번 마심
		// n - 1번 마신 경우 => n - 3번, n번 마심
		dp[i] = max(dp[i - 2] + amount[i], dp[i - 3] + amount[i - 1] + amount[i]);
		// n - 1번 안마시고, n번도 안마시는 경우
		dp[i] = max(dp[i - 1], dp[i]);
	}

	printf("%d\n", dp[n - 1]);

	return 0;
}
