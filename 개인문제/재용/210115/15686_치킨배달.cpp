// 15686_치킨배달.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define MAX 51	
#define INF 987654321

int n, m;
int city[MAX][MAX] = { 0, };
bool visited[13] = { false, };
vector<pair<int, int>> house, chicken;
int result;

// 거리 구하는 함수
int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int chosen) {
	if (chosen == m) { // M개의 치킨집 선정했을 때
		int temp = 0;
		for (int i = 0; i < house.size(); i++) {
			int d = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) {
					d = min(d, dist(house[i], chicken[j]));
				}
			}
			temp += d;
		}
		result = min(result, temp);
		return;
	}

	if (idx == chicken.size()) return;

	// 선택 O
	visited[idx] = true;
	dfs(idx + 1, chosen + 1);

	// 선택 X (폐업)
	visited[idx] = false;
	dfs(idx + 1, chosen);
}

int main() {
	scanf("%d", &n); 
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &city[i][j]);
			if (city[i][j] == 1) house.push_back({ i, j });
			else if (city[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	result = INF;
	dfs(0, 0);

	printf("%d\n", result);
}
