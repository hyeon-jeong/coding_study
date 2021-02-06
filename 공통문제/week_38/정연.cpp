#include <bits/stdc++.h>
using namespace std;

int min_cost[201][201];
const int inf = 0x1f1f1f1f;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = inf;
    memset(min_cost, inf, sizeof(min_cost));
    
    for (int i=1; i<=n; i++)
        min_cost[i][i] = 0;
    
    for (int i=0; i<fares.size(); i++){
        int u = fares[i][0], v = fares[i][1], cost = fares[i][2];
        min_cost[u][v] = min_cost[v][u] = cost;
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++)
                min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (min_cost[s][i] == inf || min_cost[i][a] == inf || min_cost[i][b] == inf)        
            continue;
        answer = min(answer, min_cost[s][i] + min_cost[i][a] + min_cost[i][b]);
    }
    
    return answer;
}
