// 9251_LCS.cpp 
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

string a, b;
int lcs[1001][1001] = { 0, };

int main()
{
	cin >> a;
	cin >> b;

	int lena = a.length();
	int lenb = b.length();

	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			if (a[i - 1] == b[j - 1]) { // 비교 문자가 같으면
				lcs[i][j] = lcs[i - 1][j - 1] + 1; // 1 증가
			}
			else { // 비교 문자가 다르면
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]); 
				/* 
					EX)
					LCS("ABC","AEB") = MAX(LCS("AB","AEB"), LCS("ABC", "AE")
				*/
			}
		}
	}

	int ans = lcs[lena][lenb];
	printf("%d\n", ans);

	return 0;
}
