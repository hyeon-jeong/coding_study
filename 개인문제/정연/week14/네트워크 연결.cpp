#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
 
int n, m, parent[1001], ans; 
vector<pair<int, pair<int, int>>> edge; 
 
int find(int x) {
    if (x == parent[x])
        return x; 
    return parent[x] = find(parent[x]); 
}
 
bool union(int x, int y) {
    x = find(x); 
    y = find(y); 
    if (x == y)
        return false; 
    parent[y] = x; 
    return true; 
}
 
int main() {
    int v1, v2, w;
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);   
 
    cin >> n >> m; 
    for (int i = 1; i <= n; i++)
        parent[i] = i; 
    
    while (m--) {
        cin >> v1 >> v2 >> w; 
        edge.push_back({ w, {v1, v2}}); 
    }
    sort(edge.begin(), edge.end());  
    
    for (int i = 0; i < v.size(); i++) {
        int w = edge[i].first; 
        int v1 = edge[i].second.first; 
        int v2 = edge[i].second.second; 
        if (union(v1, v2))  
            ans += w;   
    }
    cout << ans; 
    return 0; 
}
