// 18844_쉬운_계단수.cpp
using namespace std;
#include <iostream>
#include <vector>
#define MAX 1000000000

int n; // 수의 길이
long long dp[101][10] = { 0, };

int main() {
	scanf("%d", &n);

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1; // 자리수가 1인 경우
	}

	for (int i = 2; i <= n; i++) { // i = 자리수
		for (int j = 0; j < 10; j++) { // j로 끝나는 수의 개수
			if (j == 0) dp[i][j] = dp[i - 1][j + 1]; // 앞에 1밖에 못옴
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1]; // 앞에 8밖에 못옴
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MAX;
		}
	}

	long long result = 0;
	for (int i = 1; i < 10; i++) {
		result += dp[n][i];
	}
	result %= MAX;
	printf("%d\n", result);

	return 0;
}
