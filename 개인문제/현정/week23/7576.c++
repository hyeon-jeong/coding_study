//week9 토마토 문제 재도전!!!

#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <cstdio>

using namespace std;

int box[1000][1000]; // 인접행렬
int visit[1000][1000]; // 방문여부
int dx[4] = {0,0,-1,1};
int dy[4] = {1, -1, 0, 0};
queue< pair<int, int> > q;

int n,m,day=0;

void bfs(void){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //상하좌우의 토마토 방문! - 범위 확인
            if(0<= nx && nx < m && 0<= ny && ny < n){
                //토마토가 익지 않았을 때
                if(box[nx][ny]==0 && visit[nx][ny]==0){
                    box[nx][ny] = box[x][y] + 1;
                    visit[nx][ny] = 1;
                    q.push(make_pair(nx,ny)); //익은걸로~~
                }
            }
        }
    }
}

int main(){
    memset(box,0, sizeof(box));
    memset(visit, 0, sizeof(visit));
    scanf("%d %d", &n, &m);

    for(int i=0; i< m; i++){
        for(int j=0; j<n ;j++){
            scanf("%d",&box[i][j]);
            if(box[i][j]==1) q.push(make_pair(i,j));
        }
    }
    //큐에 넣은 토마토부터 탐색~~ -> 원점부터 탐색하는것 보다, 이게 문제의 취지에 더 맞을듯!
    bfs();

    //전체 탐색 -> 안익은 토마토가 있는지 확인.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(box[i][j] == 0){
                //cout << "익을 수 없음 "<< endl;
                cout << "-1" <<endl; // 안익은게 아직도 있다면 -1 출력
                return 0;
            }
        }
    }

    //값 확인하기.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(day < box[i][j]) day = box[i][j];
        }
    }

    printf("%d", day-1); //누적한 날짜 -1. (왜? 처음 시작이 1이므로.)

    return 0;
}