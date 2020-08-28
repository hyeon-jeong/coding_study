#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int M,N,K;
int lettuce[50][50];
bool visited[50][50];

void dfs(int y, int x){
     visited[y][x] = true;
    
     for (int i=0; i<4; i++){
         int nx = x + dx[i];
         int ny = y + dy[i];
         
         if (0<=ny && ny<N && 0<=nx && nx<M)
             if (lettuce[ny][nx])
                 dfs(ny, nx);
     }
}

int main(){
    int T;
    cin>>T;
    
    for (int i=0; i<T; i++){
        memset(visited,false,sizeof(visited));
        memset(lettuce,0,sizeof(visited));
        cin>>M>>N>>K;
        
        for (int j=0; j<K; j++){
            int x,y;
            cin>>x>>y;
            lettuce[y][x] = 1;
        }
        
        int ans = 0;
        for (int n=0; n<N; n++){
            for (int m=0; m<M; m++){
                if (lettuce[n][m] == 1 && !visited[n][m]){
                    dfs(n,m);
                    ans++;
                }
                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
