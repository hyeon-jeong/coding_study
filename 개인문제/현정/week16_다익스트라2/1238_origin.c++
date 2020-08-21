// 다익스트라 - 파티
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define INF 1000000

using namespace std;
int N, M, X, s, e, t;
vector < pair <int, int> > vilage[1001];
priority_queue < pair <int, int> > pq;

vector<int>  djikstra(int a){
    vector<int> times(N+1, INF);
    times[a] = 0;
    pq.push(make_pair(0, a));
    while(!pq.empty()){
        int vil = pq.top().second;
        int time = -pq.top().first;
        pq.pop();

        if(times[vil] < time) continue;

        for(int i=0; i<vilage[vil].size(); i++){
            int new_time = time + vilage[vil][i].second;
            if(times[vilage[vil][i].first] > new_time){
                times[vilage[vil][i].first] = new_time;
                pq.push(make_pair(-times[vilage[vil][i].first], vilage[vil][i].first));
            }
        }
    }
    return times;
}

int main(){
    cin >> N >> M >> X ;
    for(int i=0; i<M; i++){
        cin >> s >> e >> t;
        vilage[s].push_back(make_pair(e,t));
    }
    int max_time = 0;
    vector<int> come = djikstra(X);
    for(int i=1; i<=N; i++){
        vector<int> go = djikstra(i);
        //cout << "go[X] : " << go[X] <<" come[i]: "<<come[i]<<"\n";
        if(max_time < go[X]+come[i]) max_time = go[X]+come[i];
    }
    cout << max_time ;
    return 0;
}