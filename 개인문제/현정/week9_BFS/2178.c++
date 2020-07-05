#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <cstdio>

using namespace std;

string graph[101]; //인접행렬
int visit[101][101]; //방문여부
int dist[101][101];  //(i,j) 로의 누적거리
//상하좌우
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
//입력받을 변수
int n,m;

void bfs(int x, int y){
    queue< pair<int, int> > q; 
    visit[x][y] = 1;
    dist[x][y] = 1;
    
    //연결된 포인트 집어넣기
    q.push(make_pair(x, y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        //상하좌우 탐색
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx <n && 0<= ny && ny < m){
                if(graph[nx][ny]=='1' && visit[nx][ny]==0){
                    visit[nx][ny] = 1;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                else{
                    continue;
                }
            }else{
                continue;
            }
        }
    }
}

int main(){
    //memset(graph,0, sizeof(graph));
    memset(dist, 0, sizeof(dist));
    memset(visit, 0, sizeof(visit));

    scanf("%d %d", &n, &m);

    for(int i=0; i< n; i++){
        cin >> graph[i];
    }

    //원점부터 탐색~~
    bfs(0,0);

    printf("%d\n", dist[n][m]);

    return 0;
} 