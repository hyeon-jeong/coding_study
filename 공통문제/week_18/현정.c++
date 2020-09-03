//공통문제 - 아기상어
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int N, cnt=0; int size=2;
int fishes[21][21];
int dist[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int result=0;
vector <pair<int, pair<int, int> > > pq; // 이거 우선순위 큐로 하고 싶었다...

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if(a.first == b.first){
        if(a.second.second == b.second.second){
            return a.second.first < b.second.first; //x좌표로 비교
        }else{
            return a.second.second < b.second.second; //y좌표로 비교
        }
    }else{
        return a.first < b.first;
    }
}

//bfs 한번 탐색..? 전체를 돌아다니는게 아닌듯.
void bfs(int a, int b){//아기상어 좌표 
    memset(dist, 0, sizeof(dist));
    int time=987654321;
    pq.clear(); //우선순위 큐로 하면 이게 초기화가 안됨.
    //bfs 구성요소
    queue <pair <int, int> > q; // 우선순위 큐일때랑 그냥 큐일때랑 다를까..?
    q.push(make_pair(a,b));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //상하좌우 탐색
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx >= N || ny <0 || ny >= N) continue;
            //아기상어보다 같거나 작으면 탐색 가능
            if(dist[nx][ny]==0 && fishes[nx][ny]<=size){
                dist[nx][ny] = dist[x][y] + 1;
                //먹을 수 있는 물고기
                if(fishes[nx][ny] < size && fishes[nx][ny] > 0){
                    //모든 조건을 만족하는 nx, ny 를 PQ 에 집어넣는다.
                    if(time >= dist[nx][ny]){
                        time = dist[nx][ny];
                        pq.push_back(make_pair(time, make_pair(nx, ny))); //근데 덜 들어간 느낌이다..
                    }
                }
                q.push(make_pair(nx, ny));                       
            }
        }
    }
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
    //아기상어가 이동중인것을 고려
    while(true){
        bfs(x,y);
        if(pq.empty()) break;
        else{
            //sort 함수 새로 짜기
            sort(pq.begin(), pq.end(), compare);
            cout << pq[0].first<< " ";
            result += pq[0].first;
            //아기상어 위치 이동
            int move_x = pq[0].second.first; int move_y = pq[0].second.second;
            cout << move_x << " "<<move_y<<endl;
            x = move_x; y = move_y; // 바꿔줘야지.... (이마짚)
            //물고기 먹음
            fishes[move_x][move_y] = 0;
            cnt += 1;
            if(cnt == size){
                size+=1; cnt = 0;
            }
            //cout << "size : "<<size<< "count "<<cnt<<endl;
        }
    }
    cout << result << endl;
    return 0;
}