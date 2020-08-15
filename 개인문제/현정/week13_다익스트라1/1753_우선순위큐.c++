#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
#define INF 1000000

using namespace std;

int V, E, K, u, v, w;
vector < pair<int, int> > node[20001]; //노드 입력받는 벡터
int dist[20001]; // 각 노드 i 로부터의 거리 dist[i], 이 값이 계속 갱신됨..?!
//bool visited[20001]; //꼭 필요한가..? 싶지만 일단 방문확인용
priority_queue < pair<int, int> > pq; // 노드 하나씩 집어넣고 정렬 후 pop!

void dijkstra(){
    dist[K] = 0;
    pq.push(make_pair(0,K)); // start, weight

    while(!pq.empty()){
        int now = pq.top().second; // 현재 노드
        int val = -pq.top().first; // 현재 노드의 distance
        //cout << now << " " << val << "\n";
        pq.pop();
        //최소 경로 구하기. 갱신 및 push
        for(int i=0; i<node[now].size(); i++){
            int new_val = val + node[now][i].second;
            //if(dist[node[now][i].first] > val + node[now][i].second){
            if(dist[node[now][i].first] > new_val){
                dist[node[now][i].first] = new_val;
                //cout << new_val << '\n';
                pq.push(make_pair(-dist[node[now][i].first], node[now][i].first));
            }
        }
    }
}


int main(){
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    //입력받는중,,,,
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
    }
    //dist 초기화
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }
    dijkstra();

    for(int i=1; i<=V; i++){
        if(dist[i] == INF) 
            cout << "INF\n";
        else 
            cout << dist[i] << "\n" ;
    }

    return 0;

}