// 2411_아이템_먹기.cpp
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101

int n, m, a, b;
int map[MAX][MAX] = { 0, };
int dp[MAX][MAX];

int move(pair<int, int> s, pair<int, int> e) {
	int sy = s.first;
	int sx = s.second;

	int ey = e.first;
	int ex = e.second;

	if (sy > ey || sx > ex) return 0;
	if (sy == ey && sx == ex) return 1;
	
	for (int i = sy; i <= ey; i++) { // 오른쪽 이동
		if (map[i][sx] == -1) break;
		dp[i][sx] = 1;
	}

	for (int i = sx; i <= ex; i++) { // 아래 이동
		if (map[sy][i] == -1) break;
		dp[sy][i] = 1;
	}

	for (int i = sy + 1; i <= ey; i++) { // dp
		for (int j = sx + 1; j <= ex; j++) {
			if (map[i][j] != -1) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[ey][ex];
}


int main() {
	vector<pair<int, int>> v;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for (int i = 0; i < a; i++) { // 아이템
		int y, x;
		scanf("%d %d", &y, &x);
		map[y][x] = 1; 
		v.emplace_back(y, x);
	}
	for (int i = 0; i < b; i++) { // 장애물
		int y, x;
		scanf("%d %d", &y, &x);
		map[y][x] = -1;
	}

	v.emplace_back(1, 1);
	v.emplace_back(n, m);
	sort(v.begin(), v.end());

	int answer = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		int case_cnt = move(v[i], v[i + 1]);
		answer *= case_cnt;
	}

	printf("%d\n", answer);
	
	return 0;
}
