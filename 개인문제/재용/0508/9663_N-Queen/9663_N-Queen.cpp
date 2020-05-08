// 9663_N-Queen.cpp
#include <iostream>
using namespace std;
#include <vector>

int n;
int result = 0;
int col[15]; //각 행에서 퀸이 놓여진 열이 저장된 배열

bool promising(int i) { // 유망 노드 탐색 함수
	int j = 0;
	bool p = true; // 노드가 유망하면 true

	while (j < i && p) {
		if (col[i] == col[j] || abs(col[i] - col[j]) == abs(j - i)) {
			p = false; // 노드가 유망하지 않으면 false
		}
		j++;
	}
	return p;
}

void queens(int i) {
	if (i == n) { // 마지막 행일 때
		result += 1; // 경우의 수 추가
	}
	else {
		for (int j = 0; j < n; j++) {
			col[i] = j; // (i, j)에 퀸 놓음
			if (promising(i)) { // (i, j)에 놓인 퀸이 유망하면
				queens(i + 1); // 다음 행으로 넘어가서 새로운 유망 노드 찾음
			}
		}
	}
}

int main()
{
	cin >> n;
	queens(0); // 최상위 노드(루트)부터 탐색
	cout << result << endl;
}


