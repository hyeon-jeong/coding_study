// 9012_괄호.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <string>

bool vps(string str) {
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c == '(') { // 여는 괄호면 스택에 push
			s.push(str[i]);
		}
		else { // 닫는 괄호이면
			// 스택이 비어있는지 확인
			if (!s.empty()) s.pop(); // 비어있지 않으면 pop
			else return false;  // 비어있으면 짝이 안맞으므로 false
		}
	}
	return s.empty(); // str을 모두 탐색한 후 스택이 비어있으면 true, 아니면 false
}

int T; // 테스트 수

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		if (vps(str) == false) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
