// 5397_키로거.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

string keylog(string pw) {
	stack<char> front; // 왼쪽 커서(<)일 때
	stack<char> back; // 오른쪽 커서(>)일 때
	string real_pw;
	for(int i = 0; i < pw.length(); i++) {
		char a = pw[i];
		if (a == '<') { // 왼쪽 커서(<)일 때
			if (!front.empty()) {
				back.push(front.top()); // 앞쪽 스택의 top을 뒤쪽 스택에 push
				front.pop(); // 앞쪽 스택 pop
			}
			else continue;
		}
		else if (a == '>') { // 오른쪽 커서(>)일 때
			if (!back.empty()) {
				front.push(back.top()); // 뒤쪽 스택의 top을 앞쪽 스택에 push
				back.pop(); // 뒤쪽 스택 pop
			}
			else continue;
		}
		else if (a == '-') {
			if (!front.empty()) {
				front.pop(); // backspace일 때 앞쪽 스택 pop
			}
			else continue;
		}
		else front.push(a); // 그 외 문자 입력받으면 앞쪽 스택에 push
	}
	while (!back.empty()) { // 뒤쪽 스택에 남은 문자 모두 pop해서 front에 push
		front.push(back.top());
		back.pop();
	}
	while (!front.empty()) { // 앞쪽 스택에서 모두 pop해서 real_pw에 저장
		real_pw += front.top();
		front.pop();
	}
	reverse(real_pw.begin(), real_pw.end()); // LIFO이므로 reverse
	return real_pw;
}

int T; // test case

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (int i = 0; i < T; i++) {
		string pw;
		cin >> pw;
		cout << keylog(pw) << endl;
	}
}
