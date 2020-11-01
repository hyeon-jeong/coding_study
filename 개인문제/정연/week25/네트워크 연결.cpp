#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
 
int N, M, parent[1000], ans; 
vector<pair<int, pair<int, int>>> network; 
 
int find(int x) {
    if (x == parent[x])
        return x; 
    return parent[x] = find(parent[x]); 
}
 
bool union_(int x, int y) {
    x = find(x); 
    y = find(y); 
    if (x == y)
        return false; 
    parent[y] = x; 
    return true; 
}
 
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);   
    int v1, v2, w;
 
    cin >> N >> M; 
    for (int i = 0; i < N; i++)
        parent[i] = i; 
    
    for (int i=0; i < M; i++) {
        cin >> v1 >> v2 >> w; 
        network.push_back({ w, {v1, v2}}); 
    }
    sort(network.begin(), network.end());  // 가중치 w에 따라 정렬한다.
    
    for (int i = 0; i < network.size(); i++) {
        int w = network[i].first; 
        int v1 = network[i].second.first; 
        int v2 = network[i].second.second; 
        if (union_(v1, v2))  // 사이클 발생하지 않을경우 연결 후  
            ans += w;    // 연결비용 적재 
    }
    cout << ans; 
    return 0; 
}
