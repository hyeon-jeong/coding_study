#include <iostream>
#include <math.h>
#include <algorithm>
#define MAX 101
using namespace std;

int n,k;
int dp[MAX][100001]; 
int w[MAX];
int v[MAX]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=w[i]; j++)
            dp[i][j] = dp[i-1][j]
        for (int j=w[i]; j<=k; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}
