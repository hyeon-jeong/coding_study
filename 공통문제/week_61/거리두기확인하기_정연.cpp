#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x, int y, vector<string> map, bool visited[5][5]){
    queue<pair<pair<int,int>,int>> q;
    int distancing = 1;
    q.push(make_pair(make_pair(x,y),0));
    visited[x][y] = true;
    
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int manhattan = q.front().second;
        q.pop();
            
        for(int i=0; i<4; i++){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
             
            if(nextx>=0 && nextx<5 && nexty>=0 && nexty<5){
                if(visited[nextx][nexty] == false){
                    if(map[nextx][nexty] == 'X'){
                        visited[nextx][nexty] = true;
                        continue;
                    }
                    
                    else if(map[nextx][nexty] == 'O'){
                        visited[nextx][nexty] = true;
                        q.push(make_pair(make_pair(nextx,nexty), manhattan+1));
                    }

                    else if (manhattan <=2 && map[nextx][nexty] == 'P'){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int res = 1;
    for(int k=0; k<5; k++){ // 5개 대기실
        bool visited[5][5];
        for(int i=0; i<5; i++){ // 대기실 당 5x5
            for(int j=0; j<5; j++){
                if(places[k][i][j] == 'P'){
                    res = bfs(i,j, places[k], visited);
                }
            }
        }
        answer.push_back(res);
    }
    return answer;
}
