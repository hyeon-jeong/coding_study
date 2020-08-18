// 11052_카드_구매하기.cpp
using namespace std;
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

int n; // 구매 카드 개수
int dp[1001] = { 0, };

int main() {
	scanf("%d", &n);
	
	vector<int> card(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}

	dp[1] = card[1];
	for (int i = 1; i <= n; i++) { // i = 구매하는 카드 개수
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}
