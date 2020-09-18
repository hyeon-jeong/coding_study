#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
int dp[17]={0,}; //i번째 날에 dp[i]만큼의 이익
int times[17]={0,};
int pay[17]={0,};

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> times[i] >> pay[i];
    }

    //뒤에서부터 탐색하면 하루 건너뛰는 경우나 다음날 바로 상담하는 경우 나눌 필요가 없을듯..?!
    for(int i=N; i>=1 ; i--){
        if(i+times[i] >N+1){ //기억해... 현재시점 기준이라는걸...
            dp[i] = dp[i+1];
            continue;
        }
        dp[i] = max(dp[i+times[i]]+pay[i], dp[i+1]);
    }

    cout << dp[1]<<endl;

    return 0;
}