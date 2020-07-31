#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
 
int M,N,K;
int cnt;
int paper[100][100];
int visited[100][100];
 
int dfs(int y,int x){    
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++){
         int nY = y + dy[i].y;
         int nX = x + dx[i].x;
             if (0 <= nY && nY < M && 0 <= nX && nX < N)
                 if (paper[nY][nX] == 0 && !visited[nY][nX])
                     DFS(nY, nX);
    }
    return cnt;
}
 
int main(){
    
    cin>>M>>N>>K;
    
    int x1,y1,x2,y2;
    for(int i=0;i<K;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        for(int x=x1;x<x2;x++)
            for(int y=y1;y<y2;y++)
                arr[y][x]++;
        
    }
    
    vector<int> result;
    for(int y=0; y<M; y++)
         for(int x=0; x<N; x++)
             if (paper[y][x] == 0 && !visited[y][x]){
                                 cnt = 0; 
                                 DFS(y, x);
                                 result.push_back(cnt);
                         }

         cout << result.size() << endl;


        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++)
                 cout << result[i] << " ";
        cout << endl;
        return 0;
}
