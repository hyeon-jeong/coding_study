#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool visited[5][5];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k=0; k<5; k++){ // 5개 대기실
        queue<pair<int,int>> q; // 대기실마다 배치가 다르므로 k마다 초기화
        int distancing = 1;
        for(int i=0; i<5; i++){ // 대기실 당 5x5
            for(int j=0; j<5; j++){
                visited[i][j] = false;
                if(places[k][i][j] == 'P')
                    q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            
            int manhattan = 0;
            for(int i=0; i<4; i++){
                int nextx = curx + dx[i];
                int nexty = cury + dy[i];
                
                if(nextx>0 && nextx<5 && nexty>0 && nexty<5){
                    if(visited[nextx][nexty] == false)
                        visited[nextx][nexty] = true;
                    
                    if(places[k][nextx][nexty] == 'X'){
                        manhattan+2;
                        continue;
                    }
                    
                    else if(places[k][nextx][nexty] == 'O'){
                        manhattan++;
                    }

                    else if (places[k][nextx][nexty] == 'P'
                            && manhattan <= 2)
                        distancing = 0;
                }
            }
        }
        answer.push_back(distancing);
    }
    return answer;
}
