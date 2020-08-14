#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n, m;
int map[501][501], dp[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
int dfs(int row, int col){
    if (dp[row][col] != -1) return dp[row][col];
    if (row < 0 || row >= n || col < 0 || col >= m) return 0;
    if (row == 0 && col == 0) return 1;
 
    dp[row][col] = 0;
    for (int i = 0; i < 4; i++){
        int nextX = row + dx[i], nextY = col + dy[i];
        if (map[nextX][nextY] > map[row][col])
            dp[row][col] += dfs(nextX, nextY);
    }
    return dp[row][col];
}
 
int main(){
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
 
    memset(dp, -1, sizeof(dp));
    printf("%d", dfs(n - 1, m - 1));
    return 0;
} 
