// 수도 요금 경쟁

#include<iostream>

using namespace std;

int main(void)
{
  int T, P, Q, R, S, W;
	cin>>T;
	
	for(int test_case = 1; test_case <= T; test_case++)
	{
        int A, B;
        cin >> P >> Q >> R >> S >> W;
        
        A = W * P;
        
        if (W <= R)
            B = Q;
        else
            B = Q + (W - R) * S;
        
        cout << "#" << test_case << " " << (A<B ? A : B) << "\n";
    }
	return 0;
}
