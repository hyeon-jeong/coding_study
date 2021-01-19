// 16234_인구이동.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);

		int lcm = (m * n) / gcd(m, n);
		int answer;
		while (1) {
			if (x > lcm) {
				answer = -1;
				break;
			}
			if ((x - 1) % n + 1 == y) {
				/* y가 0이 되지 않도록 고려 */
				answer = x;
				break;
			}
			x += m;
		}

		printf("%d\n", answer);
	}
}
