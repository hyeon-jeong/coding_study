// 2020 카카오 인턴십 : 수식 최대화.cpp
// [참고] c++ 문자열 자르기 : https://chbuljumeok1997.tistory.com/42

#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
using namespace std;

char prior[6][3] = { {'+', '-', '*'}, {'+', '*', '-'}, {'-', '+', '*'}, {'-', '*', '+'}, {'*', '-', '+'}, {'*', '+', '-'} };

long long cal(long long a, long long b, char op) {
	long long result;
	switch (op) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	}

	return result;
}

long long solution(string expression) {
	long long answer = 0;
	vector<char> oper;
	vector<long long> num;

	/* 연산자만 따로 저장 */
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
			oper.push_back(expression[i]);
			expression[i] = ' ';
		}
	}
	
	/* 문자열로 된 숫자를 long long 타입으로 변환해 벡터에 저장 */
	istringstream only_num(expression);
	string stringBuffer;
	while (getline(only_num, stringBuffer, ' ')) {
		num.push_back(stoll(stringBuffer));
	}


	for (int p = 0; p < 6; p++) {
		vector<char> temp_oper = oper;
		vector<long long> temp_num = num;

		for (int c = 0; c < 3; c++) {
			char op = prior[p][c];

			for (int i = 0; i < temp_oper.size(); i++) {
				if (temp_oper[i] == op) {
					temp_num[i] = cal(temp_num[i], temp_num[i + 1], temp_oper[i]);

					temp_num.erase(temp_num.begin() + i + 1);
					temp_oper.erase(temp_oper.begin() + i);
					i--;
				}
			}
		}

		long long result = abs(temp_num[0]);
		if (answer < result) answer = result;
	}

	return answer;
}
