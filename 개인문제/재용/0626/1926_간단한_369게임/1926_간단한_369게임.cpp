// 1926_간단한_369게임.cpp
#include <iostream>
using namespace std;

int count_369(int n) { // 숫자 n에 3, 6, 9가 나오는 횟수 count
	int count = 0;
	while (true) {
		int x = n % 10;
		if (x == 3 || x == 6 || x == 9) count++;
		n = n / 10;
		if (n == 0) break;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int count = count_369(i);
		if (count == 0) {
			printf("%d ", i);
		}
		else {
			for (int j = 0; j < count; j++) {
				printf("-");
			}
			printf(" ");
		}
	}
	
}
