// 5557_1학년.cpp
using namespace std;
#include <vector>
#include <iostream>

int main() {
	int n;
	vector<int> arr;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr.push_back(num);
	}

	long dp[100][21] = { 0, }; // i번째 수까지의 계산 결과가 j인 경우의 수
	dp[0][arr[0]] = 1;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] > 0) { // i - 1까지의 계산 결과가 j인 경우가 있을 때
				if (j + arr[i] <= 20) { // j + (i번째 수)가 20 이하인 경우
					dp[i][j + arr[i]] += dp[i - 1][j];
				}
				if (j - arr[i] >= 0) { // j - (i번째 수)가 0 이상인 경우
					dp[i][j - arr[i]] += dp[i - 1][j];
				}
			}
		}
	}

	long answer = dp[n - 2][arr[n - 1]]; // (n - 2)번째 수까지의 계산 결과가 arr[n - 1]인 경우의 수
	printf("%ld\n", answer);
}
