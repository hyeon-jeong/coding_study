#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    double p, q, s1, s2;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> p >> q;
        s1 = (1-p) * q;
        s2 = p * (1-q) * q;
        
        if (s1 < s2) 
			cout << "#" << test_case << " YES" << endl;
		else 
			cout << "#" << test_case << " NO" << endl;
	}
	return 0;
}
