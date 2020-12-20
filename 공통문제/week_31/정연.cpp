 #include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 101
#define INF 987654321
using namespace std;

int r,c,n;
char cave[MAX][MAX];
bool visited[MAX][MAX] = {false,};
bool loc_cluster[MAX][MAX] = {false,};
vector<pair<int,int>> cluster_ota;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
//int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int dfs(int x, int y){
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx > r || ny > c) continue;
		if (!visited[nx][ny] && cave[nx][ny] == 'x') {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
    }
}

void breakMineral(int stick, int direction){
    int height = r-stick+1;
    if (true){
        for (int i=1; i<=c; i++){
            if (cave[height][i] == 'x'){
                cave[height][i] = '.';
                printf("(%d %d)\n", height, i);
                break;
            }
        }
    }
    
    else{
        for (int i=c; i>=1; i--){
            if (cave[height][i] == 'x'){
                cave[height][i] = '.';
                printf("(%d %d)\n", height, i);
                break;
            }
        }
    }
}

bool findOTACluster(){
    bool isOTA = false;
    
    //동굴 바닥부터 dfs로 공중에 떠있지 않은 클러스터를 먼저 찾는다.
    memset(visited, false, sizeof(visited));
    for (int j=1; j<=c; j++){
        if (cave[r][j] == 'x' && !visited[r-1][j]){
            visited[r][j] = true;
            dfs(r,j);
        }
    }
    
    // 찾은 클러스터 visited를 바탕으로, visited == false 이면서 cave == 'x'인 경우를 찾는다.
    cluster_ota.clear();
    memset(loc_cluster,false, sizeof(loc_cluster));
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            if (cave[i][j] == 'x' && !visited[i][j]){
                loc_cluster[i][j] = true;
                cluster_ota.push_back({i,j});
                printf("%d %d\n", i, j);
                isOTA = true;
            }
        }
    }
    return isOTA;
}

int movecalc(int x, int y){ // 내려가는 칸 수 계산
    int drop_h = 0;
    for (int i=x+1; i<=r; i++){ 
            if (cave[i][y] == 'x'){ 
                if (loc_cluster[i][y]) return INF; 
                else return drop_h; 
            }
            else if (cave[i][y] == '.') drop_h++; 
    }
    return drop_h;
}

void moveCluster(){
    int drop_h = INF-1;
    for (int i=0; i<cluster_ota.size(); i++){ // 공중에 떠 있는 클러스터를 몇 칸 내릴지 결정해야 한다.
        int x = cluster_ota[i].first;
        int y = cluster_ota[i].second;
        
        int tmp = movecalc(x,y);
        if (tmp == INF) continue;
        else drop_h = min(drop_h, tmp);
    }
    
    sort(cluster_ota.begin(), cluster_ota.end());
    for (int i=cluster_ota.size() - 1; i>=0; i--){
        int x = cluster_ota[i].first;
        int y = cluster_ota[i].second;
        
        cave[x][y] = '.';
		cave[x + drop_h][y] = 'x';
    }
}

int main(){
    scanf("%d %d", &r, &c);
    
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++)
            scanf(" %c", &cave[i][j]);
    }
    
    scanf("%d", &n);
    bool direction = true;
    for (int i=0; i<n; i++){
        int stick;
        scanf("%d", &stick);
        breakMineral(stick, direction);
        direction = !direction;
        
        if (findOTACluster()) moveCluster();
        else continue;
    }
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			printf("%c", cave[i][j]);
		}
		printf("\n");
	}
}
