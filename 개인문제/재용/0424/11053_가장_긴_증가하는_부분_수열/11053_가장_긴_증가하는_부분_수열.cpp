// 11053_가장_긴_증가하는_부분_수열.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n; // 수열 A의 크기

void longest_increasing_subseq(vector<int> s, int size) {
	int i, j;
	vector<int> h(size, 0); // 원소 A[i]로 끝나는 최장 증가 부분 수열의 길이. 0으로 초기화
	vector<int> p(size, 0); // 전 값의 인덱스
	int max = 0;
	int index;

	for (i = 1; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (s[i] > s[j] && h[i] < h[j] + 1) {
				h[i] = h[j] + 1; // 현재 원소의 최장 증가 부분 수열 길이 저장
				p[i] = j; // 전 원소의 인덱스 저장
			}
		}
	}
	for (i = 1; i < size; i++) { // 최장 부분 수열의 길이 
		if (max < h[i]) {
			max = h[i];
			index = i; // 최장 부분 수열의 마지막 원소 인덱스 저장
		}
	}

	vector<int> lis; // 최장 부분 수열을 저장할 벡터
	for(i = max; i > 0; --i) {
		lis.push_back(s[index]);
		index = p[index];
	}

	sort(lis.begin(), lis.end()); // 최장 부분 수열이 내림차순으로 정렬되어 있으므로, 오름차순으로 바꿔줌

	cout << "\nLongest increasing sebseq: ";
	for (int k = 0; k < lis.size(); k++) cout << lis[k] << " ";
	cout << "\nlength: " << max << endl;
}


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> A(n + 1); // A[0]에는 가장 작은 값(-1)이 저장되어야 하므로 총 벡터 크기는 (n + 1)이 되어야 함

	for (int i = 0; i <= n; i++) {
		if (i == 0) A[i] = -1;
		else cin >> A[i];
	}
	longest_increasing_subseq(A, n + 1);
}
