#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int n,p,k;
vector<pair<int,int>> intrnt[1001];
int dist[1001];

bool dijkstra(int mid){
    priority_queue<pair<int,int>> pq;
    pq.push({1,0});
    for(int i=1; i<=n; i++)
        dist[i] = INF;
    
    dist[1] = 0;
    
    while(!pq.empty()){
        int com = pq.top().first;
        int charge = pq.top().second;
        pq.pop();
        
        if(dist[com] < charge) continue;
        for(int i=0; i<intrnt[com].size(); i++){
            int nextcom = intrnt[com][i].first;
            int nextchrg = charge + (intrnt[com][i].second > mid);
            
            if(dist[nextcom] > nextchrg){
                dist[nextcom] = nextchrg;
                pq.push({nextcom,nextchrg});
            }
        }
    }
	return dist[n] <= k;
}

int main(){
    int low=0, mid;
    int ans = -1, high;
    cin>>n>>p>>k;
    
    for(int i=0; i<p; i++){
        int c1, c2, price;
        cin>>c1>>c2>>price;
        intrnt[c1].push_back({c2,price});
        intrnt[c2].push_back({c1,price});
        high = max(high,price);
    }
 
    while(low <= high){
        mid = (low + high) / 2;
        
        if(dijkstra(mid)){
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;       
    }   
    cout << ans;
    return 0;
}
