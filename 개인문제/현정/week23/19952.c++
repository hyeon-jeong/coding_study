//인성 문제 있어??
// 해결못함 ㅠㅠ 조만간 다시 해볼 예정...

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int miro[101][101];
int visit[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int T,H,W,O,F, Xs, Xe, Ys, Ye;
bool flag;

//종점에 오면 멈춰야함.
void bfs(int x, int y){
    queue< pair <int, int> > q;
    visit[x][y] = 1;
    
    //연결 포인트 넣기
    q.push(make_pair(x,y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        //상하좌우 탐색
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //이동하는 좌표가 미로 범위 안이어야 함.
            if(0<= nx && nx <= W && 0<= ny && ny <= H){
                //도착점인지 일단 확인
                if(nx == Xe && ny == Ye && flag){
                    //cout << "도착! "<<endl;
                    //flag = true;
                    cout << "잘했어!!";
                    return;
                }
                //F가 0 이 아니고, 점프할 높이만큼의 힘이 남아있어야 함.
                int jump = miro[nx][ny] - miro[x][y];
                if(F>0 && !visit[nx][ny] && F>jump){
                    //cout << "남은 힘 : "<< F <<endl;
                    //cout << "점프 : " << jump << endl;
                    visit[nx][ny] = 1;
                    F --;
                    flag = true;
                    q.push(make_pair(nx, ny));
                }   
                else{
                    flag = false;
                    continue;
                }
            }else{
                continue;
            }
        }
    }
}

int main(){
    int X, Y, L;
    memset(miro, 0, sizeof(miro));
    memset(visit, 0, sizeof(visit));
    cin >> T;
    while(T--){
        cin >> H >> W >> O >> F >> Xs >> Xe >> Ys >> Ye;
        for(int i=0; i<O; i++){
            cin >> X >> Y >> L;
            miro[X][Y] = L;
        }
        bfs(Xs, Ys); // 시작점.
        if(!flag) cout << "인성 문제있어??"<<endl;

        /*
        for(int i=1; i<=H; i++){
            for(int j=1; j<=W; j++){
                cout << miro[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
}