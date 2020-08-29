//공통문제 - 아기상어
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
int N;
int fishes[21][21];
int dist[21][21];
int visited[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int result=0;
priority_queue <pair<int, pair<int, int> > > pq;

void bfs(int a, int b){//아기상어 좌표 
    int size =2;
    int cnt=0; //아기상어 크기 레벨업
    memset(dist, 0, sizeof(dist));
    int time=987654321;
    //bfs 구성요소
    priority_queue <pair <int, int> > q;
    q.push(make_pair(a,b));
    while(!q.empty()){
        int x = q.top().first;
        int y = q.top().second;
        q.pop();
        //상하좌우 탐색
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx >= N || ny <0 || ny >= N) continue;
            //아기상어보다 같거나 작으면 탐색 가능
            if(dist[nx][ny] == 0 && fishes[nx][ny]<=size){
                dist[nx][ny] = dist[x][y] + 1;
                //먹을 수 있는 물고기
                if(fishes[nx][ny] < size && fishes[nx][ny] > 0){
                    cnt += 1; 
                    if(size == cnt){
                        size += 1; // 아기상어 레벨업
                        cnt = 0;
                    }
                    //모든 조건을 만족하는 nx, ny 를 PQ 에 집어넣는다.
                    if(time >= dist[nx][ny]){
                        time = dist[nx][ny];
                        pq.push(make_pair(time, make_pair(nx, ny))); //근데 덜 들어간 느낌이다..
                    }
                }
                q.push(make_pair(nx, ny));                       
            }
        }
    }
    cout << time;
}

int main(){
    memset(fishes, 0, sizeof(fishes));
    cin >> N;
    int x,y;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> fishes[i][j];
            if(fishes[i][j] == 9){
                x = i; y = j;
            }
        }
    }
    /*
    while(true){
        pq = priority_queue <pair<int, pair<int, int> > >(); // reset it
        bfs(x,y);
        if(pq.empty()) break;
    }
      */  
    //bfs 한 번 돌고나서, dist 초기화 해줘야 할 것 같은데, 어디서 해야할까..?
    bfs(x,y);
    //확인용
    while(!pq.empty()){
        int time = pq.top().first;
        int nx = pq.top().second.first;
        int ny = pq.top().second.second;
        cout << "time : "<<time<<" nx : "<<nx<<" ny: "<< ny<<endl;
        pq.pop();
    }
    
    //cout << result << endl;
    return 0;
}