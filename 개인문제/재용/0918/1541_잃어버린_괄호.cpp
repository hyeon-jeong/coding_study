// 1541_잃어버린_괄호.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <string>
#include <cstring>

int main()
{
	string exp;
	cin >> exp;
	
	int result = 0;
	string temp = ""; // 피연산자
	bool minus = false; // 처음 나온 연산자가 -이면 true
	// true이면 뒤에 나오는 모든 수를 - 연산
	// false이면 한번 + 연산 해주고, 그 뒤에 나오는 모든 수를 - 연산

	for (int i = 0; i <= exp.size(); i++) { 
		if (exp[i] == '-' || exp[i] == '+' || exp[i] == '\0') { // 연산자일 때
			if (minus) result -= stoi(temp);
			else result += stoi(temp);

			if (exp[i] == '-') minus = true;
			temp = ""; // temp 초기화
			continue;
		}
		temp += exp[i]; // 피연산자일 때
	}
	
	printf("%d\n", result);
}

