// 삼성_1859_백만_장자_프로젝트.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int test_case;
	int T;

	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		int N; // 연속된 N일
		cin >> N;
		vector<int> cost(N, 0); // 각 날의 매매가
		for (int i = 0; i < N; i++) { // input
			cin >> cost[i];
		}

		long long result = 0; // 최종 이익
		int max = 0; // 각 범위에서의 최대값
		int start = 0; // 시작 범위 인덱스
		while (start != N) {
			max = *max_element(cost.begin() + start, cost.end()); // 매매가의 최대값을 탐색
			int count = 0; // 팔 물건의 개수
			int sum = 0; // 팔 물건들의 매매가 합
			if (cost[0] == max) { // 만약 매매가의 최대값이 맨 처음에 있을 경우 구매하지 않음
				result = 0; // 최종 이익 = 0
				break;
			}
			while (cost[start] != max) { // max값 만나기 전까지
				sum += cost[start]; // 모든 매매가 더함
				count++;
				start++;
			}
			result = result + ((max * count) - sum);
			start++; // max값 인덱스 다음부터 다시 max를 탐색
		}

		cout << "#" << test_case << " " << result << endl;
	}

	return 0;
}

