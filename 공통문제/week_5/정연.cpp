#include<iostream>

using namespace std;
int price[1000000];

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
    long long profit = 0;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        for (int i = 0; i < N; i++){
            cin>>price[i];
        }
        
        int max = price[N-1];
        for (int j = N-2; j >= 0; j--){
            if (max < price[j])
                max = price[j];
            else
                profit += max - price[j];
         }
         cout<<"#"<<test_case<<" "<<profit<<endl;
         profit = 0; // 다른 코드를 보면 이 부분을 굳이 다시 0으로 초기화하지 않아도 정상적으로 답이 출력되는데, 왜 내 코드에서는 오답이 되는지 잘 모르겠다
    }
    return 0;
}
