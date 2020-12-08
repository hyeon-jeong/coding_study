//촌수계산 - BFS
#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;
int dist[MAX] = {0,}; //촌수를 저장하는 배열(= 거리계산)
vector <int> graph[MAX]; // 인접행렬 저장. 인덱스 i 에는 i와 연결된 노드들<int>이 저장됨.

int BFS(int a, int b);

int main(){
    ios::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y, a, b;
    cin >> n >> a >> b >> m; //전체 사람수, 사람1, 사람2
    //인접행렬 만들기
    for(int i=0; i<m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //BFS 탐색
    cout << BFS(a, b) << "\n"; //결과 출력
    return 0;
}

int BFS(int a, int b){
    queue<int> q;
    q.push(a);//탐색할 큐에 a 집어넣음
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        //큐가 최종적으로 비워져도 됨.
        if(b == temp) return dist[b];//목표 도착 -> 촌수 출력
        //temp 로 주변 탐색중.. (촌수 더하는중)
        int size = graph[temp].size();

        //헷갈리니까... y 는 temp 를 기준으로 센 거리값!! (=촌수)
        cout << "temp " << temp << "dist[temp] " << dist[temp] << "\n";
        for(int i=0; i<size; i++){
            int y = graph[temp][i];
            cout << "y : "<<y <<"\n";
            //촌수값 있을때 큐에 넣음 - 삼촌관계 처럼 윗 세대의 부모 같을때
            if(!dist[y]){
                q.push(y);//또 탐색..?
                dist[y] = dist[temp] + 1;
            }
        }
    }
    //촌수가 없을때
    return -1;
}