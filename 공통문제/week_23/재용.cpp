// 5052_전화번호_목록
using namespace std;
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

int t; // test case
int n; // 전화번호 개수

bool consistency(vector<string> phone) {
	for (int i = 1; i < phone.size(); i++) {
		string cur = phone[i];
		string prev = phone[i - 1];

		int cnt = 0; // 일치하는 숫자 개수
		for (int j = 0; j < prev.size(); j++) {
			if (cur[j] == prev[j]) cnt += 1;
			else continue;
		}

		if (cnt == prev.size()) return false;
	}

	return true;
}

int main() {
	scanf("%d", &t);

	for (int tc = 0; tc < t; tc++) {
		scanf("%d", &n);

		vector<string> phone;
		for (int i = 0; i < n; i++) {
			string num;
			cin >> num;
			phone.push_back(num);
		}

		sort(phone.begin(), phone.end());
		bool answer = consistency(phone);

		if (answer == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
