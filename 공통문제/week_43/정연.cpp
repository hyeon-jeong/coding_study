#include<cstdio>
#include<queue>
using namespace std;

int map[101][101];
int road[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> q;

int main(int argc, char** argv){
	int test_case;
	int T, N;
	scanf("%d\n", &T);
    
	for(test_case = 1; test_case <= T; ++test_case){
        scanf("%d\n", &N);
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                scanf("%1d", &map[i][j]);
                road[i][j] = 31313131;
            }
        }
           
        road[0][0] = 0;
        q.push(make_pair(0,0));
        
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >=0 && x < N && ny >=0 && y < N){
                    int distance = map[nx][ny] + road[x][y]; // 현재까지의 복구 시간 + 새로 이동할 위치의 복구 시간
                    if (distance < road[nx][ny]){ // 방문되지 않은 경우 road[nx][ny] == 31313131이므로, if 조건이 성립
                        q.push(make_pair(nx, ny));
                        road[nx][ny] = distance; // (nx, ny)를 방문하여, 해당 위치까지의 복구 시간의 합을 저장
                    }
                }
            }
        }
        printf("#%d %d\n", test_case, road[N-1][N-1]);
	}
	return 0;
}
