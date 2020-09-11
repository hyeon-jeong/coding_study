// 2020_카카오_괄호변환.cpp 
#include <string>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

bool correct(string x) { // 올바른 괄호이면 true
	stack<char> s;

	if (x[0] == ')') return false;
	
	s.push(x[0]);
	for (int i = 1; i < x.size(); i++) {
		if (x[i] == '(') s.push(x[i]);
		else if (x[i] == ')') {
			if (!s.empty()) s.pop();
			else return false;
		}
	}

	return true;
}

string recursion(string p) {
	if (p == "") return p; // 비었으면 빈 문자열 반환

	/* 균형잡힌 괄호 문자열 u, v로 분리 */
	string u = "";
	string v = "";

	int left = 0;
	int right = 0;

	for (int i = 0; i < p.size(); i++) {
		if (left == right && left != 0) {
			v += p[i];
			continue;
		}
		else {
			if (p[i] == '(') left++;
			else if (p[i] == ')') right++;
			u += p[i];
		}
	}

	/* u가 올바른 괄호인 경우 */
	if (correct(u)) return u + recursion(v);

	/* u가 올바르지 않은 괄호인 경우 */
	else {
		string result = "(";
		result += recursion(v) + ')';

		u.erase(0, 1);
		u.erase(u.size() - 1, 1);

		for (int i = 0; i < u.size(); i++) {
			if (u[i] == '(') result += ')';
			else if (u[i] == ')') result += '(';
		}

		return result;
	}
}

string solution(string p) {	
	string answer;
	if (correct(p)) answer = p; // 이미 올바른 괄호면 그대로 리턴
	else {
		answer = recursion(p);
	}
	return answer;
}
