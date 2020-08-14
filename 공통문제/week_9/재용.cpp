// 4261_빠른_휴대전화_키패드.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
#include <cstring>

string word_to_key(char *word) { // 단어를 키입력으로 변환해주는 함수
	char wtk[1000];
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
			wtk[i] = '2';
		}
		else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
			wtk[i] = '3';
		}
		else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
			wtk[i] = '4';
		}
		else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
			wtk[i] = '5';
		}
		else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
			wtk[i] = '6';
		}
		else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
			wtk[i] = '7';
		}
		else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
			wtk[i] = '8';
		}
		else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'y' || word[i] == 'z') {
			wtk[i] = '9';
		}
	}
	// null 문자를 마지막에 지정
	// 지정 안해주면 문자열 끝을 모름 -> 변환된 문자열도 길이가 1000인줄 앎;;
	wtk[strlen(word)] = '\0';
	string str(wtk);
	return wtk;
}

int num_of_valid_word(char *key, vector<string> dict) {
	int count = 0;
	for (int i = 0; i < dict.size(); i++) {
		// 사전에 있는 단어와 길이가 같은 key 입력만 유효함
		if (strlen(key) != dict[i].size()) continue;
		else {
			char *word = (char *)dict[i].c_str();
			string wtk = word_to_key(word); // 단어를 키로 변환
			if (wtk.compare(key) == 0) count += 1;
			else continue;
		}
	}

	return count;
}


int main()
{
	int T; // test case
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		printf("#%d ", i);

		char key[1000]; // 키 입력
		int n; // 단어 수
		scanf("%s %d", key, &n);
		
		vector<string> dict(n); // 단어 사전
		for (int j = 0; j < n; j++) {
			char word[1000];
			scanf("%s", word);
			string str(word);
			dict.push_back(word);
		}
		int count = num_of_valid_word(key, dict);
		printf("%d\n", count);
	}
	return 0;
}
