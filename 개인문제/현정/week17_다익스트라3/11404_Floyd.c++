//다익스트라 - 플로이드 와샬
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;
int n, m, a, b, c;
int graph[101][101];

void floyd(int n){
    for(int k=1; k<=n; k++){
        for(int s=1; s<=n; s++){
            for(int e=1; e<=n; e++){
                if(graph[s][k]!=INF && graph[k][e]!=INF){
                    graph[s][e] = min(graph[s][e],graph[s][k]+graph[k][e]);
                }
            }
        }
    }
}

int main(){
    //시작도시와 도착도시가 같은 경우는 없다고 함. 근데 0으로 해야할지 INF로 해야할지...?
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            graph[i][j] = (i==j)? 0 : INF; // 문법은 알고 있었으나 실제로 처음 써봄!
        }
    }

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        if(graph[a][b] > c){
            graph[a][b] = c;
        }
    }

    floyd(n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j]==INF || graph[i][j]<0){
                printf("0 ");
            }
            else{
                printf("%d ", graph[i][j]);
            }
            
        }
        printf("\n");
    }

    return 0;

}