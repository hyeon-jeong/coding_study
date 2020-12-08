#include<iostream>
#include<cmath>

using namespace std;

bool goldbach(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)
      return false;
	}
	return true;
}

int main() {
	int n = 1;
	int a, b;
	bool flag = false;
	
	while (n) {
		cin >> n;
		for (int i = 1; i < n / 2; i++) {
			a = 2 * i + 1;
			b = n - a;
			if (goldbach(a) && goldbach(b)) {
				cout << n << " = " << a << " + " << b << "\n";
				flag = true;
				break;
			}
		}
		if (!flag) 
      cout << "Goldbach's conjecture is wrong\n";
	}
}
