// 10845_큐.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string>

int n;
queue<int> q;

int main()
{
	cin >> n; // 명령의 수
	string command;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (command == "pop") {
			if (!q.empty()) {
				int element = q.front();
				q.pop();
				cout << element << endl;
			}
			else cout << -1 << endl;
		}
		else if (command == "size") cout << q.size() << endl;
		else if (command == "empty") {
			if (q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (command == "front") {
			if (!q.empty()) cout << q.front() << endl;
			else cout << -1 << endl;
		}
		else if (command == "back") {
			if (!q.empty()) cout << q.back() << endl;
			else cout << -1 << endl;
		}
	}
}

