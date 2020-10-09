#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int tomato[1000][1000];
int visited[1000][1000];
int n,m;
int main(){
    cin>>m>>n;
    queue<pair<int,int>> q;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>tomato[i][j];
            visited[i][j] = -1;
            if (tomato[i][j] == 1){
                q.push(make_pair(i,j));
                visited[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m){
                if(tomato[nx][ny] == 0 && visited[nx][ny] == -1){
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ans = max(ans, visited[i][j]);
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(tomato[i][j] == 0 && visited[i][j] == -1)
                ans = -1;
        }
    }
    cout << ans;
}
