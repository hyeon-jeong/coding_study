#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int arr[301] = {0,};
    int steps, point;
    int dp[301];

    cin >> steps;
    for(int i=1; i<=steps; i++){
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1]+arr[3], arr[2]+arr[3]);

    for(int i=4; i<=steps; i++){
        dp[i] = max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]);
    }

    cout << dp[steps] << "\n";

    return 0;
}