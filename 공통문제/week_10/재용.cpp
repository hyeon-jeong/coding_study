// 7701_염라대왕의_이름정렬.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>


bool compare(const string &s1, const string &s2) { // 정렬 함수
	if (s1.size() == s2.size()) { // 길이가 같으면 사전 오름차순으로
		return s1 < s2;
	}
	return s1.size() < s2.size(); // 길이가 다르면 길이 오름차순으로
}


int main()
{
	int T; // test case
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int n; // 이름 개수
		scanf("%d", &n);
		vector<string> v;

		for (int j = 0; j < n; j++) {
			char s[51];
			scanf("%s", s);
			string str(s); // c style로 입력받은 string을 c++ style로 변환
			v.push_back(s);
		}

		sort(v.begin(), v.end(), compare);

		// unique로 중복이 제거된 후에도 vector의 size는 동일함 (중복된 원소는 뒤로 빼버리기 때문)
		// unique의 반환값은 중복이 제거된 벡터의 end() 인덱스
		// 따라서 unique 적용 후 뒤로 빠진 중복된 원소들은 erase함
		v.erase(unique(v.begin(), v.end()), v.end()); // 중복 제거

		printf("#%d\n", i);
		vector<string>::iterator iter;
		for (iter = v.begin(); iter != v.end(); ++iter) {
			printf("%s\n", (*iter).c_str()); // c++ style의 string을 c style로 변환 후 출력
		}
	}

	return 0;
}
