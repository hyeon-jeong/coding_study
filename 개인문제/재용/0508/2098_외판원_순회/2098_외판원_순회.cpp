// 2098_외판원_순회.cpp
#include <iostream>
#include <cstring> // memset
using namespace std;
#include <vector>
#include <algorithm>
#define MAX 16
#define INF 987654321

int n; // 도시 개수
int W[MAX][MAX]; // 각 경로의 가중치가 저장된 배열
int memo[MAX][1 << MAX]; // memo[현재 방문중인 도시][이미 방문한 도시]
/* 뒤의 값은 비트마스크 값. 1을 MAX만큼 왼쪽으로 shift */
/* 1 << 5 == 100000 */
/* 방문했으면 1, 아니면 0으로 표현 */
/* 0 ~ 4번까지의 5개 도시 중 0번과 2번 도시를 방문했다면 -> 00101로 표현 */

int tsp(int current, int visited) {
	/* memoization */
	/* 이전값 미리 저장해서 동일 계산 반복 수행 제거 */
	int& result = memo[current][visited];
	if (result != -1) return result; // result가 초기값이 아니면 리턴

	/* n = 5일 때, (1 << n) - 1 == 100000 - 1 == 11111 */
	if (visited == (1 << n) - 1) { // 모든 도시를 다 방문했을 때 == 모든 비트가 1
		if (W[current][0] != 0) { // 0번째 도시로 되돌아감 (사이클)
			return W[current][0];
		}
		else return INF; // 사이클 없으면 infinite 리턴
	}
	
	result = INF;
	for (int i = 0; i < n; i++) {
		/* 현재 도시에서 i번째 도시로 가는 경로가 존재하고, i번째 도시를 아직 방문하지 않았다면 */
		/* a & (1 << n) : 변수 a의 n번째 비트가 1이면 1 << n을, 0이면 0을 리턴 */
		if (W[current][i] != 0 && !(visited & (1 << i))) {
			int visit = visited | (1 << i); // visited의 i번째 비트를 1로 바꿈 (i번째 도시 방문)
			result = min(result, tsp(i, visit) + W[current][i]); // i번째 도시 방문했을 때의 최적 경로
		}
	}
	return result;
}



int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> W[i][j];
		}
	}

	/* memoization에 사용될 배열 0으로 초기화 */
	memset(memo, -1, sizeof(memo)); 
	int distance = tsp(0, 1); // 시작점 = 0
	cout << distance << endl; 
}

