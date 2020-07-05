#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//그래프를 위해 필요한 변수
string graph[25];
int visit[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector <int> houses;
//입력받고 계산할때 쓰는 변수
int n, cnt;

void dfs(int x, int y){
    cnt ++;
    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<= nx && nx < n && 0<= ny && ny < n){
            if(graph[nx][ny] == '1' && visit[nx][ny]==0){
                dfs(nx,ny);
            }
        }
    }
}

int main(void){
    cin >> n;

    for(int i=0; i<n ; i++){
        cin >> graph[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j] == '1' && visit[i][j]==0){
                cnt = 0;
                dfs(i,j);
                houses.push_back(cnt);
            }
        }
    }

    sort(houses.begin(), houses.end());

    cout << houses.size() << endl;
    for(int i=0; i<houses.size(); i++){
        cout << houses[i] << endl;
    }

    return 0;
    
}