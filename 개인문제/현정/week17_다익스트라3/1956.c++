// 다익스트라 - 플로이드 와샬
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;
int v, e, a, b, c;
int graph[401][401];

void floyd(int n){
    for(int k=1; k<=n; k++){
        for(int s=1; s<=n ; s++){
            for(int e=1; e<=n; e++){
                if(graph[s][k]!=INF && graph[k][e]!=INF){
                    graph[s][e] = min(graph[s][e], graph[s][k]+graph[k][e]);
                }
            }
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i=0; i<=v; i++){
        for(int j=0; j<=v; j++){
            graph[i][j] = INF;
        }
    }
    for(int i=0; i<e; i++){
        cin >> a >> b >> c ;
        graph[a][b] = c;
    }

    floyd(v);

    int result = INF;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i==j){
                result = min(result, graph[i][j]);
                //cout << i << " "<< j << " "<< graph[i][j]<< "\n";
            }
        }
    }
    if(result == INF)
        cout << -1 << "\n";
    else
        cout << result << "\n";

    return 0;
}