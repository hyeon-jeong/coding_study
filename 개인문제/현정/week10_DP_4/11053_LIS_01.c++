#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    int arr[1001] = {};
    int dp[1001] = {};
    int maxlength = 1; //max 함수랑 겹치지 않기 위함.

    scanf("%d", &n);
    //memset(dp, 1, sizeof(dp));

    for(int i=1; i<=n ;i++){
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        //printf("%d ", dp[i]);
        maxlength = max(maxlength, dp[i]);
    }

    printf("%d\n", maxlength);

    return 0;
}