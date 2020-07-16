//재귀적 방법. 시간초과 발생!!ㅜㅜㅜ

#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int t, k;

int recursive(int x, int y){
    //특정한 값이 아닐때 리턴...
    //같은 값인 두 값
    if(x==y)
        return 0;
    //두 개가 다른 값일때(연속적인)
    if(x+1 == y)
        return dp[x][y] = cost[x]+cost[y];
    //3개 이상일떄
    int minn = INT32_MAX;
    for(int mid=x; mid<y; ++mid){
        int left = recursive(x,mid);
        int right = recursive(mid+1, y);
        minn = min(minn, left+right);
    }
    return dp[x][y] = minn + sum[y] - sum[x-1];
}

int main(){
    scanf("%d", &t);
    while(t--){
        memset(dp, 0, sizeof(dp));//int 배열이므로 4바이트 저장됨
        scanf("%d", &k);
        for(int i=1; i<=k; i++){
            scanf("%d", &cost[i]);
            sum[i] = sum[i-1]+cost[i];
        }
        recursive(1,k);
        printf("%d\n", dp[1][k]);
    }
    return 0;
}