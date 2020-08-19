// 2020_카카오_인턴_동굴탐험.cpp
// dfs 참고: https://codemcd.github.io/algorithm/DataStructure-DFS%EC%99%80-%EC%82%AC%EC%9D%B4%ED%81%B4/

using namespace std;
#include <string>
#include <vector>
#include <queue>
#define MAX 200000

vector<int> two_way[MAX];
vector<int> one_way[MAX];
vector<bool> visited(MAX, false); // BFS 방문 여부 배열

/* dfs를 위한 변수 선언 */
vector<int> discovered; // i번 정점의 발견 순서 (-1로 초기화)
vector<int> finished; // dfs(i)가 종료하면 true, 아니면 false
int counter = 0; // 현재까지 발견된 정점의 수
bool result = true; // 사이클 존재 여부 == 동굴 방문 경로 존재 여부

void dfs(int now) { // 사이클 탐색 dfs
	discovered[now] = counter++;
	if (!result) return;

	for (auto& next : one_way[now]) { // 인접 정점 순회
		if (discovered[next] == -1) { // 아직 발견(방문)되지 않았으면 
			dfs(next); // 방문
		}
		else if (discovered[now] < discovered[next]){ // next가 now보다 늦게 발견된 경우
			continue; // 순방향이므로 계속 진행
		}
		else if (!finished[next]) { // dfs(next)가 아직 종료되지 않았으면
			result = false; // next가 now보다 먼저 발견된 것 => 사이클 발생
			return; // 방문 순서를 어겼으므로 false
		}
	}

	finished[now] = 1; // 반복문을 빠져나오면 dfs가 끝나므로 true
	return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	bool answer = true;

	for (int i = 0; i < path.size(); i++) { // path를 2차원 배열로 복사
		int start = path[i][0];
		int end = path[i][1];
		two_way[start].push_back(end);
		two_way[end].push_back(start);
	}
	
	/* BFS로 모든 점을 방문하는 단방향 경로 찾기 */
	queue<int> q;
	q.push(0); // root = 0
	visited[0] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto& next : two_way[now]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			one_way[now].push_back(next);
		}
	}

	// 방문 순서(order) 추가
	for (int i = 0; i < order.size(); i++) {
		int start = order[i][0];
		int end = order[i][1];
		one_way[start].push_back(end);
	}

	// dfs를 사용하기 위해 discovered, finished 초기화
	// 전역변수(MAX)로 초기화하면 segmentation fault 발생..
	discovered = vector<int>(n, -1);
	finished = vector<int>(n, 0);

	dfs(0); // 사이클 존재 여부 확인
	answer = result;
	return answer;
}
