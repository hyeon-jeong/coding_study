//3차원 토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H, cnt=0;
int tomato[101][101][101];
int day[101][101][101]; //날짜 누적, 방문안했을때는 -1 넣어줌.
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
// 가로, 세로, 높이, 날짜 
queue<pair<pair<int, int>,int > > q;

void bfs(){
    //큐에서 꺼내기
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        //6개 방향 탐색~~
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx >=0 && ny >= 0 && nz >= 0 && nx <M && ny < N && nz < H){
                //토마토가 익지 않았을 때
                if(tomato[nz][ny][nx] == 0 && day[nz][ny][nx] == -1){
                    day[nz][ny][nx] = day[z][y][x] + 1; //기존의 (x,y,z) 까지 걸리는 날 + 1
                    q.push(make_pair(make_pair(nx, ny), nz));
                }
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //input
    cin >> M >> N >> H;
    for(int h=0; h<H; h++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                cin >> tomato[h][y][x];
                day[h][y][x] = -1;
                //익은상태의 토마토는 큐에 넣어주기 (BFS)
                if(tomato[h][y][x] == 1){
                    q.push(make_pair(make_pair(x, y), h));
                    day[h][y][x] = 0; // 방문했다는 표시?
                }
            }
        }
    }

    //탐색
    bfs();

    //안익은 토마토 있는지 전체 탐색~
    for(int h=0; h<H; h++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                //안익은 토마토 & 방문 안함
                if(tomato[h][y][x]==0 && day[h][y][x]==-1){
                    cnt = -1; //다 익히는거 불가능!
                    break;
                }
                if(cnt < day[h][y][x]) cnt = day[h][y][x];
            }
            if(cnt == -1) break; //break로 탈출한 cnt 잡기
        }
        if(cnt == -1) break;
    }

    /*날짜 출력
    for(int z=0; z<H; z++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                if(cnt < day[z][y][x]) cnt = day[z][y][x];
            }
        }
    }
    */

    printf("%d\n", cnt);
    return 0;
}