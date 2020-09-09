// 11501_주식.cpp 
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#define MAX 1000001

typedef long long ll;

int tc; // test case
int n; // 날의 수
int cost[MAX] = { 0, }; // 주가

int main()
{
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &cost[i]);
		}

		int max_cost = cost[n]; // 최대 주식 가격
		ll max_benefit = 0; // 최대 이윤
		for (int i = n - 1; i > 0; i--) {
			if (max_cost < cost[i]) max_cost = cost[i];
			else if (max_cost > cost[i]) {
				max_benefit += (ll)(max_cost - cost[i]);
			}
			else continue; // 같은 경우 pass
		}

		printf("%lld\n", max_benefit);
	}
}

