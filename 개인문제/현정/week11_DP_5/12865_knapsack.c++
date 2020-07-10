#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int dp[101][100001]; // 총 무게
int w[101]; // 무게
int v[101]; // 가치

int main(){

    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }

    for(int i=1; i<=n; i++){
        //물건의 무게보다 작을때 index -> dp 배열 채우기.
        //여기 없으면 틀렸다고 나옴. 솔직히 이해안됨.
        for(int temp=0; temp<w[i]; temp++){
            dp[i][temp] = dp[i-1][temp];
        }
        //w[i] <= k 일때
        for(int j=w[i]; j<=k; j++){ //k 이하의 무게를 가지는 물건들을 배낭에 담는다.
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]); //가치가 최대인것으로 dp 배열에 저장
        }
    }


    printf("%d\n", dp[n][k]);

}