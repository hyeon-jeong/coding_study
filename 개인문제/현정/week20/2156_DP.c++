//포도주시식
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[10001];
int cup[10001];
int N;

int max(int a, int b, int c){
    return a>b? (a>c)? a:c : (b>c)? b:c ;
}

int main(){
    memset(dp, 0, sizeof(dp));
    memset(cup, 0, sizeof(cup));
    cin >> N;
    for(int i=1; i<=N; i++){
        scanf("%d", &cup[i]);
    }
    dp[1] = cup[1];
    if(N > 1){
        dp[2] = dp[1] + cup[2];
    }
    if(N > 2){
        for(int i=3; i<=N; i++){
            dp[i] = max(dp[i-1], cup[i]+cup[i-1]+dp[i-3], cup[i]+dp[i-2]);
        }
    }
    printf("%d", dp[N]);
}