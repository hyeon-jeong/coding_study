// 15483_최소_편집.cpp
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define MAX 1001

int d[MAX][MAX];

int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();

	for (int i = 0; i <= n; i++) {
		d[i][0] = i;
	}

	for (int j = 0; j <= m; j++) {
		d[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 0) d[i][j] = i;
			else if (i == 0) d[i][j] = j;
			else {
				if (a[i - 1] == b[j - 1]) { // 두 문자가 같을 때
					d[i][j] = d[i - 1][j - 1]; // 편집 거리 변화 X
				}
				else { // 두 문자가 다를 때
					d[i][j] = 1 + min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] }); // 제거, 치환, 삽입 연산 중 최소값에서 + 1
				}
			}
		}
	}

	cout << d[n][m]; // 행렬의 가장 마지막 값 = 최소 편집
}

