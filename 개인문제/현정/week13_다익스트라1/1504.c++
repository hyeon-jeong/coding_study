#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
#include <math.h>
#define INF 1000000

using namespace std;

int N, E, a, b, c, v1, v2;
//bool flag = true;
vector < pair<int, int> > node[801];
priority_queue < pair<int, int> > pq;

int djikstra(int s, int e){
    int dist[801];
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    pq.push(make_pair(0, s)); // 시작점 S, 거리값 0

    while(!pq.empty()){
        int now = pq.top().second;
        int now_dist = -pq.top().first;
        pq.pop();
        
        if(dist[now] < now_dist) continue;

        for(int i=0; i<node[now].size(); i++){
            int new_dist = now_dist + node[now][i].second;
            if(dist[node[now][i].first] > new_dist){
                dist[node[now][i].first] = new_dist;
                pq.push(make_pair(-dist[node[now][i].first], node[now][i].first));
            }
        }
    }
    //if(dist[e] == INF) flag = false;
    //cout << "dist[e]" << dist[e] << endl;

    return dist[e];
}

int main(){
    cin >> N >> E;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;

    int V1toV2, V2toV1;

    //1_v1_v2_N
    int _V1 = djikstra(1, v1);
    int V1_V2 = djikstra(v1, v2);
    int V2_N = djikstra(v2, N);
    V1toV2 = _V1 + V1_V2 + V2_N;

    //1_v2_v1_N
    int _V2 = djikstra(1, v2);
    int V2_V1 = djikstra(v2,v1);
    int V1_N = djikstra(v1, N);
    V2toV1 = _V2 + V2_V1 + V1_N;

    int result = min(V1toV2, V2toV1);
    if(result >= INF || result <0){
        cout << -1 << "\n";
    }
    else{
        cout << result << "\n";
    }

    return 0;
}