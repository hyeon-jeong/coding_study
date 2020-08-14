// 9700_USB_꽃기의_미스터리.cpp
#include <iostream>
using namespace std;

int T;
double p, q;
double s1, s2;

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> p >> q;

		s1 = (1 - p) * q;
		s2 = p * (1 - q) * q;

		if (s1 < s2) {
			cout << "#" << i << " YES" << endl;
		}
		else {
			cout << "#" << i << " NO" << endl;
		}
	}
}
