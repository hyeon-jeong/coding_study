// 삼성_3752_가능한_시험_점수.cpp 
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define MAX 10000 // 최대 점수 100 * 최대 문제 수 100

int main()
{
	int test_case;
	int T;

	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		int N; // 문제 수
		cin >> N;

		queue<int> score; 
		for (int i = 0; i < N; i++) { // 각 문제의 점수 큐에 넣음
			int s;
			cin >> s;
			score.push(s);
		}

		set<int> total; // 오름차순 정렬
		total.insert(0);
		queue<int> temp; // score 큐에서 꺼낸 점수를 total set에 있는 점수에 각각 더해준 값을 임시로 저장하는 큐
		vector<int> visited(MAX, 0); // 계산된 점수 합계가 total set에 이미 있는지 확인 (1이면 존재, 0이면 존재 X)
		while (!score.empty()) {
			int s = score.front();
			for (set<int>::iterator it = total.begin(); it != total.end(); ++it) { 
				int t = *it + s; // total set에 있는 점수들과 큐에서 꺼낸 점수를 각각 더해주고
				temp.push(t); // temp 큐에 저장해줌
			}
			while (!temp.empty()) { // temp에 있는 점수를 total set에 추가
				// set은 키를 중복 저장하지 않으므로 내가 일일이 중복을 검사할 필요 없음 (set이 알아서 다 함) -> 시간초과남;;
				// 시간 초과를 막기 위해 visited 벡터를 이용해 해당 점수 합계가 set에 이미 있는지 확인
				int tmp = temp.front();
				temp.pop();
				if (visited[tmp] == 1) continue;
				else {
					total.insert(tmp);
					visited[tmp] = 1;
				}
			}
			score.pop();
		}

		cout << "#" << test_case << " " << total.size() << endl;
	}

	return 0;
}

