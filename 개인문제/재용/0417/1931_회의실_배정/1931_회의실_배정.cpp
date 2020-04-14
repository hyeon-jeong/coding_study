// 1931_회의실_배정.cpp 
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int n; // 회의 수

/* 회의 종료 시간 기준 오름차순 정렬 함수 */
/* 회의 종료 시간이 같을 경우 회의 시작 시간이 빠른 것을 앞부분에 정렬 */
bool finish_asc(pair<int, int> a, pair<int, int> b) { 
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	int count = 1; // 회의실에서 진행 가능한 회의 수

	cin.sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<pair<int, int>> t(n); /* 각 회의의 시작/종료 시간 */


	for (int i = 0; i < n; i++) { // 벡터에 값 입력
		cin >> t[i].first >> t[i].second;
	}

	sort(t.begin(), t.end(), finish_asc); // 회의 종료 시간 오름차순으로 정렬

	int current = t[0].second; // 현재 회의실 사용중인 회의의 종료 시간

	for (int i = 1; i < n; i++) {
		if (current <= t[i].first) { // 현재 회의 종료 시간보다 회의 시작 시간이 크거나 같으면 선택
			current = t[i].second;
			count++;
		}
	}

	cout << count;
}
