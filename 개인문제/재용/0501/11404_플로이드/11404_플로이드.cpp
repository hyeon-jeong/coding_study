// 11404_플로이드.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define MAX 100 + 1
#define INF 999999999

int m, n;
int d[MAX][MAX];

int main()
{
	cin >> n >> m;
	int a, b, c;

	for (int i = 1; i <= n; i++) { // 행렬 내 모든 원소를 무한대로 채움
		for (int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; i++) { // 입력받은 버스 노선 채우기
		cin >> a >> b >> c;
		if (d[a][b] > c) {
			d[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++) { // 플로이드
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] != INF && d[k][j] != INF) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || d[i][j] == INF) {
				d[i][j] = 0;
			}
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}


