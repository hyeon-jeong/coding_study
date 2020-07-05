#include <iostream>
#include <string>
#include <queue>
#define MAX 1001 //정점개수 최대 1000

using namespace std;

int graph[MAX][MAX]; //정점-정점 인접행렬
int visited[MAX]; //정점개수
queue <int> q;

int n,m,v;

void dfs(int v){
    cout << v << " ";
    visited[v] = 1;
    for(int i=1; i<= n; i++){
        if(graph[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

void bfs(int v){
    visited[v] = 1;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();

        cout << v << " "; //pop 방문
        for(int i=1; i<=n; i++){
            // 정점i가 v-i 연결되어있고 아직 방문 안했다면
            if(graph[v][i] && !visited[i]){
                q.push(i);
                visited[i] = 1;
            } 
        }
    }
}

int main(void){
    cin >> n >> m >> v;
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;
        
        graph[b][a] = 1;
    }

    //첫번째 줄에 DFS 결과
    dfs(v);
    cout << "\n";

    memset(visited, 0, sizeof(visited));
    //두번째 줄에는 BFS 결과
    bfs(v);
    cout << "\n";

    return 0;
}