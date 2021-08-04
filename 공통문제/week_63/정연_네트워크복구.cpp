#include <iostream>
#include <vector>
#include <queue>
#define INF 31313131

using namespace std;

vector<pair<int,int>> network[1001];
int dist[1001];
int repair[1001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist[now] < cost)
            continue; //이미 최단 경로를 확인한 노드인 경우 continue
        
        for(int i=0; i<network[now].size(); i++){
            int nextCost = cost + network[now][i].second;
            int nextVertex = network[now][i].first;
            
            if(nextCost < dist[nextVertex]){//비용이 더 작다면
                dist[nextVertex] = nextCost;
                pq.push(make_pair(-dist[nextVertex], nextVertex));
                
                repair[nextVertex] = now;
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        network[a].push_back(make_pair(b,c));
        network[b].push_back(make_pair(a,c));
    }
    
    fill(dist, dist+1001, INF);
    fill(repair, repair+1001, 0);
    
    dijkstra(1);
    
    cout<<n-1<<endl;
    
    for(int i=2; i<=n; i++){
        if(repair[i])
            cout<<repair[i]<<" "<<i<<endl;
    }
    
    return 0;
}
