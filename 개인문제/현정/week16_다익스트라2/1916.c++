//다익스트라 - 우선순위 큐
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <math.h>
#define INF 1000000 // 오버플로우 주의

using namespace std;
int n, m, a, b, c, s, e;
vector < pair<int, long long> > node[1001]; //마치 연결리스트 같군~~
priority_queue < pair<int, long long> > pq;

void djikstra(int start, int end){
    int dist[1001];
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        int now = pq.top().second; // front()는..?
        int cost = -pq.top().first;
        //cout << "now and cost " << now << " " << cost;
        pq.pop();

        if(dist[now] < cost) continue;
        for(int i=0; i<node[now].size(); i++){
            int val = cost + node[now][i].second;
            //cout << "val " << val;
            if(dist[node[now][i].first] > val){
                dist[node[now][i].first] = val;
                pq.push(make_pair(-dist[node[now][i].first], node[now][i].first));
            }
        }
    }
    cout << dist[e];
}

int main(){
    cin >> n >> m ;
    for(int i=0; i<m; i++){
        scanf("%d %d %d\n", &a, &b, &c);
        node[a].push_back(make_pair(b, c));
    }
    scanf("%d %d", &s, &e);
    //cout << s << " "<< e << " ";
    djikstra(s, e);
    return 0;
}