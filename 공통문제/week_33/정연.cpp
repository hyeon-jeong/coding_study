#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cstdio>
using namespace std;

int n,k,r;
set<pair<int,int>> road[101][101];
vector<pair<int,int>> cow;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visited[101][101] = {false,};

void dfs(int x, int y){
    visited[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(x<1 || y<1 || x>n || y>n)
            continue;
        if(visited[nx][ny] || road[nx][ny].count({nx,ny}))
            continue;
        dfs(nx,ny);
    }
}

int main(){
    int ans=0;
    scanf("%d %d %d", &n, &k, &r);
    
    for(int i=0; i<r; i++){
        int r1,c1,r2,c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        road[r1][c1].insert({r2,c2});
        road[r2][c2].insert({r1,c1});
    }
    
    for(int i=0; i<k; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        cow.push_back({x,y});
    }
    
    for(int i=0; i<cow.size(); i++){
        visited[101][101] = {false,};
        dfs(cow[i].first, cow[i].second);
        for(int j=i+1; j<cow.size(); j++){
            if(!visited[cow[i].first][cow[i].second])
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
