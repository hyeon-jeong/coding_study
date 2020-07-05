#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int graph[51][51];
bool visit[51][51];
int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};
int t, m, n, k;
int cnt;
int col, row;

void dfs(int i, int j){
    visit[i][j] = true; // 방문함!
    for(int p=0; p<4; p++){
        //다음 좌표값
        int nx = i + x[p];
        int ny = j + y[p];

        //방향 범위 확인
        if(0<= nx && nx < m && 0<= ny && ny < n){
            if(graph[nx][ny] && !visit[nx][ny]){
                visit[nx][ny] = true;
                dfs(nx,ny);
            }
        }
    } 
}

int main(){

    cin >> t;

    while(t--){
        
        cnt = 0;
        memset(graph, 0, sizeof(graph));
        memset(visit, false, sizeof(visit));

        cin >> m >> n >> k;

        for(int i=0; i<k; i++){
            cin >> row >> col;
            if(0 <= row && row < m && 0<= col && col < n){
                graph[row][col] = 1;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] && !visit[i][j]){
                    dfs(i, j);
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}