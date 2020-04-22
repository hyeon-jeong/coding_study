// 1932_정수_삼각형.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int number_triangle(vector<vector<int>> triangle, int k) { // k는 triangle 행렬의 행 수 (= n + 1)
	int max_result = 0;
	vector<vector<int>> best(k, vector<int>(k, 0)); // 각 원소의 최적 경로값
	
	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= i; j++) {
			/* (i-1)번째 레벨에서의 j-1번째 원소, j번째 원소 중 더 큰 값을 선택 */
			best[i][j] = triangle[i][j] + max(best[i - 1][j - 1], best[i - 1][j]);
			if (i == k - 1) { // 마지막 행의 원소 중 제일 큰 값이 최적 경로 값
				max_result = max(max_result, best[i][j]);
			}
		}
	}

	return max_result;
}

int n; // 삼각형 크기

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 0)); // triangle의 0번째 행은 비워둘 것이므로 행렬 크기는 (n+1)*(n+1)
	for (int i = 1; i <= n; i++) { // 입력값 입력
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	cout << number_triangle(triangle, n + 1);
}

