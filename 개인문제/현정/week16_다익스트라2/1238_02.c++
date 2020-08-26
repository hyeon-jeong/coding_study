// 다익스트라 - 파티
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define INF 10000000

using namespace std;
int N, M, X, s, e, t;
vector < pair <int, int> > vilage_1[1001];
vector < pair <int, int> > vilage_2[1001];
int times[1001];
priority_queue < pair <int, int> > pq;

int djikstra(int a, int b, vector < pair <int, int> > vilage){
    times[a] = 0;
    pq.push(make_pair(0, a));
    while(!pq.empty()){
        int vil = pq.top().second;
        int time = -pq.top().first;
        pq.pop();
        if(times[vil] > time) continue;
        for(int i=0; i<vilage[vil].size(); i++){
            int new_time = time + vilage[vil][i].second;
            if(times[vilage[vil][i].first] > new_time){
                times[vilage[vil][i].first] = new_time;
                pq.push(make_pair(-times[vilage[vil][i].first], vilage[vil][i].first));
            }
        }
    }
    return times[b];
}

int main(){
    memset(times, INF, sizeof(times));
    cin >> N >> M >> X ;
    for(int i=0; i<M; i++){
        cin >> s >> e >> t;
        vilage_1[s].push_back(make_pair(e,t));
        vilage_2[e].push_back(make_pair(s,t));
    }
    int max_time = 0;
    int go = djikstra(i, X, vilage_1);
    int come = djikstra(X, i, vilage_2);
    if(max_time < go+come) max_time = go+come;

    return 0;
}