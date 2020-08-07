// Kickstart_2019_Round_H_Elevanagram
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> // next_permutation
#include <utility>

vector<int> digit;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) { // Test Case
		int sum = 0;
		for (int i = 1; i <= 9; i++) { // 숫자 입력받음
			int num;
			scanf("%d", &num);
			while (num > 0) {
				digit.push_back(i); // 벡터에 넣음
				num--;
			}
		}

		sort(digit.begin(), digit.end());
		bool eleven = false; // 11의 배수이면 true
		bool minus_flag = false; // true일 때 sum에서 빼줌
		do {
			int sum = 0;
			// 순열이 바뀌어도 벡터 내 인덱스는 변하지 않기 때문에 인덱스로 접근하면 안됨..
			// iterator로 접근
			for (auto it = digit.begin(); it != digit.end(); ++it) {
				if (!minus_flag) {
					sum += *it;
					minus_flag = true;
				}
				else if (minus_flag) {
					sum -= *it;
					minus_flag = false;
				}
			}
			if (sum % 11 == 0) {
				eleven = true;
				break;
			}
			else eleven = false;
		} while (next_permutation(digit.begin(), digit.end())); // 순열의 모든 경우의 수에 대해 시도

		if (eleven) printf("Case #%d: YES\n", i);
		else printf("Case #%d: NO\n", i);
		digit.clear();
	}
}
