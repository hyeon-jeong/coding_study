// 1946_신입사원.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		int n;
		scanf("%d", &n);

		vector<pair<int, int>> score;
		for (int i = 0; i < n; i++) {
			int paper, interview;
			scanf("%d %d", &paper, &interview);
			score.emplace_back(paper, interview);
		}
		sort(score.begin(), score.end()); // 서류 등수 기준 오름차순 정렬

		int pass = 1; // 합격자 수
		int standard = score.begin()->second; // 면접 등수 비교 기준
		for (auto it = score.begin() + 1; it != score.end(); it++) {
			if (it->second > standard) continue;
			else { // 기준보다 면접 등수가 높을 경우
				pass += 1; // 합격
				standard = it->second; // 기준 변경
			}
		}

		printf("%d\n", pass);
	}
}
