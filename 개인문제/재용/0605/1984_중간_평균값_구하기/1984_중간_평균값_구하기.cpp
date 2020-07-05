// 1984_중간_평균값_구하기.cpp 
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

// 형변환때문에 반올림이 잘 안됐음... 형변환 주의
double calculate(vector<int> v) {
	double sum = 0; // 원소 합
	double count = 0; // 원소 개수
	for (vector<int>::iterator i = v.begin() + 1; i != v.end() - 1; i++) {
		sum += *i;
		count++;
	}
	double average = sum / count;
	return average;
}

int main()
{
	int T; // test case
	cin >> T;
	for (int i = 1; i <= T; i++) {
		vector<int> v;
		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end()); // 오름차순 정렬
		double avg = calculate(v);
		avg = floor(avg + 0.5);

		cout << "#" << i << " " << avg << endl;
	}

	return 0;
}

