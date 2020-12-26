// 14889_스타트와_링크.cpp
// next_permutation으로 풀면 시간초과!!
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 20

int n; // 인원 수
int cap[MAX][MAX];
bool visited[MAX] = { false, };
int answer = 2001;

void dfs(int player, int cnt) {
	if (cnt == n / 2) {
		/* start team과 link team 나누기 */
		vector<int> start, link;
		for (int i = 0; i < n; i++) {
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}

		int startCost = 0, linkCost = 0;
		for (auto &i : start) {
			for (auto &j : start) {
				if (i == j) continue;
				startCost += cap[i][j];
			}
		}
		for (auto &i : link) {
			for (auto &j : link) {
				if (i == j) continue;
				linkCost += cap[i][j];
			}
		}

		answer = min(answer, abs(linkCost - startCost));
		return;
	}

	for (int i = player + 1; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false; // backtracking
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cap[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d\n", answer);
}
