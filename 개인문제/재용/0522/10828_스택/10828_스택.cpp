// 10828_스택.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#define MAX 10000

typedef struct StackType { // 스택 구조체
	int stack[MAX];
	int top;
} StackType;

int n; // 명령의 수

void init(StackType* s) { // 스택 초기화
	s->top = -1;
}

int empty(StackType* s) {
	if (s->top == -1) return 1; // 비어있으면 1
	else return 0;
}

int stack_size(StackType* s) { // size
	if (!empty(s)) {
		return (s->top) + 1;
	}
	else return 0;
}

int peek(StackType* s) { // top
	if (!empty(s)) {
		return s->stack[s->top];
	}
	else return -1;
}

void push(StackType* s, int x) {
	s->stack[++(s->top)] = x;
}

int pop(StackType* s) {
	if (!empty(s)) {
		return s->stack[(s->top)--];
	}
	else { // 비어있으면
		return -1;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init(s);

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			push(s, x);
			continue;
		}
		else {
			if (command == "top") {
				cout << peek(s) << endl;
			}
			else if (command == "size") {
				cout << stack_size(s) << endl;
			}
			else if (command == "empty") {
				cout << empty(s) << endl;
			}
			else if (command == "pop") {
				cout << pop(s) << endl;
			}
		}
	}
}
