//다 못푼 문제.... 

#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <cstdio>

using namespace std;

int box[1000][1000]; // 인접행렬
int visit[1000][1000]; // 방문여부
int day[1000][1000]; // 시간경과(=거리)
int dx[4] = {0,0,-1,1};
int dy[4] = {1, -1, 0, 0};
queue< pair<int, int> > q;

int n,m;

void bfs(int x, int y){
    //printf("들어옴.\n");
    visit[x][y] = 1;
    //day[x][y] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //이미 익은 상태의 토마토들
            if(box[i][j] == 1 && visit[i][j] == 0){
                q.push(make_pair(i, j));
                visit[i][j] =1; //방문했다고 쳐야지
            }
        }
    }

    while(!q.empty()){
        //printf("empty 들어옴.");
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //상하좌우의 토마토 방문!
            if(0<= nx && nx < n && 0<= ny && ny < m){
                //토마토가 익지 않았을 때
                if(box[nx][ny]==0 && visit[nx][ny]==0){
                    day[nx][ny] = day[x][y] + 1;
                    q.push(make_pair(nx,ny));
                    box[nx][ny] = 1;
                    visit[nx][ny] = 1;
                }
                //토마토가 없을때
                else if( box[nx][ny] == -1 && visit[nx][ny] ==0){
                    day[nx][ny] = -1;
                    visit[nx][ny] = 1;
                }
                
            }
        }
    }
}

int main(){
    memset(box,0, sizeof(box));
    memset(visit, 0, sizeof(visit));
    memset(day, 0, sizeof(day));

    scanf("%d %d", &n, &m);

    for(int i=0; i< n; i++){
        for(int j=0; j<m ;j++){
            scanf("%d",&box[i][j]);
            //if(box[i][j]==1) q.push(make_pair(i,j));
        }
    }


    //원점부터 탐색~~
    bfs(0,0);

   printf("%d", day[n][m]);

    return 0;
}