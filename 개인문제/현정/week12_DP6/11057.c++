//오르막 수
//DP는 언제쯤 잘하게 될까~~~
#include <cstring> //memset때문에 꼭 적어야함. 백준에서 안돌아감.
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, sum;
    int dp[1001][10];

    //일단 0으로 셋팅
    memset(dp, 0, sizeof(dp));

    cin >> n;
    //한 자리 자릿수 : 모든 수가 하나의 오르막 수를 가짐
    for(int i=0; i<10; i++){
        dp[1][i] = 1;
    }
    //바로 직전 자릿수에서, 현재 인덱스(k) ~ 맨 끝 인덱스(9)까지의 합을 저장
    for(int i=2; i<= n; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    //합
    sum = 0;
    //끝의 자리가 0부터 9까지.
    for(int i=0; i<10; i++){
        sum += dp[n][i];
    }
    
    printf("%d", sum%10007);


    return 0;
}