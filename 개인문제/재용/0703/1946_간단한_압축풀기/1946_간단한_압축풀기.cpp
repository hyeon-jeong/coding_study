// 1946_간단한_압축풀기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int n; // 입력받는 line 수
		char c[1];
		int num;
		string str;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf(" %c", &c);
			scanf("%d", &num);
			str.append(num, *c);
		}

		printf("#%d\n", tc);
		int len = str.size();
		int idx = 0;
		while (true) {
			string str1 = str.substr(idx, 10);
			printf("%s\n", str1.c_str());
			idx += 10;

			if (idx > len) break;
		}
	}

	return 0;
}

