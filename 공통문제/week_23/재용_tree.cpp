// 5052_전화번호_목록
using namespace std;
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

int t; // test case
int n; // 전화번호 개수

struct Trie {
	bool is_eof; // 문자열의 끝이면 true
	Trie* child[10]; // 자식은 숫자 0 ~9 최대 10개

	Trie() : is_eof(false) { // child 생성
		memset(child, 0, sizeof(child));
	}
	~Trie() { // child 삭제
		for (int i = 0; i < 10; i++) {
			if (child[i]) delete child[i];
		}
	}

	/* 새로운 문자열 Trie에 추가 */
	void insert(const char* key) { 
		if (*key == '\0') { // 문자열 끝인 경우
			is_eof = true;
		}
		else {
			int idx = (int)(*key - '0');
			if (child[idx] == 0) child[idx] = new Trie();
			child[idx]->insert(key + 1);
		}
	}

	/* key에 해당하는 문자열을 접두어로 가지고 있는지 확인 */
	bool find(const char* key) { 
		if (*key == '\0') return true;
		if (is_eof) return false; // 문자열이 끝나기 전에 eof가 나오면 접두어가 있는 것

		int idx = (int)(*key - '0');
		return child[idx]->find(key + 1);
	}
};

int main() {
	scanf("%d", &t);

	for (int tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		char phone[10001][11];

		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			scanf("%s", &phone[i]);
			root->insert(phone[i]);
		}

		bool answer = true;
		for (int i = 0; i < n; i++) {
			if (root->find(phone[i]) == false) {
				answer = false;
				break;
			}
		}

		delete root;
		if (answer) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
