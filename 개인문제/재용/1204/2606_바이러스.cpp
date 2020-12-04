//2606_바이러스.cpp
#include <iostream>
#include <vector>
using namespace std;

int com, link;
vector<int> network[202];
vector<int> visited;
int virus = 0;

void dfs(int start) {
	if (visited[start]) {
		return;
	}

	visited[start] = 1;
	virus++;

	for (int i = 0; i < network[start].size(); i++) {
		int next = network[start][i];
		if(!visited[next]) dfs(next);
	}
}

int main() {
	scanf("%d", &com);
	scanf("%d", &link);

	for (int i = 0; i < link; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		network[a].push_back(b);
		network[b].push_back(a);
	}

	visited.assign(com + 1, 0);

	dfs(1);

	printf("%d\n", virus - 1);
}
