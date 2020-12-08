// 15591_MooTube(Silver).cpp
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 5001

typedef long long ll;

int n, Q; // n개의 동영상, Q개의 질문
vector<pair<int, ll>> usado[MAX];
int visited[MAX];
int result;

int main() {
	scanf("%d %d", &n, &Q);

	/* usado 입력받기 */
	for (int i = 0; i < n - 1; i++) {
		int p, q;
		ll r;
		scanf("%d %d %lld", &p, &q, &r);

		usado[p].push_back({ q, r });
		usado[q].push_back({ p, r });
	}

	for (int i = 0; i < Q; i++) {
		ll k; // 임계치
		int v; // 시청 동영상
		scanf("%lld %d", &k, &v);
		
		/* visited, result 초기화 */
		memset(visited, 0, sizeof(visited));
		result = 0;

		queue<int> q;
		q.push(v);
		visited[v] = 1;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < usado[cur].size(); j++) {
				int next = usado[cur][j].first; // 다음 동영상
				if (visited[next]) continue;
				
				int next_r = usado[cur][j].second; // 다음 동영상과의 usado
				if (next_r >= k) {
					visited[next] = 1;
					result++;
					q.push(next);
				}
			}
		}
		printf("%d\n", result);
	}

	return 0;
}
