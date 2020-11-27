// 13458_시험감독.cpp
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

int n;
vector<long long> A;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long a;
		scanf("%lld", &a);
		A.push_back(a);
	}
	long long b, c;
	scanf("%lld %lld", &b, &c);

	long long total = 0;
	for (int i = 0; i < n; i++) {
		total += 1; // 총감독관
		long long rest = 0; 
		if (A[i] >= b) { // 나머지 응시생 수가 있는 경우
			rest = (long long)ceil((double)(A[i] - b) / (double)c);
		}
		total += rest;
	}

	printf("%lld\n", total);

	return 0;
}
