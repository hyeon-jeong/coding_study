//배낭문제

#include <iostream>
#include <algorithm>

using namespace std;

int weight[101]={0,};
int value[101]={0,};
int dp[101][100001];

int main(){
    int n, k, w, v;
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j]; // 담지 않은 경우
            //담은 경우
            if(j >= weight[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }

    }
    
    cout << dp[n][k] << "\n";

}