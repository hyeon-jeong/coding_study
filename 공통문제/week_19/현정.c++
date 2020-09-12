// 청소년 상어~
#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <cstdio>
using namespace std;

int N, M;
int added[501][501]; //더한 여부
int graph[501][501]; //인접 행렬
int tetro[501][501]; //(i,j) 에서의 최대값 저장.
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int result;

void bfs(int x, int y){
    queue< pair<int, int> > q;
    int temp = graph[x][y]; //temp 에 임의의 점 (x, y)값 저장
    added[x][y] = 1;

    q.push(make_pair(x, y)); //q에는 주변점들 다 들어갈 예정......
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        int moveCount=1;
        //상하좌우
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //printf("%d %d\n", nx, ny);

            //최대값 찾고, 4칸 이동하기.
            if(0<= nx && nx <N && 0<= ny && ny< M){
                if(added[nx][ny] == 0 && moveCount <=4){ // 더한적 없다면
                    added[nx][ny] = 1;
                    temp += graph[nx][ny];
                    moveCount += 1; //1칸 이동
                    q.push(make_pair(nx,ny));
                }
                //위치가 여기가 맞나...?
                if(temp > tetro[x][y]){
                    tetro[x][y] = temp; //tetro를 최대값으로 갱신
                    temp = 0;
                }
            }else{
                continue;
            }

            printf("tetro[x][y] : %d\n", tetro[x][y]);
            //printf("temp : %d\n", temp);
        }
        if(result < tetro[x][y]) result = tetro[x][y]; //tetro 값 중 가장 큰 값 구하기.
        printf("result : %d\n", result);
        printf("count : %d\n", moveCount);
    }
}

int main(){
    memset(added, 0, sizeof(added));
    memset(graph, 0, sizeof(graph));
    memset(tetro, 0, sizeof(tetro));
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
    */
    bfs(0,0);
    printf("%d\n", result);

    return 0;
}