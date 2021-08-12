// 1202_보석_도둑.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct jewel {
	int weight;
	int cost;
};

int N, K;
vector<int> bags;
vector<jewel> jewels;

// 보석 무게 오름차순 정렬
bool comp(jewel a, jewel b) {
	return a.weight < b.weight;
}

int main() {
	scanf("%d %d", &N, &K);

	// 각 보석의 무게, 가격
	for (int i = 0; i < N; i++) {
		int m, v;
		scanf("%d %d", &m, &v);
		jewels.push_back({ m, v });
	}

	// 보석 무게 오름차순 정렬
	sort(jewels.begin(), jewels.end(), comp);

	// 각 가방의 최대 무게
	for (int i = 0; i < K; i++) {
		int c;
		scanf("%d", &c);
		bags.push_back(c);
	}

	// 가방 정렬 (오름차순)
	sort(bags.begin(), bags.end());

	ll result = 0; // 최대 보석 가격
	priority_queue<int> pq; // 가방에 넣을 수 있는 보석
	int idx = 0; // 보석 인덱스
	for (auto bag : bags) { 
		// 가방에 넣을 수 있는 보석 모두 큐에 push
		while (idx < N && jewels[idx].weight <= bag) {
			pq.push(jewels[idx++].cost);
		}

		// 가방에 들어갈 수 있는 보석이 있으면
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	printf("%lld\n", result);
	return 0;
}
