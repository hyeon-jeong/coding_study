// 2098_외판원_순회.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define MAX 16

int U[MAX];
void initial(int n) {
	for (int i = 0; i < n; i++) {
		U[i] = i;
	}
}

int find(int x) {
	if (U[x] == x) return x;
	else return U[x] = find(U[x]);
}

bool equal(int p, int q) {
	if (p == q) return true;
	else return false;
}

void merge(int p, int q) {
	if (p < q) U[q] = p;
	else U[p] = q;
}

vector<pair<int, pair<int, int>>> mst(vector<pair<int, pair<int, int>>> X, int n) {
	vector<pair<int, pair<int, int>>> F;
	sort(X.begin(), X.end());

	initial(n);
	int e = n * n;
	for (int i = 0; i < e; i++) {
		int p, q, w;
		p = find(X[i].second.first);
		q = find(X[i].second.second);
		w = X[i].first;
		if (!equal(p, q)) {
			merge(p, q);
			F.push_back(make_pair(w, make_pair(p, q)));
		}
	}
	return F;
}

int n; // 도시 개수

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	vector<pair<int, pair<int, int>>> W;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int w;
			cin >> w;
			W.push_back(make_pair(w, make_pair(i, j)));
		}
	}
	W = mst(W, n);
	
	for (int i = 0; i < W.size(); i++) {
		cout << "(" << W[i].second.first << ", " << W[i].second.second << ")" << endl;
	}
}

