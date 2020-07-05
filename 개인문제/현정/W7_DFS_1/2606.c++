#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int graph[101][101];
int visited[101];
int n, cnt;

void dfs(int v){
    visited[v] = 1;
    for(int i=1; i<=n ; i++){
        //아직 방문안했고 연결된 노드를 찾아서,,,,
        if(!visited[i] && graph[v][i] == 1){
            cnt ++;
            dfs(i);
        }
    }
}

int main(){
    int edge;
    int u, v;
    cin >> n;
    cin >> edge;

    for (int i=0; i<edge ; i++){
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    dfs(1); // 1번 컴퓨터부터 감염시작!
    
    cout << cnt << endl;
    
    return 0;
}