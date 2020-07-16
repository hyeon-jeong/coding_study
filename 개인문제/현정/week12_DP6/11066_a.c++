//dp
//파일 합치기 sol-A

#include <cstdio>
#include <iostream>
#include <string.h>
#include <limits.h> // 이런것도 있음...!
#include <algorithm>

using namespace std;

int main(){
    int t, k;
    int dp[501][501];
    int cost[501];
    int sum[501];

    scanf("%d", &t);
    while(t--){
        memset(dp, 0, sizeof(dp));
        memset(cost,0,sizeof(cost));

        scanf("%d", &k);
        //비용 입력하기, 누적합 저장
        for(int i=1; i<=k; i++){
            cin >> cost[i];
            sum[i] = sum[i-1]+cost[i];
        }
        //부분합 구하기 -> 전체 최소비용 구하기 (bottom-up)
        for(int temp=1; temp<k; temp++){
            // i+j 인덱스 범위는 k 이내
            for(int left=1; left+temp<=k; left++){
                int right = left + temp;
                //이거 꼭 있어야 할까..?! -> 최대한 큰 수로 일단 잡아놔야 min 계산할 수 있음.
                dp[left][right] = 987654321;
                for(int mid=left; mid<right; mid++){
                    dp[left][right] = min(dp[left][right], dp[left][mid]+dp[mid+1][right]+sum[right]-sum[left-1]);
                }
            }
        }
        //1부터 k 까지 탐색.
        cout << dp[1][k] << "\n";

        /*
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                cout << dp[i][j] << " ";
            }
            printf("\n");
        }
        */
    }

    return 0;
}