#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int arr[1001] = {};
    int dp1[1001] = {};
    int dp2[1001] = {};
    int result;

    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }

    //증가수열
    for(int i=1; i<=n; i++){
        dp1[i] = 1;
        for(int j=1; j<=i; j++){
            if(arr[i]>arr[j]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }
    //감소수열
    for(int i=n ; i>=1 ; i--){
        dp2[i]=1;
        for(int j=n; j>=i ; j--){
            //if(arr[i]<arr[j]){ 이거 아님...
            if(arr[i]>arr[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }
    result = dp1[0]+dp2[0]-1;
    for(int i=1; i<=n; i++){
        int sum = dp1[i] + dp2[i]-1;
        //k 를 하나씩 증가시켜보면서 증가,감소수열에서의 수열길이의 합이 최대일때의 k를 찾는다.
        if(result < sum){
            result = sum;
        }
    }

   printf("%d", result);
    return 0;

}