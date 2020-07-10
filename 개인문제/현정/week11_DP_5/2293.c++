#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,k;
    int coins[101];
    int dp[10001] = {1,}; //가치 : 100000 이하의 자연수를 가짐.

    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &coins[i]);
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k;j++){
            if(j >= coins[i]){ // 동전 하나의 가치가 어떤 동전 i의 가치 이상일때 -> 바꿀수있음
                dp[j] += dp[j-coins[i]]; //해당 가치가 될 때까지의 경우의 수를 합산            
           }
        }
    }
    printf("%d", dp[k]);

    return 0;

}