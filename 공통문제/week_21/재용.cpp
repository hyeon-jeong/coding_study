// 14501_퇴사.cpp 
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#define DAY 16

int n; // 근무 일수
int T[DAY] = { 0, };
int P[DAY] = { 0, };
int visited[DAY] = { 0, };

int max_profit = 0;
void dfs(int start, int cur_profit) { // start: 시작점, cur_profit: 현재까지의 이익
	if (visited[start] || start > n + 1) return; // 마지막 날(n일)에 일할 수 있는 경우도 포함되도록 start > n + 1
	if (max_profit < cur_profit) max_profit = cur_profit;
	
	for (int i = start; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i + T[i], cur_profit + P[i]);
			visited[i] = 0; // 백트래킹
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	dfs(1, 0); 
	printf("%d\n", max_profit);

	return 0;
}
