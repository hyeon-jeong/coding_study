// 1989_초심자의_회문검사.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		char word[10];
		scanf("%s", word);

		int len = strlen(word);
		int p = 1;
		for (int i = 0; i < len / 2; i++) {
			if (word[i] != word[len - i - 1]) {
				p = 0;
				break;
			}
			else continue;
		}
		printf("#%d", tc);
		printf(" %d\n", p);
	}
	return 0;
}

