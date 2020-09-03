#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int R,C;
char board[20][20];
bool visited[26];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int y, int x, int visit){
    visited[visit-'A'] = true;
    int ans = 0;
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (0<=ny && ny<R && 0<=nx && nx<C){
            int alpha = board[ny][nx];  //다음으로 방문할 지점의 알파벳 (ASCII)
            if (!visited[alpha-'A']){
                visited[alpha-'A'] = true;
                ans = max(ans,dfs(ny,nx,alpha));
                visited[alpha-'A'] = false;  //false로 바꿔주지 않으면 다음 탐색 (다른 루트로 탐색) 할 때도 계속 해당 알파벳이 이미 방문한 것으로 인식되기 때문에 오류가 나게 된다.
            }
        }
    }
    return ans+1;
}

int main(){
    cin>>R>>C;
    for (int i=0; i<R; i++){
        string s;
        cin>>s;
        for (int j=0; j<s.length(); j++)
            board[i][j] = s[j];
    }
    
    cout<<dfs(0,0,board[0][0])<<'\n';  //x,y 좌표와 함께 board에서 출발점의 알파벳을 인자로 줘야 함  
    return 0;
}
