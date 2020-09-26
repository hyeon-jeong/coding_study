#include <iostream>
using namespace std;

int main(){
    int n;
    int t[17] = {0,};
    int p[17] = {0,};
    int dp[17] = {0,};
    int profit = 0;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>t[i]>>p[i];
    
    for (int i=1; i<=n; i++){
        if (i + t[i] <= n+1){
            dp[i + t[i]] = max(dp[i + t[i]], p[i] + dp[i]);
            profit = max(profit, dp[i + t[i]]);
        }
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    cout << profit << endl;
    return 0;   
}
