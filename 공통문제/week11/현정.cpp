#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <cstdio>

using namespace std;

string input[301]; //지뢰 map
//int visit[301][301]; // 방문확인용
int popping[301][301]; //지뢰 count 저장용
//vector <int> bomb;
int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
int click;
int t,n; // 입력받을 변수

void dfs(int x, int y){
    click ++; // 이게 맞을까..?
    //visit[x][y] = 1; 이거 딱히 필요없을듯. 중복 count 되어야 하니까
    int count=0;
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<= nx && nx < n && 0 <= ny && ny < n){
            //주변 지뢰 탐색 후 count
            if(input[nx][ny]=='*' && input[x][y]=='.'){
                count++; // popping[x][y] 를 바로 ++ 할까...?
                //continue;
            }
            if(input[nx][ny]=='.' && popping[x][y]==0){
                //printf("%c", input[x][y]);
                dfs(nx,ny);
            }
        }
    }
    popping[x][y] = count;

}

int main(void){

    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d", &n);
        memset(popping, 0, sizeof(popping));
        //int min=n*n;
        for(int j=0; j<n; j++){
            cin >> input[j];
        }

        cout << "???"<<'\n';
        for(int l=0; l<n; l++){
            for(int m=0; m<n; m++){
                if(input[l][m]=='.'){
                    dfs(l,m);
                }
                /*
                if(click < min){
                    min = click;
                }
                */
               //cout << click << '\n';
            }
        }
    
        cout << "\n" << "result" << "\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d ", popping[i][j]);
            }
            cout << "\n";
        }
        
        printf("\n");
        printf("#%d %d\n", i, click);
        printf("\n");
    }


}

