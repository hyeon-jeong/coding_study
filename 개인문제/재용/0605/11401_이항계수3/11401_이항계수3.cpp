// 11401_이항계수3.cpp
#include <iostream>
using namespace std;
#include <stack>

typedef long long ll;
ll M = 1000000007LL;

// x^c (mod n) 계산
// 제곱-곱 연산 방법 이용
ll square_and_multiply(ll x, ll c, ll n) { 
	ll ans = 1;
	stack<ll> bin; 
	while (c > 0) { // c를 이진수로 변환한 값을 스택에 저장
		ll b = c % 2;
		bin.push(b);
		c = c / 2;
	}
	while (!bin.empty()) {
		ans *= ans;
		ans %= n;
		if (bin.top() != 0) { //c[i]가 1이면 x를 한번 더 곱해서 mod 계산
			ans = (ans * x) % n;
		}
		bin.pop();
	}
	return ans;
}

ll binomial_coefficient(ll n, ll k) { // 이항계수 계산 함수
	ll a = 1; // A (== n! mod M)
	ll b = 1; // B (== k!(n-k)! mod M) 
	ll ans = 1;

	for (ll i = 1; i <= n; i++) { // n! mod M 계산
		a *= i;
		a = a % M;
	}
	for (ll i = 1; i <= k; i++) { // k! mod M 계산
		b *= i;
		b = b % M;
	}
	for (ll i = 1; i <= (n - k); i++) { // k!(n-k)! mod M 계산
		b *= i;
		b = b % M;
	}

	ll b2 = square_and_multiply(b, M - 2, M); // B^(M - 2) mod M 계산
	ans = (a * b2) % M;

	return ans;
}


int main()
{
	ll n, k;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cout << binomial_coefficient(n, k) << endl;
	
	return 0;
}