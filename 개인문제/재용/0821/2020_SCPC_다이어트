// 2020_SCPC_다이어트.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		int n; // 메뉴 수
		int k; // 날짜 수
		cin >> n >> k;
		vector<int> calA;
		vector<int> calB;

		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			calA.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			calB.push_back(tmp);
		}

		sort(calA.begin(), calA.end()); // 오름차순
		sort(calB.rbegin(), calB.rend()); // 내림차순
		calA.erase(calA.begin() + k, calA.end());
		calB.erase(calB.begin(), calB.end() - k);

		for (int i = 0; i < k; i++) {
			int daily = calA.back() + calB.back();
			if (Answer < daily) Answer = daily;
			calA.pop_back();
			calB.pop_back();
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

	}

	return 0;
}
